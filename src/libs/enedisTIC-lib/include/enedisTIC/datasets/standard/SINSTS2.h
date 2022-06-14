#ifndef SINSTS2_H
#define SINSTS2_H

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
 *  @brief  Puissance app. instantanée soutirée phase 2.
 */
class   LIBENEDISTIC_EXPORT SINSTS2
        :   public  GenericDataset
{
public:

    SINSTS2();



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

#endif  /*< SINSTS2_H */
