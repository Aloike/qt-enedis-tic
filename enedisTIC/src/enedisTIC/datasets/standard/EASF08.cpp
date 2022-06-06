/* Corresponding header inclusion */
#include "EASF08.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EASF08::LABEL("EASF08");
const size_t        EASF08::DATA_LENGTH(9);
const std::string   EASF08::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EASF08::EASF08()
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
