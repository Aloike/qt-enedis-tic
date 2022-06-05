/* Corresponding header inclusion */
#include "SMAXSN3.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   SMAXSN3::LABEL("SMAXSN3");
const size_t        SMAXSN3::DATA_LENGTH(5);
const std::string   SMAXSN3::UNIT("VA");

/* ########################################################################## */
/* ########################################################################## */

SMAXSN3::SMAXSN3()
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
