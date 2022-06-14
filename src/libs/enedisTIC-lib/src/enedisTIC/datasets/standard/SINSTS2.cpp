/* Corresponding header inclusion */
#include "SINSTS2.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   SINSTS2::LABEL("SINSTS2");
const size_t        SINSTS2::DATA_LENGTH(5);
const std::string   SINSTS2::UNIT("VA");

/* ########################################################################## */
/* ########################################################################## */

SINSTS2::SINSTS2()
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
