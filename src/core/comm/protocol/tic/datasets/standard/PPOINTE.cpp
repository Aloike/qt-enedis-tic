/* Corresponding header inclusion */
#include "PPOINTE.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   PPOINTE::LABEL("PPOINTE");
const size_t        PPOINTE::DATA_LENGTH(98);
const std::string   PPOINTE::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

PPOINTE::PPOINTE()
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
