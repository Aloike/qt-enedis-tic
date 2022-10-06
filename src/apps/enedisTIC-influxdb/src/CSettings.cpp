/* Corresponding header inclusion */
#include "CSettings.h"

/* System includes */

/* Libraries includes */
#include <QCoreApplication>

/* Project includes */
#include "trace.h"


namespace NsConfig
{

namespace InfluxDb
{
static const char*  SERVERNAME_KEY      = "influxdb/host";
static const char*  SERVERNAME_DEFAULT  = "localhost";

static const char*  PORT_KEY      = "influxdb/port";
static const int    PORT_DEFAULT  = 8186;

static const char*  DATABASE_KEY     = "influxdb/database";
static const char*  DATABASE_DEFAULT = "energy";

static const char*  MEASUREMENTNAME_KEY     = "influxdb/measurement_name";
static const char*  MEASUREMENTNAME_DEFAULT = "enedis-tic";
};  /*< namespace InfluxDb */

namespace SerialPort
{
static const char*  PORTNAME_KEY      = "SerialPort/name";
static const char*  PORTNAME_DEFAULT  = "/dev/ttyUSB0";
};  /*< namespace SerialPort */

namespace TIC
{
static const char*  MODE_KEY        = "TIC/mode";
static const char*  MODE_DEFAULT    = "historical";
};  /*< namespace SerialPort */

};  /*< namespace NsConfig */

/* ########################################################################## */
/* ########################################################################## */

CSettings::CSettings(void)
    :   m_settings(
            QCoreApplication::applicationName() + ".ini",
            QSettings::IniFormat
        )
{
    /*
     *  InfluxDB
     */
    this->setIfNotExists(
        NsConfig::InfluxDb::SERVERNAME_KEY,
        NsConfig::InfluxDb::SERVERNAME_DEFAULT
    );

    this->setIfNotExists(
        NsConfig::InfluxDb::PORT_KEY,
        NsConfig::InfluxDb::PORT_DEFAULT
    );

    this->setIfNotExists(
        NsConfig::InfluxDb::DATABASE_KEY,
        NsConfig::InfluxDb::DATABASE_DEFAULT
    );

    this->setIfNotExists(
        NsConfig::InfluxDb::MEASUREMENTNAME_KEY,
        NsConfig::InfluxDb::MEASUREMENTNAME_DEFAULT
    );


    /*
     *  Serial Port
     */
    this->setIfNotExists(
        NsConfig::SerialPort::PORTNAME_KEY,
        NsConfig::SerialPort::PORTNAME_DEFAULT
    );
}

/* ########################################################################## */
/* ########################################################################## */

QString
    CSettings::influxdbDatabaseName(void) const
{
    return
        this->m_settings.value(
                NsConfig::InfluxDb::DATABASE_KEY,
                NsConfig::InfluxDb::DATABASE_DEFAULT
        ).toString();
}

/* ########################################################################## */
/* ########################################################################## */

QString
    CSettings::influxdbHost(void) const
{
    return
        this->m_settings.value(
                NsConfig::InfluxDb::SERVERNAME_KEY,
                NsConfig::InfluxDb::SERVERNAME_DEFAULT
        ).toString();
}

/* ########################################################################## */
/* ########################################################################## */

QString
    CSettings::influxdbMeasurementName(void) const
{
    return
        this->m_settings.value(
                NsConfig::InfluxDb::MEASUREMENTNAME_KEY,
                NsConfig::InfluxDb::MEASUREMENTNAME_DEFAULT
        ).toString();
}

/* ########################################################################## */
/* ########################################################################## */

int CSettings::influxdbPort(void) const
{
    return
        this->m_settings.value(
                NsConfig::InfluxDb::PORT_KEY,
                NsConfig::InfluxDb::PORT_DEFAULT
        ).toInt();
}

/* ########################################################################## */
/* ########################################################################## */

QString
    CSettings::serialPortName(void) const
{
    return
        this->m_settings.value(
                NsConfig::SerialPort::PORTNAME_KEY,
                NsConfig::SerialPort::PORTNAME_DEFAULT
                ).toString();
}

/* ########################################################################## */
/* ########################################################################## */

void
    CSettings::setIfNotExists(
        const QString& pInKey,
        const QVariant& pInValue
    )
{
    if( ! this->m_settings.contains( pInKey ) )
    {
        this->m_settings.setValue(
            pInKey,
            pInValue
        );
    }
}

/* ########################################################################## */
/* ########################################################################## */

TIC::TeTICMode
    CSettings::ticMode()
{

    /* Set default value if the key is not available in the file */
    if( ! this->m_settings.contains( NsConfig::TIC::MODE_KEY ) )
    {
        this->m_settings.setValue(
                NsConfig::TIC::MODE_KEY,
                NsConfig::TIC::MODE_DEFAULT
        );
    }


    QString lValue
        = this->m_settings.value(
                NsConfig::TIC::MODE_KEY,
                NsConfig::TIC::MODE_DEFAULT
        ).toString();

    QString lValueUpper = lValue.toUpper();


    TIC::TeTICMode  retval  = TIC::E_TIC_MODE_HISTORICAL;
    if( lValueUpper == "HISTORICAL" )
    {
        retval  = TIC::E_TIC_MODE_HISTORICAL;
    }
    else if( lValueUpper == "STANDARD" )
    {
        retval  = TIC::E_TIC_MODE_STANDARD;
    }
    else
    {
        TRACE_WARN(
            "Invalid value for '%s': '%s'!",
            NsConfig::TIC::MODE_KEY,
            lValue.toStdString().c_str()
        );

        TRACE_INFO(
            "Valid values of '%s': 'historical' or 'standard'.",
            NsConfig::TIC::MODE_KEY
        );


        TRACE_INFO(
            "Set value of '%s' to default ('%s').",
            NsConfig::TIC::MODE_KEY,
            NsConfig::TIC::MODE_DEFAULT
        );
        this->m_settings.setValue(
            NsConfig::TIC::MODE_KEY,
            NsConfig::TIC::MODE_DEFAULT
        );
    }

    return retval;
}

/* ########################################################################## */
/* ########################################################################## */
