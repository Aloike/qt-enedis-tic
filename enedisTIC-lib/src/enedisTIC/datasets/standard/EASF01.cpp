/* Corresponding header inclusion */
#include "EASF01.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EASF01::LABEL("EASF01");
const size_t        EASF01::DATA_LENGTH(9);
const std::string   EASF01::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EASF01::EASF01()
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
