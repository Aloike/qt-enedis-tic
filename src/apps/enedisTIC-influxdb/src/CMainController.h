#ifndef CMAINCONTROLLER_H
#define CMAINCONTROLLER_H

/* Inherited classes */
#include <QObject>

/* System includes */
#include <memory>

/* Libraries includes */

/* Project includes */
#include "CSettings.h"
#include "CWrapperTicInflux.h"

#define D_CMainController_READ_FROM_FILE

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

#ifdef  D_CMainController_READ_FROM_FILE
    void    readFromFile(void);
#endif



public:
protected:
private:

    CSettings           m_settings;
    std::unique_ptr<CWrapperTicInflux>  p_wrapperTicInflux;



signals:

public slots:
};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< CMAINCONTROLLER_H */
