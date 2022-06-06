#ifndef WDATAVIEWER_H
#define WDATAVIEWER_H

/* Inherited classes */
#include <QWidget>

/* System includes */

/* Libraries includes */
class   QHBoxLayout;
class   QTableWidget;
class   QVBoxLayout;

/* Project includes */
#include <enedisTIC/utils.h>

class   GBCourantTension;
class   GBEnergieActive;
class   GBInfosCompteur;
class   GBPuissanceApparente;
class   GBTarification;



/* ########################################################################## */
/* ########################################################################## */

class   WDataViewer
        :   public  QWidget
{
    Q_OBJECT

public:

    explicit WDataViewer(QWidget *parent = nullptr);


    void    updateData(const TIC::TDatasetsPtrList &pDatasetsList);



protected:
private:

    void    _createLayout(void);
    void    _createUi(void);



public:
protected:
private:

    GBEnergieActive*        p_energieActiveGB;
    GBInfosCompteur*        p_infosCompteurGB;
    QHBoxLayout*            p_layoutMain;
    QVBoxLayout*            p_layoutConsumption;
    GBPuissanceApparente*   p_puissanceApparenteGB;
    GBTarification*         p_tarificationGB;
    GBCourantTension*       p_tensionCourantGB;



signals:

public slots:
};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< WDATAVIEWER_H */
