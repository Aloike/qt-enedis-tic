/* Corresponding header inclusion */
#include "IINST1.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   IINST1::LABEL("IINST1");
const size_t        IINST1::DATA_LENGTH(3);
const std::string   IINST1::UNIT("A");

/* ########################################################################## */
/* ########################################################################## */

IINST1::IINST1()
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
