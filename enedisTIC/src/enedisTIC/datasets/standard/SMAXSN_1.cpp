/* Corresponding header inclusion */
#include "SMAXSN_1.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   SMAXSN_1::LABEL("SMAXSN-1");
const size_t        SMAXSN_1::DATA_LENGTH(5);
const std::string   SMAXSN_1::UNIT("VA");

/* ########################################################################## */
/* ########################################################################## */

SMAXSN_1::SMAXSN_1()
    :   GenericDataset(
            LABEL,
            true,
            DATA_LENGTH )
{
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
