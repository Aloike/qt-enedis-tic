#ifndef SMAXSN1_1_H
#define SMAXSN1_1_H

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
 *  @brief Puissance app max. soutirée n-1, phase 1.
 */
class   SMAXSN1_1
        :   public  GenericDataset
{
public:

    SMAXSN1_1();



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

#endif  /*< SMAXSN1_1_H */
