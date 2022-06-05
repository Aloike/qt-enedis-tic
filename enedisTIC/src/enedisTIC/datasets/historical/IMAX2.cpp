/* Corresponding header inclusion */
#include "IMAX2.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   IMAX2::LABEL("IMAX2");
const size_t        IMAX2::DATA_LENGTH(3);
const std::string   IMAX2::UNIT("A");

/* ########################################################################## */
/* ########################################################################## */

IMAX2::IMAX2()
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
