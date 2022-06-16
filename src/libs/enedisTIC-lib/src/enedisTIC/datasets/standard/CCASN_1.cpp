/* Corresponding header inclusion */
#include "CCASN_1.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   CCASN_1::LABEL("CCASN-1");
const size_t        CCASN_1::DATA_LENGTH(5);
const std::string   CCASN_1::UNIT("W");

/* ########################################################################## */
/* ########################################################################## */

CCASN_1::CCASN_1()
    :   GenericDataset(
            LABEL,
            true,
            DATA_LENGTH,
            UNIT )
{
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
