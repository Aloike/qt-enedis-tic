/* Corresponding header inclusion */
#include "SMAXSN1_1.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   SMAXSN1_1::LABEL("SMAXSN1-1");
const size_t        SMAXSN1_1::DATA_LENGTH(5);
const std::string   SMAXSN1_1::UNIT("VA");

/* ########################################################################## */
/* ########################################################################## */

SMAXSN1_1::SMAXSN1_1()
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
