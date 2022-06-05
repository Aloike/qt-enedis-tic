/* Corresponding header inclusion */
#include "EASF06.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EASF06::LABEL("EASF06");
const size_t        EASF06::DATA_LENGTH(9);
const std::string   EASF06::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EASF06::EASF06()
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
