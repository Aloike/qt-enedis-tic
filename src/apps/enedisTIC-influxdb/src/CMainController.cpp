/* Corresponding header inclusion */
#include "CMainController.h"

/* System includes */

/* Libraries includes */
#include <QCoreApplication>
#include <QDebug>
#include <QFile>

/* Project includes */
#include "trace.h"


#ifdef  D_CMainController_READ_FROM_FILE
static const char*  C_FILE_INPUT_PATH
//    = "data/samples/tic-historique-3phases-live_tempo_bleu_HP-singleFrame.hex";
//    = "data/samples/tic-historique-3phases-live_tempo_bleu_HP.raw.hex";
    = "data/samples/tic-standard-1phase-live_HP.raw.hex";
//    = "data/samples/tic-standard-1phase-live_singleFrame.dat";
#endif

/* ########################################################################## */
/* ########################################################################## */

CMainController::CMainController(QObject *parent)
    :   QObject(parent)
    ,   m_settings()
{
    this->p_wrapperTicInflux
        = std::make_unique<CWrapperTicInflux>(
            this->m_settings.influxdbHost().toStdString(),
            this->m_settings.influxdbPort(),
            this->m_settings.influxdbDatabaseName().toStdString(),
            this->m_settings.influxdbMeasurementName().toStdString()
        );

#ifdef  D_CMainController_READ_FROM_FILE
    this->readFromFile();
#else
    this->_createConnections();

    this->serialPort_init();
#endif
}

/* ########################################################################## */
/* ########################################################################## */

void
    CMainController::_createConnections(void)
{
    QObject::connect(
        &this->m_serialPort,
        SIGNAL(readyRead()),
        this,
        SLOT(on_m_serialPort_readyRead())
    );
}

/* ########################################################################## */
/* ########################################################################## */
#ifdef  D_CMainController_READ_FROM_FILE
void    CMainController::readFromFile()
{
    QFile   lInputFile( C_FILE_INPUT_PATH );

    int     retval  = EXIT_FAILURE;


    if( ! lInputFile.open(QFile::ReadOnly) )
    {
        TRACE_WARN(
            "Can't open test file: %s",
            lInputFile.fileName().toStdString().c_str()
        );

        retval  = EXIT_FAILURE;
    }
    else
    {
        TRACE_DBG(
            "Opened file: '%s'",
            lInputFile.fileName().toStdString().c_str()
        );

        QByteArray lReadData;
        while( ! lInputFile.atEnd() )
        {
            TRACE_DBG("Reading data from file...");

            /* Limit the length of the data read to force using the buffer */
            lReadData   = lInputFile.read(1000);
            TRACE_DBG(
                "Read data:'%s'.",
                lReadData.toStdString().c_str()
            );

            /* Add read data to the buffer then process it */
            this->p_wrapperTicInflux->appendRawData(
                lReadData.toStdString()
            );
        }

        lInputFile.close();
        retval  = EXIT_SUCCESS;
    }
}
#endif  /*< defined D_CMainController_READ_FROM_FILE */

/* ########################################################################## */
/* ########################################################################## */

void
    CMainController::on_m_serialPort_readyRead()
{
    QByteArray lReadData;
    while( this->m_serialPort.canReadLine() )
    {
        TRACE_DBG( "Reading data from serial port..." );

        /* Limit the length of the data read to force using the buffer */
        lReadData   = this->m_serialPort.readLine( 256 );
        TRACE_DBG(
            "Read data:'%s'.",
            lReadData.toStdString().c_str()
        );

        /* Add read data to the buffer then process it */
        this->p_wrapperTicInflux->appendRawData(
            lReadData.toStdString()
        );
    }
}

/* ########################################################################## */
/* ########################################################################## */

bool
    CMainController::serialPort_init(void)
{
    bool    retval  = false;


    try
    {
        /* Set port configuration */
        this->m_serialPort.setPortName(
            this->m_settings.serialPortName()
        );

        this->m_serialPort.setDataBits(QSerialPort::Data7);
        this->m_serialPort.setParity(QSerialPort::EvenParity);
        this->m_serialPort.setFlowControl(QSerialPort::NoFlowControl);
        this->m_serialPort.setStopBits(QSerialPort::OneStop);

        QSerialPort::BaudRate lBaudRate = QSerialPort::Baud1200;
        auto lTicMode   = this->m_settings.ticMode();
        switch( lTicMode )
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
        this->m_serialPort.setBaudRate( lBaudRate );

        /* Open the serial interface */
        if( this->m_serialPort.open(QIODevice::ReadWrite) )
        {
            TRACE_DBG(
                "Connected to '%s'.",
                this->m_serialPort.portName().toStdString().c_str()
            );

            retval  = true;
        }
        else
        {
            throw std::runtime_error(
                std::string( "Unable to open '")
                + this->m_serialPort.portName().toStdString()
                + "': " + this->m_serialPort.errorString().toStdString()
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
