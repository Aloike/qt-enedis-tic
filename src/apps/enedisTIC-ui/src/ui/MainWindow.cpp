#include "MainWindow.h"

#include <QCoreApplication>
#include <QLabel>
#include <QMenuBar>
#include <QStatusBar>
#include <QVBoxLayout>

#include "TBSerialConfig.h"
#include "WDataViewer.h"

/* ########################################################################## */
/* ########################################################################## */

MainWindow::MainWindow(QWidget *pParent)
    :   QMainWindow(pParent)
    ,   p_dataViewerW(new WDataViewer(this))
    ,   p_labelStatusDatasetsCount(new QLabel(this))
    ,   p_labelStatusFramesCount(new QLabel(this))
    ,   p_serialConfigTB(new TBSerialConfig(this))
{
    this->setWindowTitle(QCoreApplication::applicationName());

    this->_createUi();
    this->_createLayout();

    this->setDatasetsCount(0U);
    this->setFramesCount(0U);
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
    this->menuBar()->addMenu("testMenu");

    this->addToolBar(this->p_serialConfigTB);
    this->statusBar()->addPermanentWidget(
        this->p_labelStatusFramesCount
    );
    this->statusBar()->addPermanentWidget(
        this->p_labelStatusDatasetsCount
    );
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

void
    MainWindow::setDatasetsCount(const size_t &pCount)
{
    this->p_labelStatusDatasetsCount->setText(
        tr("Datasets: ") + QString("%1").arg(pCount)
    );
}

/* ########################################################################## */
/* ########################################################################## */

void
    MainWindow::setFramesCount(const size_t &pCount)
{
    this->p_labelStatusFramesCount->setText(
        tr("Frames: ") + QString("%1").arg(pCount)
    );
}

/* ########################################################################## */
/* ########################################################################## */
