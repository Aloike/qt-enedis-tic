/* Corresponding header inclusion */
#include "EASD04.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EASD04::LABEL("EASD04");
const size_t        EASD04::DATA_LENGTH(9);
const std::string   EASD04::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EASD04::EASD04()
    :   GenericDataset(
            LABEL,
            false,
            DATA_LENGTH,
            UNIT )
{
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
