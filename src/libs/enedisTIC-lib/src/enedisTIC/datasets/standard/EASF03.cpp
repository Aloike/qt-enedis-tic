/* Corresponding header inclusion */
#include "EASF03.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EASF03::LABEL("EASF03");
const size_t        EASF03::DATA_LENGTH(9);
const std::string   EASF03::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EASF03::EASF03()
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
