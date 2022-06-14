#ifndef PMAX_H
#define PMAX_H

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
 *  @brief  Puissance maximale triphasée atteinte (Smax (en VA) du jour n-1).
 */
class   LIBENEDISTIC_EXPORT PMAX
        :   public  GenericDataset
{
public:

    PMAX();



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

#endif  /*< PMAX_H */
