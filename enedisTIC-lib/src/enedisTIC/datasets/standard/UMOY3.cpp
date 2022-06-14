/* Corresponding header inclusion */
#include "UMOY3.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   UMOY3::LABEL("UMOY3");
const size_t        UMOY3::DATA_LENGTH(3);
const std::string   UMOY3::UNIT("V");

/* ########################################################################## */
/* ########################################################################## */

UMOY3::UMOY3()
    :   GenericDataset(
            LABEL,
            true,
            DATA_LENGTH,
            UNIT )
{
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
