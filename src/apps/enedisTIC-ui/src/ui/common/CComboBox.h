#ifndef CCOMBOBOX_H
#define CCOMBOBOX_H

/* Inherited classes */
#include <QComboBox>

/* System includes */

/* Libraries includes */

/* Project includes */



/* ########################################################################## */
/* ########################################################################## */

class   CComboBox
        :   public  QComboBox
{
    Q_OBJECT

public:

    CComboBox(QWidget *pParentPtr, bool pIsEditable=false);
    virtual ~CComboBox();


    virtual void    showPopup();




signals:

    void    aboutToShowPopup(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< CCOMBOBOX_H */
