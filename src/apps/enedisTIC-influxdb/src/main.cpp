#include <chrono>
#include <iostream>
#include <sstream>

#include <QtGlobal>
#include <QDebug>
#include <QFile>

#include "CWrapperTicInflux.h"


static const char*  C_FILE_INPUT_PATH
//    = "data/samples/tic-historique-3phases-live_tempo_bleu_HP-singleFrame.hex";
    = "data/samples/tic-standard-1phase-live_singleFrame.dat";

static CWrapperTicInflux   s_ticToInflux("tic-test");

/* ########################################################################## */
/* ########################################################################## */

void    writeDatasets(const TIC::TDatasetsPtrList& pDatasetsPtrList);

/* ########################################################################## */
/* ########################################################################## */

void    test_writeToInfluxDB_v1(void)
{
    // Provide complete URI
    auto influxdb = influxdb::InfluxDBFactory::Get("http://localhost:8186?db=test");
    influxdb->write(
        influxdb::Point{"test"}
            .addField("value", 10)
            .addTag("host", "localhost")
    );
}

/* ########################################################################## */
/* ########################################################################## */

int     test_fromFile(
        const QString &pInputPath
    )
{
    QFile   lInputFile( pInputPath );

    int     retval  = EXIT_FAILURE;


    if( ! lInputFile.open(QFile::ReadOnly) )
    {
        QString lErrorMsg   = QString(
            "Can't open test file: %1"
        ).arg( pInputPath );
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
//            tic_appendData( lReadData.toStdString() );
            s_ticToInflux.appendRawData( lReadData.toStdString() );

        }

        lInputFile.close();
        retval  = EXIT_SUCCESS;
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

int main(int argc,char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    return test_fromFile( C_FILE_INPUT_PATH );


//    return 0;
}

/* ########################################################################## */
/* ########################################################################## */
