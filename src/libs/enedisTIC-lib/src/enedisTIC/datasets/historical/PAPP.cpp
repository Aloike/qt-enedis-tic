/* Corresponding header inclusion */
#include "PAPP.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   PAPP::LABEL("PAPP");
const size_t        PAPP::DATA_LENGTH(5);
const std::string   PAPP::UNIT("VA");

/* ########################################################################## */
/* ########################################################################## */

PAPP::PAPP()
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
