#include <chrono>
#include <iostream>
#include <sstream>

#include <QtGlobal>
#include <QDebug>
#include <QFile>

#include <InfluxDBFactory.h>

#include <enedisTIC/FrameBuffer.h>
#include <enedisTIC/FrameProcessor.h>
#include <enedisTIC/datasets.h>

static TIC::FrameBuffer     s_ticFrameBuffer;
static TIC::FrameProcessor  s_ticFrameProcessor;

static auto s_influxdb = influxdb::InfluxDBFactory::Get("http://localhost:8186?db=test");

static const char*  C_MEASUREMENT_NAME  = "tic-test";

static const char*  C_FILE_INPUT_PATH
//    = "data/samples/tic-historique-3phases-live_tempo_bleu_HP-singleFrame.hex";
    = "data/samples/tic-standard-1phase-live_singleFrame.dat";

/* ########################################################################## */
/* ########################################################################## */

void    writeDatasets(const TIC::TDatasetsPtrList& pDatasetsPtrList);

/* ########################################################################## */
/* ########################################################################## */

//void    influxdb_write(influxdb::Point&& pPoint)
//{
//    // Provide complete URI
//    influxdb->write(
//        pPoint
//    );
//}

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

void    tic_appendData(const std::string& pDataStr)
{
    s_ticFrameBuffer.append(pDataStr);

    while( s_ticFrameBuffer.hasFrames() )
    {
        std::string lFrame  = s_ticFrameBuffer.popOne();

        qDebug(
            "Extracted frame with a length of %ld chars.",
            lFrame.length()
        );


        /* Try to decode the content of the received frame */
        try
        {
            TIC::TDatasetsPtrList  lDatasetsList
                = s_ticFrameProcessor.decode( lFrame );

//            this->m_datasetsCount   += lDatasetsList.size();
//            this->p_mainWindow->setDatasetsCount(this->m_datasetsCount);

            writeDatasets( lDatasetsList );
        }
        catch( const std::runtime_error& e )
        {
            qWarning(
                "A runtime error occured: %s",
                e.what()
            );
        }
    }
}

/* ########################################################################## */
/* ########################################################################## */

//std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<int, std::ratio_multiply<std::ratio<24>, std::chrono::hours::period>>>
//    tic_timestampStrToDate(const std::string &pDateStr)
//{
//    std::istringstream lIn( pDateStr );

//    std::chrono::time_point<
//        std::chrono::system_clock,
//        std::chrono::duration<
//            int,
//            std::ratio_multiply<
//                std::ratio<24>,
//                std::chrono::hours::period
//            >
//        >
//    >  dp;

//    // format: 2000-06-04
//    qWarning( "pDateStr == %s", pDateStr.c_str() );
////    lIn >> date::parse("%F", dp);

//    return dp;
//}

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
            tic_appendData( lReadData.toStdString() );
        }

        lInputFile.close();
        retval  = EXIT_SUCCESS;
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

void    writeDatasets(const TIC::TDatasetsPtrList& pDatasetsPtrList)
{
    std::vector<TIC::TDatasetPtr>   lTags;
    std::vector<TIC::TDatasetPtr>   lValues;
    std::vector<TIC::TDatasetPtr>   lValuesWithTimestamp;
    time_t                          lTimestampEpoch_s   = 0;


    for( const TIC::TDatasetPtr& lDatasetPtr : pDatasetsPtrList )
    {
        if(     lDatasetPtr->label() == TIC::Datasets::ADSC::LABEL
            ||  lDatasetPtr->label() == TIC::Datasets::PRM::LABEL
            ||  lDatasetPtr->label() == TIC::Datasets::VTIC::LABEL )
        {
            /* Constant datasets used as tags */
            lTags.push_back( lDatasetPtr );
        }
        else if( lDatasetPtr->label() == TIC::Datasets::DATE::LABEL )
        {
            /* Contains the current date & time*/
            lTimestampEpoch_s   = lDatasetPtr->timestampEpoch_s();
        }
        else if( lDatasetPtr->hasTimestamp() )
        {
            /* Datasets with specific timestamps */
            lValuesWithTimestamp.push_back( lDatasetPtr );
        }
        else
        {
            /* Other datasets */
            lValues.push_back( lDatasetPtr );
        }
    }

    /* ---------------------------------------------------------------------- */
    /* ---------------------------------------------------------------------- */

    influxdb::Point lPointBase{C_MEASUREMENT_NAME};
    for( const TIC::TDatasetPtr& lDatasetPtr : lTags )
    {
        lPointBase.addTag(
            lDatasetPtr->label(),
            lDatasetPtr->data()
        );
    }


    influxdb::Point lPointDefault   = lPointBase;
    for( const TIC::TDatasetPtr& lDatasetPtr : lValues )
    {
        switch( lDatasetPtr->dataType() )
        {
            case    TIC::Datasets::AbstractDataset::E_DATA_INTEGER:
            {
                int lValue  = std::stoi( lDatasetPtr->data() );
                lPointDefault.addField(
                    lDatasetPtr->label(),
                    lValue
                );
                break;
            }


            default:
                lPointDefault.addField(
                    lDatasetPtr->label(),
                    lDatasetPtr->data()
                );
                break;
        }
    }
    if( lTimestampEpoch_s != 0 )
    {
        lPointBase.setTimestamp(
            std::chrono::system_clock::from_time_t(
                lTimestampEpoch_s
            )
        );
    }
    s_influxdb->write( lPointDefault.addTag(std::string(), std::string()) );


    for( const TIC::TDatasetPtr& lDatasetPtr : lValuesWithTimestamp )
    {
        influxdb::Point lPointTimestamped   = lPointBase;

        switch( lDatasetPtr->dataType() )
        {
            case    TIC::Datasets::AbstractDataset::E_DATA_INTEGER:
            {
                int lValue  = std::stoi( lDatasetPtr->data() );
                lPointTimestamped.addField(
                    lDatasetPtr->label(),
                    lValue
                );
                break;
            }


            default:
                lPointTimestamped.addField(
                    lDatasetPtr->label(),
                    lDatasetPtr->data()
                );
                break;
        }

        lPointTimestamped.setTimestamp(
            std::chrono::system_clock::from_time_t(
                lDatasetPtr->timestampEpoch_s()
            )
        );

        s_influxdb->write(
            lPointTimestamped.addTag(std::string(), std::string())
        );
    }
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
