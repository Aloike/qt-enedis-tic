/* Corresponding header inclusion */
#include "SMAXSN1.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   SMAXSN1::LABEL("SMAXSN1");
const size_t        SMAXSN1::DATA_LENGTH(5);
const std::string   SMAXSN1::UNIT("VA");

/* ########################################################################## */
/* ########################################################################## */

SMAXSN1::SMAXSN1()
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
