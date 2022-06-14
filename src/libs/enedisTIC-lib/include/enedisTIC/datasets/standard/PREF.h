#ifndef PREF_H
#define PREF_H

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
 *  @brief  Puissance app. de référence (PREF).
 */
class   LIBENEDISTIC_EXPORT PREF
        :   public  GenericDataset
{
public:

    PREF();



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

#endif  /*< PREF_H */
