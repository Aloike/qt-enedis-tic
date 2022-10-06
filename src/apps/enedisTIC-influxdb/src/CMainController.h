#ifndef CMAINCONTROLLER_H
#define CMAINCONTROLLER_H

/* Inherited classes */
#include <QObject>

/* System includes */
#include <memory>

/* Libraries includes */
#include <QSerialPort>

/* Project includes */
#include "CSettings.h"
#include "CWrapperTicInflux.h"

//#define D_CMainController_READ_FROM_FILE

/* ########################################################################## */
/* ########################################################################## */

class   CMainController
        :   public  QObject
{
    Q_OBJECT

public:

    explicit CMainController(QObject *parent = nullptr);



protected:
private:

    CMainController(const CMainController&)                 = delete;
    CMainController&    operator=(const CMainController&)   = delete;

    void    _createConnections(void);

#ifdef  D_CMainController_READ_FROM_FILE
    void    readFromFile(void);
#endif

    bool    serialPort_init(void);


public slots:
private slots:

    void    on_m_serialPort_readyRead(void);


signals:


public:
protected:
private:

    QSerialPort         m_serialPort;
    CSettings           m_settings;
    std::unique_ptr<CWrapperTicInflux>  p_wrapperTicInflux;


};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< CMAINCONTROLLER_H */
