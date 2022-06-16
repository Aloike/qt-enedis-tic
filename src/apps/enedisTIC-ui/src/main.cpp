#include <QApplication>

#include "MainController.h"
#include "src-autogen/Version.h"

/* ########################################################################## */
/* ########################################################################## */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationVersion(VERSION_CVS + "-" + VERSION_BUILD);


    MainController  lMainController;

    return a.exec();
}

/* ########################################################################## */
/* ########################################################################## */
