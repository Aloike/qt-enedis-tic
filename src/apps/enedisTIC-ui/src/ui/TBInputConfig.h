#ifndef TBINPUTCONFIG_H
#define TBINPUTCONFIG_H

#include <QToolBar>

/* Libraries includes */
class   QHBoxLayout;
class   QPushButton;
class   QRadioButton;

/* Project includes */
#include <enedisTIC/utils.h>
class   CComboBox;


class   TBInputConfig
        :   public  QToolBar
{
    Q_OBJECT

public:

    explicit TBInputConfig(QWidget *parent = nullptr);
//    ~TBSerialConfig();


    void    setInputsList(const QStringList &pPortNamesList);
    void    setInputOpened(const bool pPortConnected);

    QString         selectedInputPath(void) const;
    TIC::TeTICMode  selectedTICMode(void) const;



signals:

    void    inputsListAboutToShow(void);
    void    inputOpenCloseTriggered(bool);



private:

    void    _createConnections(void);
    void    _createLayout(void);


private:

    CComboBox*      p_cbInputName;
    QHBoxLayout*    p_layoutMain;
    QHBoxLayout*    p_layoutTicMode;
    QPushButton*    p_pbOpenClose;
    QRadioButton*   p_rbTicModeHistorical;
    QRadioButton*   p_rbTicModeStandard;
};

#endif  /*< TBSERIALCONFIG_H */
