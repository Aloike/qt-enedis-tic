#ifndef LTARF_H
#define LTARF_H

/* Inherited classes */
#include "../GenericDataset.h"

/* System includes */

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {


/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Libellé tarif fournisseur en cours.
 */
class   LTARF
        :   public  GenericDataset
{
public:

    LTARF();



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

#endif  /*< LTARF_H */
