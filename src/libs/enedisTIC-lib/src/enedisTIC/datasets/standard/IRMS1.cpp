/* Corresponding header inclusion */
#include "IRMS1.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   IRMS1::LABEL("IRMS1");
const size_t        IRMS1::DATA_LENGTH(3);
const std::string   IRMS1::UNIT("A");

/* ########################################################################## */
/* ########################################################################## */

IRMS1::IRMS1()
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
