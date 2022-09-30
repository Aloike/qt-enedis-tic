/* Corresponding header inclusion */
#include "EAST.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EAST::LABEL("EAST");
const size_t        EAST::DATA_LENGTH(9);
const std::string   EAST::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EAST::EAST()
    :   GenericDataset(
            LABEL,
            false,
            DATA_LENGTH,
            E_DATA_INTEGER,
            UNIT )
{
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
