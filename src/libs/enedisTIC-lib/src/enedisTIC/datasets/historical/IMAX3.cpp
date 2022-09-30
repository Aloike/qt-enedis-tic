/* Corresponding header inclusion */
#include "IMAX3.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   IMAX3::LABEL("IMAX3");
const size_t        IMAX3::DATA_LENGTH(3);
const std::string   IMAX3::UNIT("A");

/* ########################################################################## */
/* ########################################################################## */

IMAX3::IMAX3()
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
