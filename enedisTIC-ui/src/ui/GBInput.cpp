/* Corresponding header inclusion */
#include "GBInput.h"

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

GBInput::GBInput(QWidget *pParentPtr)
    :   QGroupBox(
            tr("Input"),
            pParentPtr
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
    GBInput::_createConnections(void)
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
    GBInput::_createLayout()
{
    this->p_layoutMain  = new QGridLayout(this);
    this->p_layoutMain->addWidget(
        new QLabel(
            tr("Serial port"),
            this ),
        E_ROW_SERIALPORTNAME,
        E_COL_LABEL
    );
    this->p_layoutMain->addWidget(
        this->p_cbSerialPortName,
        E_ROW_SERIALPORTNAME,
        E_COL_WIDGET
    );

    this->p_layoutMain->addWidget(
        new QLabel(
            tr("TIC mode"),
            this ),
        E_ROW_TICMODE,
        E_COL_LABEL
    );

    this->p_layoutTicMode   = new QHBoxLayout();
    this->p_layoutMain->addLayout(
        this->p_layoutTicMode,
        E_ROW_TICMODE,
        E_COL_WIDGET
    );
    this->p_layoutTicMode->addWidget(this->p_rbTicModeHistorical);
    this->p_layoutTicMode->addWidget(this->p_rbTicModeStandard);


    this->p_layoutMain->addWidget(
        this->p_pbOpenClose,
        E_ROW_OPENCLOSE,
        E_COL_WIDGET
    );
}

/* ########################################################################## */
/* ########################################################################## */

QString
    GBInput::selectedPortName(void) const
{
    return this->p_cbSerialPortName->currentText();
}

/* ########################################################################## */
/* ########################################################################## */

TIC::TeTICMode
    GBInput::selectedTICMode(void) const
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
    GBInput::setPortsList(const QStringList& pPortNamesList)
{
    this->p_cbSerialPortName->clear();
    this->p_cbSerialPortName->addItems(pPortNamesList);
}

/* ########################################################################## */
/* ########################################################################## */

void
    GBInput::setPortOpened(const bool pPortConnected)
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
