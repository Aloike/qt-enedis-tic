/* Corresponding header inclusion */
#include "IRMS2.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   IRMS2::LABEL("IRMS2");
const size_t        IRMS2::DATA_LENGTH(3);
const std::string   IRMS2::UNIT("A");

/* ########################################################################## */
/* ########################################################################## */

IRMS2::IRMS2()
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
