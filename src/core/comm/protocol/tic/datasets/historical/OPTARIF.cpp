/* Corresponding header inclusion */
#include "OPTARIF.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   OPTARIF::LABEL("OPTARIF");
const size_t        OPTARIF::DATA_LENGTH(4);
const std::string   OPTARIF::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

OPTARIF::OPTARIF()
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
