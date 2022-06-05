/* Corresponding header inclusion */
#include "BBRHCJR.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   BBRHCJR::LABEL("BBRHCJR");
const size_t        BBRHCJR::DATA_LENGTH(9);
const std::string   BBRHCJR::UNIT("Wh");

/* ########################################################################## */
/* ########################################################################## */

BBRHCJR::BBRHCJR()
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
