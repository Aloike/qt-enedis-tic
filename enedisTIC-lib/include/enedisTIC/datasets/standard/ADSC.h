#ifndef ADSC_H
#define ADSC_H

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
 *  @brief  Adresse Secondaire du Compteur.
 *
 *  Il s’agit de l’adresse secondaire EURIDIS du compteur qui correspond aussi
 *  à son numéro de série.
 *
 *  Les compteurs sont identifiables à partir de leur numéro de série dont la
 *  codification répond à la norme EURIDIS en tant qu’identifiant de station
 *  secondaire (ADS).
 *
 *  Le numéro de série des compteurs est codé sur 12 caractères numériques qui
 *  correspondent à la définition suivante :
 *  + code du constructeur 2 caractères,
 *  + millésime de l'année de construction 2 caractères,
 *  + type de l'appareil 2 caractères,
 *  + matricule de l'appareil 6 caractères.
 *
 *  Les compteurs concernés par ce document sont identifiables à partir des 2
 *  caractères représentant le type de l’appareil. Les valeurs couvertes sont :
 *  + 61 : Compteur monophasé 60 A généralisation Linky G3 - arrivée puissance
 *    haute
 *  + 62 : Compteur monophasé 90 A généralisation Linky G1 - arrivée puissance
 *    basse
 *  + 63 : Compteur triphasé 60 A généralisation Linky G1 - arrivée puissance
 *    basse
 *  + 64 : Compteur monophasé 60 A généralisation Linky G3 - arrivée puissance
 *    basse
 *  + 70 : Compteur monophasé Linky 60 A mise au point G3
 *  + 71 : Compteur triphasé Linky 60 A mise au point G3
 *  + 75 : Compteur monophasé 90 A généralisation Linky G3 - arrivée puissance
 *    basse
 *  + 76 : Compteur triphasé 60 A généralisation Linky G3 - arrivée puissance
 *    basse
 */
class   LIBENEDISTIC_EXPORT ADSC
        :   public  GenericDataset
{
public:

    ADSC();



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

#endif  /*< ADSC_H */
