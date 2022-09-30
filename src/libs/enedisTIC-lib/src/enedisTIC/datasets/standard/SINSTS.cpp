/* Corresponding header inclusion */
#include "SINSTS.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   SINSTS::LABEL("SINSTS");
const size_t        SINSTS::DATA_LENGTH(5);
const std::string   SINSTS::UNIT("VA");

/* ########################################################################## */
/* ########################################################################## */

SINSTS::SINSTS()
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
