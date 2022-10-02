#include <QCoreApplication>

#include "CMainController.h"

/* ########################################################################## */
/* ########################################################################## */

int main(int argc,char *argv[])
{
    QCoreApplication    app( argc, argv );

    app.setOrganizationName("Aloike");
    app.setOrganizationDomain("aloike.github.io");
    app.setApplicationName("enedisTIC-influxdb");


    CMainController lMainController( &app );

    return  app.exec();
}

/* ########################################################################## */
/* ########################################################################## */
