/* Corresponding header inclusion */
#include "EASF09.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EASF09::LABEL("EASF09");
const size_t        EASF09::DATA_LENGTH(9);
const std::string   EASF09::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EASF09::EASF09()
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
