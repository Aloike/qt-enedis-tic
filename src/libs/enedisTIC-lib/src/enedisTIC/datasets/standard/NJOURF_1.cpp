/* Corresponding header inclusion */
#include "NJOURF_1.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   NJOURF_1::LABEL("NJOURF+1");
const size_t        NJOURF_1::DATA_LENGTH(2);
const std::string   NJOURF_1::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

NJOURF_1::NJOURF_1()
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
