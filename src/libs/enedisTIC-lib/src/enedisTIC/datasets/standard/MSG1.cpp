/* Corresponding header inclusion */
#include "MSG1.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   MSG1::LABEL("MSG1");
const size_t        MSG1::DATA_LENGTH(32);
const std::string   MSG1::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

MSG1::MSG1()
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
