#ifndef NGTF_H
#define NGTF_H

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
 *  @brief  Nom du calendrier tarifaire fournisseur.
 */
class  LIBENEDISTIC_EXPORT  NGTF
        :   public  GenericDataset
{
public:

    NGTF();



protected:
private:



public:

    static const std::string    LABEL;
    static const size_t         DATA_LENGTH;



protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

} // namespace Dataset
} // namespace TIC

#endif  /*< NGTF_H */
