#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class   QLabel;
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

    void    setFramesCount(const size_t& pCount);
    void    setDatasetsCount(const size_t& pCount);



private:

    void    _createUi(void);
    void    _createLayout(void);



private:

    WDataViewer*    p_dataViewerW;
    QLabel*         p_labelStatusDatasetsCount;
    QLabel*         p_labelStatusFramesCount;
    TBSerialConfig* p_serialConfigTB;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< MAINWINDOW_H */
