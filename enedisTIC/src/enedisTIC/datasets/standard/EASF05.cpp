/* Corresponding header inclusion */
#include "EASF05.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EASF05::LABEL("EASF05");
const size_t        EASF05::DATA_LENGTH(9);
const std::string   EASF05::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EASF05::EASF05()
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
