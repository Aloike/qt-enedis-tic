#ifndef PRM_H
#define PRM_H

/* Inherited classes */
#include "../../libEnedisTIC_global.h"
#include "../GenericDataset.h"

/* System includes */

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {


/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  PRM (Point de Référence des Mesures).
 *
 *  Ce numéro correspond à la référence de votre logement ou de votre local ;
 *  c’est votre référence client.
 *  Composé de 14 chiffres il figure sur la facture d’électricité de votre
 *  fournisseursous ce nom : numéro de PDL ou PRM.
 *  Il apparaît en haut à droite de votre facture d’électricité.
 *  Si vous contactez votre fournisseur d’électricité ou Enedis, pensez à vous
 *  munir de ce numéro à 14 chiffres, il permet de vous prendre en charge plus
 *  rapidement.
 *  PRM signifie Point de Référence des Mesures,
 *  PDL signifie Point De Livraison. C’est la même référence à 14 chiffres.
 */
class   LIBENEDISTIC_EXPORT PRM
        :   public  GenericDataset
{
public:

    PRM();



protected:
private:



public:

    static const std::string    LABEL;
    static const size_t         DATA_LENGTH;
    static const std::string    UNIT;



protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

} // namespace Dataset
} // namespace TIC

#endif  /*< PRM_H */
