#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class   QVBoxLayout;

#include "core/comm/protocol/tic/TDatasetsList.h"
class   GBInput;
class   GBDataViewer;

/* ########################################################################## */
/* ########################################################################## */

class   MainWindow
    :   public  QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *pParent = nullptr);
    ~MainWindow();


    GBInput*    inputGB(void) const;

    void    updateData(const TIC::TDatasetsPtrList& pDatasetsList);



private:

    void    _createUi(void);
    void    _createLayout(void);



private:

    GBDataViewer*   p_dataViewerGB;
    GBInput*        p_inputGB;
    QVBoxLayout*    p_layoutMain;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< MAINWINDOW_H */
