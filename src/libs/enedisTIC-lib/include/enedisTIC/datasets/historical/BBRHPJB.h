#ifndef BBRHPJB_H
#define BBRHPJB_H

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
 *  @brief  Index option Tempo - Heures Pleines Jours Bleus.
 */
class   LIBENEDISTIC_EXPORT BBRHPJB
        :   public  GenericDataset
{
public:

    BBRHPJB();



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

#endif  /*< BBRHPJB_H */
