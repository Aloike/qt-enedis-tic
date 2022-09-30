/* Corresponding header inclusion */
#include "PPOT.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   PPOT::LABEL("PPOT");
const size_t        PPOT::DATA_LENGTH(2);
const std::string   PPOT::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

PPOT::PPOT()
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
