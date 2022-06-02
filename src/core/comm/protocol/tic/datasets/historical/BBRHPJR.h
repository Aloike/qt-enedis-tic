#ifndef BBRHPJR_H
#define BBRHPJR_H

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
 *  @brief  Index option Tempo - Heures Pleines Jours Rouges.
 */
class   BBRHPJR
        :   public  GenericDataset
{
public:

    BBRHPJR();



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

#endif  /*< BBRHPJR_H */
