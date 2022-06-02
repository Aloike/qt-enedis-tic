/* Corresponding header inclusion */
#include "HHPHC.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   HHPHC::LABEL("HHPHC");
const size_t        HHPHC::DATA_LENGTH(1);
const std::string   HHPHC::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

HHPHC::HHPHC()
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
