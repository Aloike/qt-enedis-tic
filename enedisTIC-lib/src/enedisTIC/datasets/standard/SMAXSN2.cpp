/* Corresponding header inclusion */
#include "SMAXSN2.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   SMAXSN2::LABEL("SMAXSN2");
const size_t        SMAXSN2::DATA_LENGTH(5);
const std::string   SMAXSN2::UNIT("VA");

/* ########################################################################## */
/* ########################################################################## */

SMAXSN2::SMAXSN2()
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
