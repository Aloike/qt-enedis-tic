#ifndef BBRHPJW_H
#define BBRHPJW_H

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
 *  @brief  Index option Tempo - Heures Pleines Jours Blancs.
 */
class   LIBENEDISTIC_EXPORT BBRHPJW
        :   public  GenericDataset
{
public:

    BBRHPJW();



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

#endif  /*< BBRHPJW_H */
