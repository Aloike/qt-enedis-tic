#ifndef VTIC_H
#define VTIC_H

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
 *  @brief  Version de la TIC.
 */
class   LIBENEDISTIC_EXPORT VTIC
        :   public  GenericDataset
{
public:

    VTIC();



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

#endif  /*< VTIC_H */
