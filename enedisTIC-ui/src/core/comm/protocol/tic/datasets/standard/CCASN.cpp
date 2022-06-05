/* Corresponding header inclusion */
#include "CCASN.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   CCASN::LABEL("CCASN");
const size_t        CCASN::DATA_LENGTH(5);
const std::string   CCASN::UNIT("W");

/* ########################################################################## */
/* ########################################################################## */

CCASN::CCASN()
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
