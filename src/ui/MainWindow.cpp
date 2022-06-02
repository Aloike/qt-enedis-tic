#include "MainWindow.h"

#include <QCoreApplication>
#include <QMenuBar>
#include <QVBoxLayout>

#include "GBInput.h"
#include "GBDataViewer.h"

/* ########################################################################## */
/* ########################################################################## */

MainWindow::MainWindow(QWidget *pParent)
    :   QMainWindow(pParent)
    ,   p_dataViewerGB(new GBDataViewer(this))
    ,   p_inputGB(new GBInput(this))
    ,   p_layoutMain( nullptr )
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

    this->p_layoutMain->addWidget( this->p_inputGB );
    this->p_layoutMain->addWidget( this->p_dataViewerGB );
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainWindow::_createUi(void)
{
//    this->setMenuBar(new QMenuBar(this));
    this->menuBar()->addMenu("testMenu");
}

/* ########################################################################## */
/* ########################################################################## */

GBInput*
    MainWindow::inputGB(void) const
{
    return this->p_inputGB;
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
