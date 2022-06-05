/* Corresponding header inclusion */
#include "ADCO.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   ADCO::LABEL("ADCO");
const size_t        ADCO::DATA_LENGTH(12);
const std::string   ADCO::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

ADCO::ADCO()
    :   GenericDataset(
            LABEL,
            false,
            DATA_LENGTH,
            UNIT )
{
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
