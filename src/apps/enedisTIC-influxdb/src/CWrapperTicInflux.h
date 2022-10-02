#ifndef CWRAPPERTICINFLUX_H
#define CWRAPPERTICINFLUX_H

/* Inherited classes */

/* System includes */
#include <string>

/* Libraries includes */

/* Project includes */
#include <enedisTIC/FrameBuffer.h>
#include <enedisTIC/FrameProcessor.h>
#include <InfluxDBFactory.h>



/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  The CWrapperTicInflux class converts raw TIC data into Influx data
 *          points.
 */
class   CWrapperTicInflux
{
public:

    CWrapperTicInflux(const std::string& pInInfluxMeasurementName);


    void    appendRawData(const std::string& pInData);



protected:
private:

    CWrapperTicInflux(const CWrapperTicInflux&) = delete;

    void    frameToInfluxdbPoints(
                const TIC::TDatasetsPtrList& pDatasetsPtrList );



public:
protected:
private:

    std::string         m_influxMeasurementName;
    TIC::FrameBuffer    m_ticFrameBuffer;
    TIC::FrameProcessor m_ticFrameProcessor;
    std::unique_ptr<influxdb::InfluxDB> m_influxdb;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< CWRAPPERTICINFLUX_H */
