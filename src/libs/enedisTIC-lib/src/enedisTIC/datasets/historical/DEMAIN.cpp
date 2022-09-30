/* Corresponding header inclusion */
#include "DEMAIN.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   DEMAIN::LABEL("DEMAIN");
const size_t        DEMAIN::DATA_LENGTH(4);
const std::string   DEMAIN::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

DEMAIN::DEMAIN()
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
