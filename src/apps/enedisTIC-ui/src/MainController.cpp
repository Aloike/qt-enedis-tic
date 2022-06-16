/* Corresponding header inclusion */
#include "MainController.h"

/* System includes */
#include <memory>

/* Libraries includes */
#include <QApplication>
#include <QDateTime>
#include <QFile>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QStatusBar>

/* Project includes */
#include <enedisTIC/FrameBuffer.h>
#include <enedisTIC/FrameProcessor.h>

#include "ui/MainWindow.h"
#include "ui/TBInputConfig.h"


/* ########################################################################## */
/* ########################################################################## */
/*
 *  Trace macros
 */
#include "core/trace.h"

#if defined  QT_DEBUG
#   if defined D_TRACE_ENABLE_DBGLOW
#       define  TRACE_DBGLOW(format,...)                                       \
                TRACE_DBG_BASE( format, ##__VA_ARGS__ );
#   else
#       define  TRACE_DBGLOW(format,...)
#   endif

#   define TRACE_DBG(format,...)                                               \
           TRACE_DBG_BASE( format, ##__VA_ARGS__ );
#else
#   define  TRACE_DBG(format,...)
#   define  TRACE_DBGLOW(format,...)
#endif

#define TRACE_INFO(format,...)                                                 \
        TRACE_INFO_BASE( format, ##__VA_ARGS__ );

#define TRACE_WARN(format,...)                                                 \
        TRACE_WARN_BASE( format, ##__VA_ARGS__ );

#define TRACE_ERR(format,...)                                                  \
        TRACE_ERR_BASE( format, ##__VA_ARGS__ );

/* ########################################################################## */
/* ########################################################################## */

MainController::MainController(void)
    :   QObject()
    ,   m_datasetsCount( 0U )
    ,   m_framesCount( 0U )
    ,   p_frameBuffer(std::make_unique<TIC::FrameBuffer>())
    ,   p_frameProcessor(std::make_unique<TIC::FrameProcessor>())
    ,   p_mainWindow(new MainWindow())
    ,   p_outputFile(new QFile(this))
    ,   p_serialPort(new QSerialPort(this))
{
    this->_createConnections();

    this->initialize();
}

/* ########################################################################## */
/* ########################################################################## */

MainController::~MainController()
{
//    delete this->p_mainWindow;
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainController::_createConnections(void)
{
    QObject::connect(
        this->p_mainWindow->inputConfigTB(),
        SIGNAL(inputsListAboutToShow()),
        this,
        SLOT(on_ui_inputsList_aboutToShow())
    );

    QObject::connect(
        this->p_mainWindow->inputConfigTB(),
        SIGNAL(inputOpenCloseTriggered(bool)),
        this,
        SLOT(on_ui_inputOpenCloseTriggered(bool))
    );

    QObject::connect(
        this->p_serialPort,
        SIGNAL(readyRead()),
        this,
        SLOT(on_p_serialPort_readyRead())
    );
}

/* ########################################################################## */
/* ########################################################################## */

bool
    MainController::_openInputFile(
        const QString &pInputPath
    )
{
    QFile   lInputFile( pInputPath );

    bool    retval  = false;


    if( ! lInputFile.open(QFile::ReadOnly) )
    {
        QString lErrorMsg   = tr(
            "Can't open test file: %1"
        ).arg( pInputPath );
        this->p_mainWindow->setStatus( lErrorMsg );

        retval  = false;
    }
    else
    {
        TRACE_DBG(
            "Opened file: '%s'",
            lInputFile.fileName().toStdString().c_str()
        )

        QByteArray lReadData;
        while( ! lInputFile.atEnd() )
        {
            TRACE_DBG("Reading data from file...")

            /* Limit the length of the data read to force using the buffer */
            lReadData   = lInputFile.read(1000);
            TRACE_DBGLOW(
                "Read data:'%s'.",
                lReadData.toStdString().c_str()
            )

            /* Add read data to the buffer then process it */
            this->p_frameBuffer->append( lReadData.toStdString() );
            this->processFrames();
        }

        lInputFile.close();
        retval  = true;
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

bool
    MainController::_openInputSerialPort(
        const QString &pInputPath,
        const TIC::TeTICMode &pMode
    )
{
    bool    retval  = false;


    try
    {
        /* Set port configuration */
        this->p_serialPort->setPortName(
            pInputPath
        );

        this->p_serialPort->setDataBits(QSerialPort::Data7);
        this->p_serialPort->setParity(QSerialPort::EvenParity);
        this->p_serialPort->setFlowControl(QSerialPort::NoFlowControl);
        this->p_serialPort->setStopBits(QSerialPort::OneStop);

        QSerialPort::BaudRate lBaudRate = QSerialPort::Baud1200;
        switch( pMode )
        {
            case    TIC::E_TIC_MODE_HISTORICAL:
                lBaudRate   = QSerialPort::Baud1200;
                break;

            case    TIC::E_TIC_MODE_STANDARD:
                lBaudRate   = QSerialPort::Baud9600;
                break;

            default:
                throw std::logic_error("Unknown TIC mode!");
        }
        this->p_serialPort->setBaudRate(lBaudRate);

        /* Open the serial interface */
        if( this->p_serialPort->open(QIODevice::ReadWrite) )
        {
            TRACE_DBG(
                "Connected to '%s'.",
                this->p_serialPort->portName().toStdString().c_str()
            )

            this->p_outputFile->setFileName(
                QApplication::applicationName()
                + "-receivedData-"
                + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss")
                + ".hex"
            );
            this->p_outputFile->open(QFile::WriteOnly);
            retval  = true;
        }
        else
        {
            throw std::runtime_error(
                std::string( "Unable to open '")
                + this->p_serialPort->portName().toStdString()
                + "': " + this->p_serialPort->errorString().toStdString()
                + "!"
            );
        }
    }
    catch( std::exception& myEx )
    {
        TRACE_ERR(
            "An exception occured while opening serial port: %s",
            myEx.what()
        );
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

void
MainController::initialize(void)
{
    /* Show the UI */
    this->p_mainWindow->show();

    this->p_mainWindow->inputConfigTB()->setInputOpened(false);
//    this->updateSerialPortsList();
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainController::inputClose()
{
    if( this->p_serialPort->isOpen() )
    {
        this->p_serialPort->close();

        this->p_mainWindow->setStatus(
            tr("Closed serial port \"%1\".")
            .arg( this->p_serialPort->portName() )
        );
    }

    /* Also close the output file if it is open */
    if( this->p_outputFile->isOpen() )
    {
        this->p_outputFile->close();
    }
}

/* ########################################################################## */
/* ########################################################################## */

bool
    MainController::inputIsOpen(void) const
{
    return this->p_serialPort->isOpen();
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Opens the input data source.
 *
 *  @param  pInputPath  The path to the input. Example: `/dev/ttyUSB0`.
 */
void
    MainController::inputOpen(
        const QString&          pInputPath,
        const TIC::TeTICMode&   pMode )
{
    if( this->_openInputSerialPort( pInputPath, pMode ) == true )
    {
        TRACE_INFO(
            "Opened '%s' as a serial port.",
            pInputPath.toStdString().c_str()
        );
        this->p_mainWindow->setStatus(
            tr("Opened serial port \"%1\".")
            .arg( pInputPath )
        );
    }
    else if( this->_openInputFile( pInputPath ) )
    {
        TRACE_INFO(
            "Opened '%s' as a regular file.",
            pInputPath.toStdString().c_str()
        );

        this->p_mainWindow->setStatus(
            tr("Read file \"%1\".")
            .arg( pInputPath )
        );
    }
    else
    {
        QString lErrorMsg   = tr(
            "Unable to open '%1'!"
        ).arg( pInputPath );

        TRACE_ERR( "%s", lErrorMsg.toStdString().c_str() );
        this->p_mainWindow->setStatus(
            lErrorMsg
        );
    }
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainController::on_p_serialPort_readyRead()
{
    QByteArray lReadBuffer;

    while( this->p_serialPort->canReadLine() )
    {
        lReadBuffer = this->p_serialPort->readAll();

        /* Write received data to the output file for future reference */
        this->p_outputFile->write(lReadBuffer);

        /* Append data to the buffer and try to extract frames */
        this->p_frameBuffer->append( lReadBuffer.toStdString() );
        this->processFrames();
    }
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainController::on_ui_inputOpenCloseTriggered(bool)
{
    TRACE_DBG("Button 'OpenClose' clicked.")

    this->p_mainWindow->centralWidget()->setEnabled(false);

    if( this->inputIsOpen() )
    {
        this->inputClose();
    }
    else
    {
        this->inputOpen(
            this->p_mainWindow->inputConfigTB()->selectedInputPath(),
            this->p_mainWindow->inputConfigTB()->selectedTICMode()
        );
    }

    this->p_mainWindow->centralWidget()->setEnabled(true);
    this->p_mainWindow->inputConfigTB()->setInputOpened(
        this->inputIsOpen()
    );
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainController::on_ui_inputsList_aboutToShow()
{
    this->updateSerialPortsList();
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainController::processFrames(void)
{
    std::string lFrame;

    while( this->p_frameBuffer->hasFrames() )
    {
        lFrame  = this->p_frameBuffer->popOne();

        TRACE_DBG(
            "Extracted frame with a length of %ld chars.",
            lFrame.length()
        )

        /* Update the frames count on the GUI */
        this->m_framesCount++;
        this->p_mainWindow->setFramesCount(this->m_framesCount);


        /* Try to decode the content of the received frame */
        try
        {
            TIC::TDatasetsPtrList  lDatasetsList
                = this->p_frameProcessor->decode( lFrame );

            this->m_datasetsCount   += lDatasetsList.size();
            this->p_mainWindow->setDatasetsCount(this->m_datasetsCount);

            this->p_mainWindow->updateData( lDatasetsList );
        }
        catch( const std::runtime_error& e )
        {
            TRACE_ERR(
                "A runtime error occured: %s",
                e.what()
            )

            this->p_mainWindow->setStatus(
                e.what()
            );
        }
    }
}

/* ########################################################################## */
/* ########################################################################## */

void
MainController::updateSerialPortsList(void)
{
    QStringList lPortsList;

    for(    QSerialPortInfo lPortInfo
        :   QSerialPortInfo::availablePorts() )
    {
        lPortsList.append( lPortInfo.systemLocation() );
        TRACE_DBG(
            "Adding port to list: '%s'",
            lPortInfo.systemLocation().toStdString().c_str()
        )
    }


    this->p_mainWindow->inputConfigTB()->setInputsList(lPortsList);
}

/* ########################################################################## */
/* ########################################################################## */
