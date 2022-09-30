/* Corresponding header inclusion */
#include "PRM.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   PRM::LABEL("PRM");
const size_t        PRM::DATA_LENGTH(14);
const std::string   PRM::UNIT("");

/* ########################################################################## */
/* ########################################################################## */

PRM::PRM()
    :   GenericDataset(
            LABEL,
            false,
            DATA_LENGTH,
            E_DATA_INTEGER,
            UNIT )
{
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
