/* Corresponding header inclusion */
#include "EASF10.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EASF10::LABEL("EASF10");
const size_t        EASF10::DATA_LENGTH(9);
const std::string   EASF10::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EASF10::EASF10()
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
