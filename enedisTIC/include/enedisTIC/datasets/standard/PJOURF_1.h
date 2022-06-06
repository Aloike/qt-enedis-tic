#ifndef PJOURF_1_H
#define PJOURF_1_H

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
 *  @brief  Profil du prochain jour calendrier fournisseur.
 */
class   LIBENEDISTIC_EXPORT PJOURF_1
        :   public  GenericDataset
{
public:

    PJOURF_1();



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

#endif  /*< PJOURF_1_H */
