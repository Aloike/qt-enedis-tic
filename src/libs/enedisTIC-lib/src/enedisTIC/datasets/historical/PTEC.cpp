/* Corresponding header inclusion */
#include "PTEC.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   PTEC::LABEL("PTEC");
const size_t        PTEC::DATA_LENGTH(4);
const std::string   PTEC::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

PTEC::PTEC()
    :   GenericDataset(
            LABEL,
            false,
            DATA_LENGTH,
            E_DATA_TEXT,
            UNIT )
{
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
