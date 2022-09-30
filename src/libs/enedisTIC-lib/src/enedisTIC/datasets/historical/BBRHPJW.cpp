/* Corresponding header inclusion */
#include "BBRHPJW.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   BBRHPJW::LABEL("BBRHPJW");
const size_t        BBRHPJW::DATA_LENGTH(9);
const std::string   BBRHPJW::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

BBRHPJW::BBRHPJW()
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
