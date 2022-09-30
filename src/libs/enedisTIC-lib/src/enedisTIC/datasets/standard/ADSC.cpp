/* Corresponding header inclusion */
#include "ADSC.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   ADSC::LABEL("ADSC");
const size_t        ADSC::DATA_LENGTH(12);
const std::string   ADSC::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

ADSC::ADSC()
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
