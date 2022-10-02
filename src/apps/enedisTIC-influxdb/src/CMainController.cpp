/* Corresponding header inclusion */
#include "CMainController.h"

/* System includes */

/* Libraries includes */
#include <QCoreApplication>
#include <QDebug>
#include <QFile>

/* Project includes */


#ifdef  D_CMainController_READ_FROM_FILE
static const char*  C_FILE_INPUT_PATH
//    = "data/samples/tic-historique-3phases-live_tempo_bleu_HP-singleFrame.hex";
    = "data/samples/tic-standard-1phase-live_singleFrame.dat";
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
#endif
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
        QString lErrorMsg   = QString(
            "Can't open test file: %1"
        ).arg( lInputFile.fileName() );
        qWarning( "%s", lErrorMsg.toStdString().c_str() );

        retval  = EXIT_FAILURE;
    }
    else
    {
        qDebug(
            "Opened file: '%s'",
            lInputFile.fileName().toStdString().c_str()
        );

        QByteArray lReadData;
        while( ! lInputFile.atEnd() )
        {
            qDebug("Reading data from file...");

            /* Limit the length of the data read to force using the buffer */
            lReadData   = lInputFile.read(1000);
            qDebug(
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
