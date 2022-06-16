#include "MainWindow.h"

#include <QCoreApplication>
#include <QLabel>
#include <QMenuBar>
#include <QStatusBar>
#include <QVBoxLayout>

#include "TBInputConfig.h"
#include "WDataViewer.h"

/* ########################################################################## */
/* ########################################################################## */

MainWindow::MainWindow(QWidget *pParent)
    :   QMainWindow(pParent)
    ,   p_dataViewerW(new WDataViewer(this))
    ,   p_inputConfigTB(new TBInputConfig(this))
    ,   p_labelStatusDatasetsCount(new QLabel(this))
    ,   p_labelStatusFramesCount(new QLabel(this))
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

    this->addToolBar(this->p_inputConfigTB);
    this->statusBar()->addPermanentWidget(
        this->p_labelStatusFramesCount
    );
    this->statusBar()->addPermanentWidget(
        this->p_labelStatusDatasetsCount
    );
}

/* ########################################################################## */
/* ########################################################################## */

TBInputConfig*
    MainWindow::inputConfigTB(void) const
{
    return this->p_inputConfigTB;
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

void
    MainWindow::setStatus(const QString &pStatusMsg)
{
    this->statusBar()->showMessage( pStatusMsg );
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
