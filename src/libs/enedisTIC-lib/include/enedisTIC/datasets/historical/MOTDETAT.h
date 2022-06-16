#ifndef MOTDETAT_H
#define MOTDETAT_H

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
 *  @brief  Mot d'Etat du compteur.
 */
class   LIBENEDISTIC_EXPORT MOTDETAT
        :   public  GenericDataset
{
public:

    MOTDETAT();



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

#endif  /*< MOTDETAT_H */
