/* Corresponding header inclusion */
#include "CComboBox.h"

/* System includes */

/* Libraries includes */
#include <QLineEdit>

/* Project includes */


/* ########################################################################## */
/* ########################################################################## */

CComboBox::CComboBox(   QWidget*    pParentPtr,
                        bool        pIsEditable )
    :   QComboBox( pParentPtr )
{
    this->setEditable(true);
    this->lineEdit()->setDisabled(false);
    this->lineEdit()->setReadOnly( ! pIsEditable );
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief Destructor of the CComboBox class.
 */
CComboBox::~CComboBox()
{
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  This method overloads QComboBox::showPopup() to be able to emit a
 *          signal when the drop-list is about to show.
 *
 * Having the \ref aboutToShowPopup signal available is convenient to update the
 * list before it is shown to the operator.
 */
void
    CComboBox::showPopup()
{
    emit this->aboutToShowPopup();
    QComboBox::showPopup();
}

/* ########################################################################## */
/* ########################################################################## */
