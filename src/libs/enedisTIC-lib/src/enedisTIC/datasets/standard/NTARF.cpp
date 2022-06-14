/* Corresponding header inclusion */
#include "NTARF.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   NTARF::LABEL("NTARF");
const size_t        NTARF::DATA_LENGTH(2);
const std::string   NTARF::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

NTARF::NTARF()
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
