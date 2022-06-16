/* Corresponding header inclusion */
#include "STGE.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   STGE::LABEL("STGE");
const size_t        STGE::DATA_LENGTH(8);
const std::string   STGE::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

STGE::STGE()
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
