#ifndef NJOURF_1_H
#define NJOURF_1_H

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
 *  @brief  Numéro du prochain jour calendrier fournisseur.
 */
class   LIBENEDISTIC_EXPORT NJOURF_1
        :   public  GenericDataset
{
public:

    NJOURF_1();



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

#endif  /*< NJOURF_1_H */
