#ifndef BBRHCJR_H
#define BBRHCJR_H

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
 *  @brief  Index option Tempo - Heures Creuses Jours Rouges.
 */
class   LIBENEDISTIC_EXPORT BBRHCJR
        :   public  GenericDataset
{
public:

    BBRHCJR();



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

#endif  /*< BBRHCJR_H */
