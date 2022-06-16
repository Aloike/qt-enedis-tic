#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class   QLabel;
class   QVBoxLayout;

#include <enedisTIC/utils.h>

class   TBInputConfig;
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


    TBInputConfig*  inputConfigTB(void) const;

    void    setStatus(const QString& pStatusMsg);
    void    updateData(const TIC::TDatasetsPtrList& pDatasetsList);

    void    setFramesCount(const size_t& pCount);
    void    setDatasetsCount(const size_t& pCount);



private:

    void    _createUi(void);
    void    _createLayout(void);



private:

    WDataViewer*    p_dataViewerW;
    TBInputConfig*  p_inputConfigTB;
    QLabel*         p_labelStatusDatasetsCount;
    QLabel*         p_labelStatusFramesCount;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< MAINWINDOW_H */
