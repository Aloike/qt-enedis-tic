/* Corresponding header inclusion */
#include "TBSerialConfig.h"

/* System includes */
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>

/* Libraries includes */

/* Project includes */
#include "common/CComboBox.h"


/* ########################################################################## */
/* ########################################################################## */

TBSerialConfig::TBSerialConfig(QWidget *parent)
    :   QToolBar(
            tr("Serial port configuration"),
            parent
        )
    ,   p_cbSerialPortName(new CComboBox(this))
    ,   p_layoutMain(NULL)
    ,   p_layoutTicMode(NULL)
    ,   p_pbOpenClose(new QPushButton(tr("Open/Close"), this))
    ,   p_rbTicModeHistorical(new QRadioButton(tr("Historical"),this))
    ,   p_rbTicModeStandard(new QRadioButton(tr("Standard"),this))
{
    this->_createLayout();
    this->_createConnections();

    this->p_rbTicModeHistorical->setChecked(true);
}

/* ########################################################################## */
/* ########################################################################## */

void
    TBSerialConfig::_createConnections(void)
{
    QObject::connect(
        this->p_cbSerialPortName,
        SIGNAL(aboutToShowPopup()),
        this,
        SIGNAL(portsListAboutToShow())
    );

    QObject::connect(
        this->p_pbOpenClose,
        SIGNAL(clicked(bool)),
        this,
        SIGNAL(portOpenCloseTriggered(bool))
    );
}

/* ########################################################################## */
/* ########################################################################## */

void
    TBSerialConfig::_createLayout()
{
    this->addWidget(
        new QLabel(
            tr("Serial port:"),
            this )
    );
    this->addWidget(
        this->p_cbSerialPortName
    );

    this->addSeparator();

    this->addWidget(
        new QLabel(
            tr("TIC mode"),
            this )
    );

    this->addWidget(this->p_rbTicModeHistorical);
    this->addWidget(this->p_rbTicModeStandard);

    this->addSeparator();

    this->addWidget(
        this->p_pbOpenClose
    );
}

/* ########################################################################## */
/* ########################################################################## */

QString
    TBSerialConfig::selectedPortName(void) const
{
    return this->p_cbSerialPortName->currentText();
}

/* ########################################################################## */
/* ########################################################################## */

TIC::TeTICMode
    TBSerialConfig::selectedTICMode(void) const
{
    TIC::TeTICMode  retval;

    if( this->p_rbTicModeHistorical->isChecked() )
    {
        retval  = TIC::E_TIC_MODE_HISTORICAL;
    }
    else if( this->p_rbTicModeStandard->isChecked() )
    {
        retval  = TIC::E_TIC_MODE_STANDARD;
    }
    else
    {
        throw std::logic_error("Unexpected case: No TIC mode selected!");
    }

    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

void
    TBSerialConfig::setPortsList(const QStringList& pPortNamesList)
{
    this->p_cbSerialPortName->clear();
    this->p_cbSerialPortName->addItems(pPortNamesList);
}

/* ########################################################################## */
/* ########################################################################## */

void
    TBSerialConfig::setPortOpened(const bool pPortConnected)
{
    this->p_cbSerialPortName->setEnabled( ! pPortConnected );
    this->p_rbTicModeHistorical->setEnabled( ! pPortConnected );
    this->p_rbTicModeStandard->setEnabled( ! pPortConnected );

    if( pPortConnected )
    {
        this->p_pbOpenClose->setText(tr("Close"));
    }
    else
    {
        this->p_pbOpenClose->setText(tr("Open"));
    }
}

/* ########################################################################## */
/* ########################################################################## */
