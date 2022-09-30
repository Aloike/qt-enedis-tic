/* Corresponding header inclusion */
#include "URMS3.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   URMS3::LABEL("URMS3");
const size_t        URMS3::DATA_LENGTH(3);
const std::string   URMS3::UNIT("V");

/* ########################################################################## */
/* ########################################################################## */

URMS3::URMS3()
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
