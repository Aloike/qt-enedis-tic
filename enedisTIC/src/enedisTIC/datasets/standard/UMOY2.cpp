/* Corresponding header inclusion */
#include "UMOY2.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   UMOY2::LABEL("UMOY2");
const size_t        UMOY2::DATA_LENGTH(3);
const std::string   UMOY2::UNIT("V");

/* ########################################################################## */
/* ########################################################################## */

UMOY2::UMOY2()
    :   GenericDataset(
            LABEL,
            true,
            DATA_LENGTH,
            UNIT )
{
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
