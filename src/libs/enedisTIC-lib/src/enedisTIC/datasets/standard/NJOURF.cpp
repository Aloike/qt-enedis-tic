/* Corresponding header inclusion */
#include "NJOURF.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   NJOURF::LABEL("NJOURF");
const size_t        NJOURF::DATA_LENGTH(2);
const std::string   NJOURF::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

NJOURF::NJOURF()
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
