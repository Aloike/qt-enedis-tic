/* Corresponding header inclusion */
#include "BBRHCJW.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   BBRHCJW::LABEL("BBRHCJW");
const size_t        BBRHCJW::DATA_LENGTH(9);
const std::string   BBRHCJW::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

BBRHCJW::BBRHCJW()
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
