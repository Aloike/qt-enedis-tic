#ifndef ABSTRACTDATASET_H
#define ABSTRACTDATASET_H

/* Inherited classes */
#include "../libEnedisTIC_global.h"

/* System includes */
#include <string>

/* Libraries includes */

/* Project includes */
#include "../utils.h"


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

class   LIBENEDISTIC_EXPORT AbstractDataset
{
public:

    /* Fixed data */
    std::string label(void) const;
    bool        hasTimestamp(void) const;
    size_t      dataLength(void) const;
    std::string unit(void) const;


    /* Interactions with transport layer */
    void        unpack(const std::string& pDatasetStr);
    std::string
        pack(
            const TIC::TeTICMode pTICMode=E_TIC_MODE_HISTORICAL) const;


    /* Varying data */
    std::string timestamp(void) const;
    void        setTimestamp(const std::string& pTimestampStr);

    std::string data(void) const;


    virtual std::string toJsonStr(void) const;



protected:

    AbstractDataset(
        const std::string&  pLabel,
        const bool          pHasTimestamp,
        const size_t&       pDataLength,
        const std::string&  pUnit=std::string() );


//    virtual void    load(const TIC::Transport::Dataset &pDataset);


    virtual std::string packData(void) const    = 0;
    virtual void        unpackData(const std::string& pData)    = 0;


    void    checkData(const std::string& pData);



private:



public:
protected:

    static const size_t C_TIMESTAMP_LENGTH;

    const size_t        m_dataLength;
    const bool          m_hasTimestamp;
    const std::string   m_label;
    const std::string   m_unit;

    std::string m_timestamp;



private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Dataset */
}   /*< namespace TIC */

#endif  /*< ABSTRACTDATASET_H */
