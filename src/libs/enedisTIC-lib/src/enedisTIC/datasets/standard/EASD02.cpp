/* Corresponding header inclusion */
#include "EASD02.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EASD02::LABEL("EASD02");
const size_t        EASD02::DATA_LENGTH(9);
const std::string   EASD02::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EASD02::EASD02()
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
