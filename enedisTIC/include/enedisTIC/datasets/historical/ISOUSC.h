#ifndef ISOUSC_H
#define ISOUSC_H

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
 *  @brief  Intensité souscrite.
 *
 *  Pour triphasé: 1/3 PREF (en VA)/200 V.
 */
class   LIBENEDISTIC_EXPORT ISOUSC
        :   public  GenericDataset
{
public:

    ISOUSC();



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

#endif  /*< ISOUSC_H */
