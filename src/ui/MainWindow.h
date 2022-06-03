#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class   QVBoxLayout;

#include "core/comm/protocol/tic/utils.h"
class   GBDataViewer;
class   TBSerialConfig;

/* ########################################################################## */
/* ########################################################################## */

class   MainWindow
    :   public  QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *pParent = nullptr);
    ~MainWindow();


    TBSerialConfig* serialConfigTB(void) const;

    void    updateData(const TIC::TDatasetsPtrList& pDatasetsList);



private:

    void    _createUi(void);
    void    _createLayout(void);



private:

    GBDataViewer*   p_dataViewerGB;
    QVBoxLayout*    p_layoutMain;
    TBSerialConfig* p_serialConfigTB;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< MAINWINDOW_H */
