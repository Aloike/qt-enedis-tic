/* Corresponding header inclusion */
#include "IINST2.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   IINST2::LABEL("IINST2");
const size_t        IINST2::DATA_LENGTH(3);
const std::string   IINST2::UNIT("A");

/* ########################################################################## */
/* ########################################################################## */

IINST2::IINST2()
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
