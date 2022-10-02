#ifndef CSETTINGS_H
#define CSETTINGS_H

/* Inherited classes */

/* System includes */

/* Libraries includes */
#include <QSettings>

/* Project includes */



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