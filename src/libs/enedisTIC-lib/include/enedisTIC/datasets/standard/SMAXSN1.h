#ifndef SMAXSN1_H
#define SMAXSN1_H

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
 *  @brief Puissance app. max. soutirée n, phase 1.
 */
class   LIBENEDISTIC_EXPORT SMAXSN1
        :   public  GenericDataset
{
public:

    SMAXSN1();



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

#endif  /*< SMAXSN1_H */
