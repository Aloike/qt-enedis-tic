/* Corresponding header inclusion */
#include "VTIC.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   VTIC::LABEL("VTIC");
const size_t        VTIC::DATA_LENGTH(2);

/* ########################################################################## */
/* ########################################################################## */

VTIC::VTIC()
    :   GenericDataset(
            LABEL,
            false,
            DATA_LENGTH,
            E_DATA_INTEGER )
{
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
