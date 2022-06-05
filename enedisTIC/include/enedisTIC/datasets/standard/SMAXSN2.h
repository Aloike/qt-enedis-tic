#ifndef SMAXSN2_H
#define SMAXSN2_H

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
 *  @brief Puissance app. max. soutirée n, phase 2.
 */
class   LIBENEDISTIC_EXPORT SMAXSN2
        :   public  GenericDataset
{
public:

    SMAXSN2();



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

#endif  /*< SMAXSN2_H */
