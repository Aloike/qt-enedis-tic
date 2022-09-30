/* Corresponding header inclusion */
#include "PMAX.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   PMAX::LABEL("PMAX");
const size_t        PMAX::DATA_LENGTH(5);
const std::string   PMAX::UNIT("W");

/* ########################################################################## */
/* ########################################################################## */

PMAX::PMAX()
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
