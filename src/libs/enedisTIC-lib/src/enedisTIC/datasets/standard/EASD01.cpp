/* Corresponding header inclusion */
#include "EASD01.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   EASD01::LABEL("EASD01");
const size_t        EASD01::DATA_LENGTH(9);
const std::string   EASD01::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

EASD01::EASD01()
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
