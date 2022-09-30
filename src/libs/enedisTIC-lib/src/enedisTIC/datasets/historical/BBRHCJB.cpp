/* Corresponding header inclusion */
#include "BBRHCJB.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   BBRHCJB::LABEL("BBRHCJB");
const size_t        BBRHCJB::DATA_LENGTH(9);
const std::string   BBRHCJB::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

BBRHCJB::BBRHCJB()
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
