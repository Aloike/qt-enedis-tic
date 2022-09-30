/* Corresponding header inclusion */
#include "ISOUSC.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   ISOUSC::LABEL("ISOUSC");
const size_t        ISOUSC::DATA_LENGTH(2);
const std::string   ISOUSC::UNIT("A");

/* ########################################################################## */
/* ########################################################################## */

ISOUSC::ISOUSC()
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
