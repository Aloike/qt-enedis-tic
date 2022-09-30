/* Corresponding header inclusion */
#include "MOTDETAT.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   MOTDETAT::LABEL("MOTDETAT");
const size_t        MOTDETAT::DATA_LENGTH(6);
const std::string   MOTDETAT::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

MOTDETAT::MOTDETAT()
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
