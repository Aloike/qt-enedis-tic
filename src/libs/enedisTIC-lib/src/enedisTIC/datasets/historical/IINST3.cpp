/* Corresponding header inclusion */
#include "IINST3.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   IINST3::LABEL("IINST3");
const size_t        IINST3::DATA_LENGTH(3);
const std::string   IINST3::UNIT("A");

/* ########################################################################## */
/* ########################################################################## */

IINST3::IINST3()
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
