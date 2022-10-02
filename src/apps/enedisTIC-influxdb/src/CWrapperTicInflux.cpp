/* Corresponding header inclusion */
#include "CWrapperTicInflux.h"

/* System includes */

/* Libraries includes */
#include <qdebug.h>

/* Project includes */
#include <enedisTIC/datasets.h>
#include <enedisTIC/datasets/AbstractDataset.h>


/* ########################################################################## */
/* ########################################################################## */

CWrapperTicInflux::CWrapperTicInflux(
    const std::string& pInInfluxMeasurementName)
    :   m_influxMeasurementName( pInInfluxMeasurementName )
    ,   m_influxdb( influxdb::InfluxDBFactory::Get("http://localhost:8186?db=enedisTIC-test") )
{

}

/* ########################################################################## */
/* ########################################################################## */

void
    CWrapperTicInflux::appendRawData(const std::string &pInData)
{
    this->m_ticFrameBuffer.append( pInData );

    while( this->m_ticFrameBuffer.hasFrames() )
    {
        std::string lFrame  = this->m_ticFrameBuffer.popOne();

        qDebug(
            "Extracted frame with a length of %ld chars.",
            lFrame.length()
        );


        /* Try to decode the content of the received frame */
        try
        {
            TIC::TDatasetsPtrList  lDatasetsList
                = this->m_ticFrameProcessor.decode( lFrame );

//            this->m_datasetsCount   += lDatasetsList.size();

            this->frameToInfluxdbPoints( lDatasetsList );
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
/**
 *  @brief  Converts a datasets list to an InfluxDB points list.
 *  @note   Datasets shall come from the same frame as some of them will be used
 *          as tags or timestamps for all of the others.
 *
 *  @param  pDatasetsPtrList[in]    A reference to a datasets pointers list.
 */
void
    CWrapperTicInflux::frameToInfluxdbPoints(
        const TIC::TDatasetsPtrList& pDatasetsPtrList)
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

    influxdb::Point lPointBase{this->m_influxMeasurementName};
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
    this->m_influxdb->write(
        lPointDefault.addTag(std::string(), std::string())
    );


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

        this->m_influxdb->write(
            lPointTimestamped.addTag(std::string(), std::string())
        );
    }
}

/* ########################################################################## */
/* ########################################################################## */
