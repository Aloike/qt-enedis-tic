#ifndef GBINPUT_H
#define GBINPUT_H

/* Inherited classes */
#include <QGroupBox>

/* System includes */

/* Libraries includes */
class   QGridLayout;
class   QHBoxLayout;
class   QPushButton;
class   QRadioButton;

/* Project includes */
#include <enedisTIC/utils.h>
class   CComboBox;


/* ########################################################################## */
/* ########################################################################## */

class   GBInput
        :   public  QGroupBox
{
    Q_OBJECT

public:

    GBInput(QWidget* pParentPtr);


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

    enum    EColumns {
        E_COL_LABEL,
        E_COL_WIDGET
    };

    enum    ERows {
        E_ROW_SERIALPORTNAME,
        E_ROW_TICMODE,
        E_ROW_OPENCLOSE
    };

    CComboBox*      p_cbSerialPortName;
    QGridLayout*    p_layoutMain;
    QHBoxLayout*    p_layoutTicMode;
    QPushButton*    p_pbOpenClose;
    QRadioButton*   p_rbTicModeHistorical;
    QRadioButton*   p_rbTicModeStandard;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< GBINPUT_H */
