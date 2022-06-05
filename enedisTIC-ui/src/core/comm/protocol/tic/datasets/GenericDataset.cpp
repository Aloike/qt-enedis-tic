/* Corresponding header inclusion */
#include "GenericDataset.h"

/* System includes */
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

GenericDataset::GenericDataset(
    const std::string&  pLabel,
    const bool          pHasTimestamp,
    const size_t&       pDataLength,
    const std::string&  pUnit )
    :   AbstractDataset(
            pLabel,
            pHasTimestamp,
            pDataLength,
            pUnit )
    ,   m_data()
{

}

/* ########################################################################## */
/* ########################################################################## */

std::string
GenericDataset::packData(void) const
{
    return this->m_data;
}

/* ########################################################################## */
/* ########################################################################## */

void
GenericDataset::setData(
    const std::string &pData
)
{
    this->checkData(pData);
    this->unpackData(pData);
}

/* ########################################################################## */
/* ########################################################################## */

std::string
    GenericDataset::toJsonStr() const
{
    std::string retval;


    retval  += "'GenericDataset': {";

    retval  += AbstractDataset::toJsonStr();

    retval  += ", ";
    retval  += "'data': '" + this->m_data + "'";

    retval  += "}";


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

void
GenericDataset::unpackData(
    const std::string &pData
)
{
    this->m_data    =   pData;
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC
