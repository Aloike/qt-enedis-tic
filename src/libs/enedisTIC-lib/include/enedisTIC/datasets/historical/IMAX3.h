#ifndef IMAX3_H
#define IMAX3_H

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
 *  @brief  Intensité maximale pour la phase 3.
 */
class   LIBENEDISTIC_EXPORT IMAX3
        :   public  GenericDataset
{
public:

    IMAX3();



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

#endif  /*< IMAX3_H */
