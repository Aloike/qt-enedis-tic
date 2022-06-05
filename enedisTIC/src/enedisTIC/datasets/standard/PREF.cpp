/* Corresponding header inclusion */
#include "PREF.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const std::string   PREF::LABEL("PREF");
const size_t        PREF::DATA_LENGTH(2);
const std::string   PREF::UNIT("kVA");

/* ########################################################################## */
/* ########################################################################## */

PREF::PREF()
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
