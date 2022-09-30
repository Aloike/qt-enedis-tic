/* Corresponding header inclusion */
#include "BBRHPJR.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   BBRHPJR::LABEL("BBRHPJR");
const size_t        BBRHPJR::DATA_LENGTH(9);
const std::string   BBRHPJR::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

BBRHPJR::BBRHPJR()
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
