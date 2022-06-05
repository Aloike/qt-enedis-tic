#ifndef PPOT_H
#define PPOT_H

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
 *  @brief  Présence des potentiels.
 *
 *  "0X", le X reflétant les coupures de phase selon la règle suivante :
 *  absence de la phase n  bit n = 1
 */
class   PPOT
        :   public  GenericDataset
{
public:

    PPOT();



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

#endif  /*< PPOT_H */
