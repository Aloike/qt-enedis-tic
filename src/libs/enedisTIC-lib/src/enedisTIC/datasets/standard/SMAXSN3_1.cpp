/* Corresponding header inclusion */
#include "SMAXSN3_1.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   SMAXSN3_1::LABEL("SMAXSN3-1");
const size_t        SMAXSN3_1::DATA_LENGTH(5);
const std::string   SMAXSN3_1::UNIT("VA");

/* ########################################################################## */
/* ########################################################################## */

SMAXSN3_1::SMAXSN3_1()
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
