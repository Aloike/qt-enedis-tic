#ifndef PAPP_H
#define PAPP_H

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
 *  @brief  Puissance apparente triphasée soutirée.
 *
 *  S (en VA), arrondi à la dizaine la plus proche.
 */
class   PAPP
        :   public  GenericDataset
{
public:

    PAPP();



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

#endif  /*< PAPP_H */
