#ifndef CSETTINGS_H
#define CSETTINGS_H

/* Inherited classes */

/* System includes */

/* Libraries includes */
#include <QSettings>

/* Project includes */
#include <enedisTIC/utils.h>


/* ########################################################################## */
/* ########################################################################## */

class   CSettings
{
public:

    CSettings(void);
    CSettings(CSettings&&)      = delete;
    CSettings(const CSettings&) = delete;


    QString     influxdbHost(void) const;
    int         influxdbPort(void) const;
    QString     influxdbDatabaseName(void) const;
    QString     influxdbMeasurementName(void) const;

    QString     serialPortName(void) const;

    TIC::TeTICMode  ticMode(void);



protected:
private:

    void    setIfNotExists( const QString& pInKey, const QVariant& pInValue );



public:
protected:
private:

    QSettings   m_settings;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< CSETTINGS_H */
