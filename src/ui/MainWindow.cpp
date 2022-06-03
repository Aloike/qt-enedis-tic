#include "MainWindow.h"

#include <QCoreApplication>
#include <QMenuBar>
#include <QVBoxLayout>

#include "GBDataViewer.h"
#include "TBSerialConfig.h"

/* ########################################################################## */
/* ########################################################################## */

MainWindow::MainWindow(QWidget *pParent)
    :   QMainWindow(pParent)
    ,   p_dataViewerGB(new GBDataViewer(this))
    ,   p_layoutMain( nullptr )
    ,   p_serialConfigTB(new TBSerialConfig(this))
{
    this->setWindowTitle(QCoreApplication::applicationName());

    this->_createUi();
    this->_createLayout();

//    this->showMaximized();
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
    this->setCentralWidget( new QWidget(this) );
    this->p_layoutMain  = new QVBoxLayout(this->centralWidget());

    this->p_layoutMain->addWidget( this->p_dataViewerGB );
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
    this->p_dataViewerGB->updateData(pDatasetsList);
}

/* ########################################################################## */
/* ########################################################################## */
