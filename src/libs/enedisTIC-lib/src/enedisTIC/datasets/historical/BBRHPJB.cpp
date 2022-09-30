/* Corresponding header inclusion */
#include "BBRHPJB.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   BBRHPJB::LABEL("BBRHPJB");
const size_t        BBRHPJB::DATA_LENGTH(9);
const std::string   BBRHPJB::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

BBRHPJB::BBRHPJB()
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
