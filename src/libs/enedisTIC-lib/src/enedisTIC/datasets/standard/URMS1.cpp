/* Corresponding header inclusion */
#include "URMS1.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   URMS1::LABEL("URMS1");
const size_t        URMS1::DATA_LENGTH(3);
const std::string   URMS1::UNIT("V");

/* ########################################################################## */
/* ########################################################################## */

URMS1::URMS1()
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
