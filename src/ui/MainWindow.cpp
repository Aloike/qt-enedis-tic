#include "MainWindow.h"

#include <QCoreApplication>
#include <QMenuBar>
#include <QVBoxLayout>

#include "TBSerialConfig.h"
#include "WDataViewer.h"

/* ########################################################################## */
/* ########################################################################## */

MainWindow::MainWindow(QWidget *pParent)
    :   QMainWindow(pParent)
    ,   p_serialConfigTB(new TBSerialConfig(this))
    ,   p_dataViewerW(new WDataViewer(this))
{
    this->setWindowTitle(QCoreApplication::applicationName());

    this->_createUi();
    this->_createLayout();
}

/* ########################################################################## */
/* ########################################################################## */

MainWindow::~MainWindow()
{
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainWindow::_createLayout(void)
{
    this->setCentralWidget( this->p_dataViewerW );
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainWindow::_createUi(void)
{
//    this->setMenuBar(new QMenuBar(this));
    this->menuBar()->addMenu("testMenu");

    this->addToolBar(this->p_serialConfigTB);
}

/* ########################################################################## */
/* ########################################################################## */

TBSerialConfig*
    MainWindow::serialConfigTB(void) const
{
    return this->p_serialConfigTB;
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainWindow::updateData(const TIC::TDatasetsPtrList &pDatasetsList)
{
    this->p_dataViewerW->updateData(pDatasetsList);
}

/* ########################################################################## */
/* ########################################################################## */
