#ifndef TBSERIALCONFIG_H
#define TBSERIALCONFIG_H

#include <QToolBar>

/* Libraries includes */
class   QHBoxLayout;
class   QPushButton;
class   QRadioButton;

/* Project includes */
#include <enedisTIC/utils.h>
class   CComboBox;


class   TBSerialConfig
        :   public  QToolBar
{
    Q_OBJECT

public:

    explicit TBSerialConfig(QWidget *parent = nullptr);
//    ~TBSerialConfig();


    void    setPortsList(const QStringList &pPortNamesList);
    void    setPortOpened(const bool pPortConnected);

    QString         selectedPortName(void) const;
    TIC::TeTICMode  selectedTICMode(void) const;



signals:

    void    portsListAboutToShow(void);
    void    portOpenCloseTriggered(bool);



private:

    void    _createConnections(void);
    void    _createLayout(void);


private:

    CComboBox*      p_cbSerialPortName;
    QHBoxLayout*    p_layoutMain;
    QHBoxLayout*    p_layoutTicMode;
    QPushButton*    p_pbOpenClose;
    QRadioButton*   p_rbTicModeHistorical;
    QRadioButton*   p_rbTicModeStandard;
};

#endif  /*< TBSERIALCONFIG_H */
