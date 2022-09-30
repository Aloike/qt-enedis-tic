/* Corresponding header inclusion */
#include "EASD03.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EASD03::LABEL("EASD03");
const size_t        EASD03::DATA_LENGTH(9);
const std::string   EASD03::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EASD03::EASD03()
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
