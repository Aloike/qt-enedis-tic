/* Corresponding header inclusion */
#include "EASF04.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EASF04::LABEL("EASF04");
const size_t        EASF04::DATA_LENGTH(9);
const std::string   EASF04::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EASF04::EASF04()
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
