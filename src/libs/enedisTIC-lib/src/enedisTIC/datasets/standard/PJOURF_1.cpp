/* Corresponding header inclusion */
#include "PJOURF_1.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   PJOURF_1::LABEL("PJOURF+1");
const size_t        PJOURF_1::DATA_LENGTH(98);
const std::string   PJOURF_1::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

PJOURF_1::PJOURF_1()
    :   GenericDataset(
            LABEL,
            false,
            DATA_LENGTH,
            E_DATA_TEXT,
            UNIT )
{
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
