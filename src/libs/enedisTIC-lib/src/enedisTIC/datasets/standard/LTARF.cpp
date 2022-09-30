/* Corresponding header inclusion */
#include "LTARF.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   LTARF::LABEL("LTARF");
const size_t        LTARF::DATA_LENGTH(16);

/* ########################################################################## */
/* ########################################################################## */

LTARF::LTARF()
    :   GenericDataset(
            LABEL,
            false,
            DATA_LENGTH,
            E_DATA_TEXT )
{
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
