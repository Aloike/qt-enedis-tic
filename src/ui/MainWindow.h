#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class   QVBoxLayout;

#include "core/comm/protocol/tic/utils.h"
class   TBSerialConfig;
class   WDataViewer;

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

    TBSerialConfig* p_serialConfigTB;
    WDataViewer*    p_dataViewerW;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< MAINWINDOW_H */
