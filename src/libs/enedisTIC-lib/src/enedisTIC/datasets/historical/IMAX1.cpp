/* Corresponding header inclusion */
#include "IMAX1.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   IMAX1::LABEL("IMAX1");
const size_t        IMAX1::DATA_LENGTH(3);
const std::string   IMAX1::UNIT("A");

/* ########################################################################## */
/* ########################################################################## */

IMAX1::IMAX1()
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
