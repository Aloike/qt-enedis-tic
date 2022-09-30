/* Corresponding header inclusion */
#include "SMAXSN2_1.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   SMAXSN2_1::LABEL("SMAXSN2-1");
const size_t        SMAXSN2_1::DATA_LENGTH(5);
const std::string   SMAXSN2_1::UNIT("VA");

/* ########################################################################## */
/* ########################################################################## */

SMAXSN2_1::SMAXSN2_1()
    :   GenericDataset(
            LABEL,
            true,
            DATA_LENGTH,
            E_DATA_INTEGER,
            UNIT )
{
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
