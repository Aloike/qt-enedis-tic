/* Corresponding header inclusion */
#include "IRMS3.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   IRMS3::LABEL("IRMS3");
const size_t        IRMS3::DATA_LENGTH(3);
const std::string   IRMS3::UNIT("A");

/* ########################################################################## */
/* ########################################################################## */

IRMS3::IRMS3()
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
