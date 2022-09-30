/* Corresponding header inclusion */
#include "EASF07.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EASF07::LABEL("EASF07");
const size_t        EASF07::DATA_LENGTH(9);
const std::string   EASF07::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EASF07::EASF07()
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
