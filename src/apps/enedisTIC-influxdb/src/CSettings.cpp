/* Corresponding header inclusion */
#include "CSettings.h"

/* System includes */

/* Libraries includes */
#include <QCoreApplication>

/* Project includes */


namespace NsConfig
{

namespace InfluxDb
{
static const char*  SERVERNAME_KEY      = "influxdb/host";
static const char*  SERVERNAME_DEFAULT  = "localhost";

static const char*  PORT_KEY      = "influxdb/port";
static const int    PORT_DEFAULT  = 8186;

static const char*  DATABASE_KEY     = "influxdb/database";
static const char*  DATABASE_DEFAULT = "tmp";

static const char*  MEASUREMENTNAME_KEY     = "influxdb/measurement_name";
static const char*  MEASUREMENTNAME_DEFAULT = "enedis-tic-test";
};  /*< namespace InfluxDb */

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
