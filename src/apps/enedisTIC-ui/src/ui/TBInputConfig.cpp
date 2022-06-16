/* Corresponding header inclusion */
#include "TBInputConfig.h"

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

TBInputConfig::TBInputConfig(QWidget *parent)
    :   QToolBar(
            tr("Input configuration"),
            parent
        )
    ,   p_cbInputName(new CComboBox(this, true))
    ,   p_layoutMain(NULL)
    ,   p_layoutTicMode(NULL)
    ,   p_pbOpenClose(new QPushButton(tr("Open/Close"), this))
    ,   p_rbTicModeHistorical(new QRadioButton(tr("Historical"),this))
    ,   p_rbTicModeStandard(new QRadioButton(tr("Standard"),this))
{
    this->_createLayout();
    this->_createConnections();

    this->p_cbInputName->setMinimumWidth( 250 );
    this->p_rbTicModeHistorical->setChecked(true);
}

/* ########################################################################## */
/* ########################################################################## */

void
    TBInputConfig::_createConnections(void)
{
    QObject::connect(
        this->p_cbInputName,
        SIGNAL(aboutToShowPopup()),
        this,
        SIGNAL(inputsListAboutToShow())
    );

    QObject::connect(
        this->p_pbOpenClose,
        SIGNAL(clicked(bool)),
        this,
        SIGNAL(inputOpenCloseTriggered(bool))
    );
}

/* ########################################################################## */
/* ########################################################################## */

void
    TBInputConfig::_createLayout()
{
    this->addWidget(
        new QLabel(
            tr("Input:"),
            this )
    );
    this->addWidget(
        this->p_cbInputName
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
    TBInputConfig::selectedInputPath(void) const
{
    return this->p_cbInputName->currentText();
}

/* ########################################################################## */
/* ########################################################################## */

TIC::TeTICMode
    TBInputConfig::selectedTICMode(void) const
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
    TBInputConfig::setInputsList(const QStringList& pInputPathsList)
{
    this->p_cbInputName->clear();
    this->p_cbInputName->addItems(pInputPathsList);
}

/* ########################################################################## */
/* ########################################################################## */

void
    TBInputConfig::setInputOpened(const bool pInputOpened)
{
    this->p_cbInputName->setEnabled( ! pInputOpened );
    this->p_rbTicModeHistorical->setEnabled( ! pInputOpened );
    this->p_rbTicModeStandard->setEnabled( ! pInputOpened );

    if( pInputOpened )
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
