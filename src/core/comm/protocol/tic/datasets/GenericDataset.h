#ifndef GENERICDATASET_H
#define GENERICDATASET_H

/* Inherited classes */
#include "AbstractDataset.h"

/* System includes */

/* Libraries includes */

/* Project includes */


namespace TIC {
namespace Datasets {


/* ########################################################################## */
/* ########################################################################## */

class   GenericDataset
        :   public  TIC::Datasets::AbstractDataset
{
public:

    GenericDataset(
            const std::string&  pLabel,
            const bool          pHasTimestamp,
            const size_t&       pDataLength,
            const std::string&  pUnit=std::string() );


    virtual std::string toJsonStr(void) const;


    void    setData(const std::string& pData);



protected:

    virtual std::string packData(void) const;
    virtual void        unpackData(const std::string &pData);



private:



public:
protected:

    std::string m_data;



private:

};

/* ########################################################################## */
/* ########################################################################## */

} // namespace Datasets
} // namespace TIC

#endif  /*< GENERICDATASET_H */
