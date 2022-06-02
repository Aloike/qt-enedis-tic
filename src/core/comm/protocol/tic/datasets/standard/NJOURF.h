#ifndef NJOURF_H
#define NJOURF_H

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
 *  @brief  Numéro du jour en cours calendrier fournisseur.
 */
class   NJOURF
        :   public  GenericDataset
{
public:

    NJOURF();



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

#endif  /*< NJOURF_H */
