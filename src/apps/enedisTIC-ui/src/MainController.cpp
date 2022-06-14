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
#include <enedisTIC/FrameProcessor.h>

#include "ui/MainWindow.h"
#include "ui/TBSerialConfig.h"


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

static const QString    C_TESTDATA_FILE
//    = "../tests/data/samples/tic-standard-1phase-live_30s_raw.dat";
    = "../tests/data/samples/tic-standard-1phase-live_HC.raw.hex";
//    = "../tests/data/samples/tic-standard-1phase-live_HP.raw.hex";
//        "../tests/data/samples/tic-historical-3phase-1min.raw.dat"
//        "../tests/data/samples/tic-standard-singleFrame.dat"
//        "../tests/data/samples/tic-standard-1phase.raw.dat";

/* ########################################################################## */
/* ########################################################################## */

MainController::MainController(void)
    :   QObject()
    ,   m_datasetsCount( 0U )
    ,   m_framesCount( 0U )
    ,   m_inputBuffer()
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
        this->p_mainWindow->serialConfigTB(),
        SIGNAL(portsListAboutToShow()),
        this,
        SLOT(on_ui_portsList_aboutToShow())
    );

    QObject::connect(
        this->p_mainWindow->serialConfigTB(),
        SIGNAL(portOpenCloseTriggered(bool)),
        this,
        SLOT(on_ui_portOpenCloseTriggered(bool))
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

QByteArray
    MainController::extractFrameFromBuffer(void)
{
    const char  c_endOfFrame    = TIC::CHAR_ETX;
    const char  c_startOfFrame  = TIC::CHAR_STX;

    QByteArray  retval;


    TRACE_DBGLOW(
        "m_inputBuffer='%s'.",
        this->m_inputBuffer.toStdString().c_str()
    )


    /* begin loop */
    int     lIdxFirstFrameStart = -1;
    int     lIdxFrameEnd    = -1;
    int     lIdxFrameStart  = -1;
    bool    lFlagContinueProcess    = true;
    while( lFlagContinueProcess )
    {
        TRACE_DBG("New iteration of buffer processing.")

        if( this->m_inputBuffer.isEmpty() == true )
        {
            TRACE_DBG("Buffer is empty.")

            lFlagContinueProcess    = false;
            break;
        }


        /*
         *  Remove data preceding the first start of frame in the buffer.
         */
        lIdxFirstFrameStart = this->m_inputBuffer.indexOf(c_startOfFrame);
        if( lIdxFirstFrameStart == -1 )
        {
            TRACE_DBG(
                "No start of frame in buffer. Discarding %d chars.",
                this->m_inputBuffer.length()
            )

            this->m_inputBuffer.clear();

            lFlagContinueProcess    = false;
            break;
        }
        else if( lIdxFirstFrameStart != 0 )
        {
            TRACE_DBG(
                "First start of frame is after invalid data."
                " Discarding %d chars.",
                lIdxFirstFrameStart
            )

            this->m_inputBuffer.remove( 0, lIdxFirstFrameStart);

            lIdxFirstFrameStart = this->m_inputBuffer.indexOf(c_startOfFrame);
        }
        else
        {
            /* Nothing to do - Buffer is now expected to start with a SOF */
        }


        /* Look for the first end of frame */
        lIdxFrameEnd    = this->m_inputBuffer.indexOf(c_endOfFrame, 1);

        /* Look backwards for a start of frame from the end of frame.
         * If there's no end of frame, it will search from the end of the
         * buffer. */
        lIdxFrameStart  = this->m_inputBuffer.lastIndexOf(
            c_startOfFrame,
            lIdxFrameEnd -1
        );


        if( lIdxFrameEnd == -1)
        {
            TRACE_DBG(
                "No end of frame in buffer."
            )
            lFlagContinueProcess    = false;


            if( lIdxFrameStart != lIdxFirstFrameStart )
            {
                TRACE_WARN(
                    "Found multiple start of frame!"
                    " Discarding %d bytes before the last occurence: '%s'!",
                    lIdxFrameStart,
                    this->m_inputBuffer.left(lIdxFrameStart)
                        .toStdString().c_str()
                )

                this->m_inputBuffer.remove(0, lIdxFrameStart);
            }

            continue;
        }

        if( lIdxFrameStart == -1 )
        {
            throw std::logic_error(
                "Unexpected case: a start of frame should have been found!"
            );
        }
        else if( lIdxFrameStart != 0 )
        {
            /* The start of frame corresponding to the end of frame is not at
             * the beginning of the buffer - it means there's multiple
             * start of frame before the first end of frame. */
            TRACE_WARN(
                "Discarding %d bytes of an incomplete frame: '%s'!",
                lIdxFrameStart,
                this->m_inputBuffer.left(lIdxFrameStart).toStdString().c_str()
            )

            this->m_inputBuffer.remove(0, lIdxFrameStart);
            continue;
        }
        else
        {
            /* Extract the frame */
            retval  = this->m_inputBuffer.left(lIdxFrameEnd + 1);
            this->m_inputBuffer.remove( 0, lIdxFrameEnd + 1 );
            lFlagContinueProcess    = false;
            break;
        }

    }/* end loop */


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

void
MainController::initialize(void)
{
    /* Show the UI */
    this->p_mainWindow->show();

    this->p_mainWindow->serialConfigTB()->setPortOpened(false);
//    this->updateSerialPortsList();
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainController::inputClose()
{
    TRACE_DBG(
        "Closing '%s'.",
        this->p_serialPort->portName().toStdString().c_str()
    )

    this->p_serialPort->close();
    this->p_outputFile->close();
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
#ifdef  TEST_DATA_FROM_FILE
    Q_UNUSED(pInputPath)
    Q_UNUSED(pMode)

    QFile   lInputFile( C_TESTDATA_FILE );

    if( ! lInputFile.open(QFile::ReadOnly) )
    {
        throw std::runtime_error(
            "Can't open test file: " + lInputFile.errorString().toStdString()
        );
    }
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

        /*  Add read data to the buffer then process it */
        this->m_inputBuffer.append( lReadData );
        this->processInputBuffer();
    }

    lInputFile.close();
#else
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
    }
    else
    {
        TRACE_ERR(
            "Unable to open '%s': %s!",
            this->p_serialPort->portName().toStdString().c_str(),
            this->p_serialPort->errorString().toStdString().c_str()
        )
    }
#endif
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
        this->m_inputBuffer.append( lReadBuffer );
        this->processInputBuffer();
    }
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainController::on_ui_portOpenCloseTriggered(bool)
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
            this->p_mainWindow->serialConfigTB()->selectedPortName(),
            this->p_mainWindow->serialConfigTB()->selectedTICMode()
        );
    }

    this->p_mainWindow->centralWidget()->setEnabled(true);
    this->p_mainWindow->serialConfigTB()->setPortOpened(
        this->inputIsOpen()
    );
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainController::on_ui_portsList_aboutToShow()
{
    this->updateSerialPortsList();
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainController::processInputBuffer(void)
{
    QByteArray  lFrame;

    do
    {
        lFrame  = this->extractFrameFromBuffer();

        if( lFrame.isEmpty() )
        {
            TRACE_DBG("No frame to process.")
        }
        else
        {
            TRACE_DBG(
                "Extracted frame with a length of %d chars.",
                lFrame.length()
            )

            this->m_framesCount++;
            this->p_mainWindow->setFramesCount(this->m_framesCount);

            try
            {
                TIC::TDatasetsPtrList  lDatasetsList
                    = this->p_frameProcessor->decode( lFrame.toStdString() );

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

                this->p_mainWindow->statusBar()->showMessage(
                    e.what(),
                    10
                );
            }
        }
    }   while( ! lFrame.isEmpty() );
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


    this->p_mainWindow->serialConfigTB()->setPortsList(lPortsList);
}

/* ########################################################################## */
/* ########################################################################## */
