/* Corresponding header inclusion */
#include "AbstractDataset.h"

/* System includes */
#include <algorithm>
#include <stdexcept>

/* Libraries includes */

/* Project includes */
#include "enedisTIC/utils.h"


namespace TIC {
namespace Datasets {

/* ########################################################################## */
/* ########################################################################## */

const size_t    AbstractDataset::C_LABEL_LENGTH     = 8;
const size_t    AbstractDataset::C_TIMESTAMP_LENGTH = 13;

/* ########################################################################## */
/* ########################################################################## */

AbstractDataset::AbstractDataset(
    const std::string&  pLabel,
    const bool          pHasTimestamp,
    const size_t&       pDataLength,
    const std::string&  pUnit   )
    :   m_dataLength(pDataLength)
    ,   m_hasTimestamp(pHasTimestamp)
    ,   m_label(pLabel)
    ,   m_unit( pUnit )
    ,   m_timestamp()
{
    /* Check the given label is valid */
    if(     pLabel.empty()
        ||  pLabel.length() > 8 )
    {
        throw std::out_of_range(
            "pLabel must have a length of 1 to 8 chars!"
            " (pLabel='" + pLabel + "')"
        );
    }
}

/* ########################################################################## */
/* ########################################################################## */

void
AbstractDataset::checkData(const std::string &pData)
{
    if( pData.length() != this->dataLength() )
    {
        throw std::invalid_argument(
            "Invalid data string length!"
            " (expected length of "
            + std::to_string(this->dataLength())
            + ", got " + std::to_string(pData.length())
            + ")"
        );
    }

    /* Check the content of the data section of the dataset */
    const auto c_charsValidRange_lambda = [](char i) {
        return (i >= 0x20 && i <= 0x7E);
    };
    if( ! std::all_of(pData.begin(), pData.end(), c_charsValidRange_lambda) )
    {
        throw std::out_of_range(
            "data must only contain ASCII chars between 0x20 and 0x7E!"
            " (got '" + pData + "')"
        );
    }
}

/* ########################################################################## */
/* ########################################################################## */

std::string
    AbstractDataset::data(void) const
{
    return this->packData();
}

/* ########################################################################## */
/* ########################################################################## */

size_t
    AbstractDataset::dataLength() const
{
    return this->m_dataLength;
}

/* ########################################################################## */
/* ########################################################################## */

std::string
    AbstractDataset::extractLabel(
        const std::string &pDatasetStr
    )
{
    TeTICMode lLinkyMode  = dataset_getType(pDatasetStr);
    char        lSpacingChar    = dataset_spacingChar( lLinkyMode );

    /* Check label length */
    size_t lIdxLabelEnd    = pDatasetStr.find(
        lSpacingChar,
        C_CHARIDX_LABELSTART
    );
    if( lIdxLabelEnd == std::string::npos )
    {
        throw std::runtime_error(
            "In " + std::string(__PRETTY_FUNCTION__) + ": "
            + "Unable to find spacing char separator after label!"
            " (from data '" + pDatasetStr + "')"
        );
    }
    if( lIdxLabelEnd > (C_CHARIDX_LABELSTART + C_LABEL_LENGTH) )
    {
        throw std::runtime_error(
            "In " + std::string(__PRETTY_FUNCTION__) + ": "
            + "Invalid label length!"
            " (expected length of less than "
            + std::to_string(C_LABEL_LENGTH)
            + ", got "
            + std::to_string(lIdxLabelEnd - C_CHARIDX_LABELSTART)
            + " from data '" + pDatasetStr + "')"
        );
    }

    /* Extract the label */
    std::string retval  = pDatasetStr.substr(
            C_CHARIDX_LABELSTART,
            lIdxLabelEnd - C_CHARIDX_LABELSTART
    );

#ifdef  TRACE_DEBUG
    std::cout
        <<  __FILE__ << " +" << __LINE__ << " \t"
        <<  "retval: '" + retval + "'"
        << std::endl;
#endif
    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

bool
AbstractDataset::hasTimestamp(void) const
{
    return this->m_hasTimestamp;
}

/* ########################################################################## */
/* ########################################################################## */

std::string
    AbstractDataset::label(void) const
{
    return this->m_label;
}

/* ########################################################################## */
/* ########################################################################## */

std::string
AbstractDataset::pack(const TeTICMode pTICMode) const
{
    const char c_spacingChar
        =   pTICMode==E_TIC_MODE_STANDARD
            ?   TIC::CHAR_HT
            :   TIC::CHAR_SP;

    std::string lPayload;
    lPayload  += this->label();
    if( this->hasTimestamp() == true )
    {
        lPayload  += c_spacingChar;
        lPayload  += this->timestamp();
    }
    lPayload  += c_spacingChar;
    lPayload  += this->data();
    lPayload  += c_spacingChar;

    unsigned char   lChecksum   = TIC::calculateChecksum( lPayload );

    std::string retval;
    retval  =   CHAR_LF;
    retval  +=  lPayload;
    retval  +=  lChecksum;
    retval  +=  CHAR_CR;

    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

void
    AbstractDataset::setTimestamp(const std::string& pTimestampStr)
{
    if( pTimestampStr.length() != C_TIMESTAMP_LENGTH )
    {
        throw std::out_of_range(
            "Invalid timestamp length!"
            " (expected " + std::to_string(C_TIMESTAMP_LENGTH)
            + ", got " + std::to_string( pTimestampStr.length() )
            + ", data: '" + pTimestampStr + "')"
        );
    }

    switch( pTimestampStr[0] )
    {
        case 'E':
        case 'e':
        case 'H':
        case 'h':
            break;

        default:
            throw std::out_of_range(
                "pTimestampStr has invalid season char!"
            );
            break;
    }


    this->m_timestamp   = pTimestampStr;
}

/* ########################################################################## */
/* ########################################################################## */

std::string
    AbstractDataset::timestamp() const
{
    return this->m_timestamp;
}

/* ########################################################################## */
/* ########################################################################## */

std::string
    AbstractDataset::toJsonStr(void) const
{
    std::string retval  = "'AbstractDataset': {";


    retval  +=  "'label': '" + this->label() + "'";

    retval  +=  ", ";
    retval  +=  "'hasTimestamp': '"+std::to_string(this->hasTimestamp())+"'";

    if( this->hasTimestamp() )
    {
        retval  +=  ", ";
        retval  +=  "'timestamp': '" + this->timestamp() + "'";
    }

//    retval  +=  ", ";
//    retval  +=  "'data': '" + this->data() + "'";

    retval  +=  ", ";
    retval  +=  "'dataLength': '" + std::to_string(this->dataLength()) + "'";

    retval  +=  ", ";
    retval  +=  "'unit': '" + this->unit() + "'";


    retval  +=  "}";
    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

std::string
    AbstractDataset::unit() const
{
    return this->m_unit;
}

/* ########################################################################## */
/* ########################################################################## */

void
    AbstractDataset::unpack(const std::string& pDatasetStr)
{
    TeTICMode lLinkyMode  = dataset_getType(pDatasetStr);

    char        lSpacingChar    = dataset_spacingChar( lLinkyMode );


    /*
     *  Check pre-conditions
     */
    /* Verify start of dataset char */
    if( pDatasetStr[0] != TIC::CHAR_LF )
    {
        throw std::runtime_error("pData doesn't start with LF!");
    }


    /* Check label length */
    size_t lIdxLabelEnd    = pDatasetStr.find(
        lSpacingChar,
        C_CHARIDX_LABELSTART
    );
    if(     lIdxLabelEnd > (C_CHARIDX_LABELSTART + C_LABEL_LENGTH)
        ||  lIdxLabelEnd == std::string::npos )
    {
        throw std::runtime_error(
            "Invalid label length!"
            " (expected length of less than "
            + std::to_string(C_LABEL_LENGTH)
            + ", got "
            + std::to_string(lIdxLabelEnd - C_CHARIDX_LABELSTART)
            + " from data '" + pDatasetStr + "')"
        );
    }


    /* Check how many horizontal tabs are in the dataset string */
    size_t lCountHT = std::count(
        pDatasetStr.begin(),
        pDatasetStr.end(),
        lSpacingChar
    );
    if(     (   this->hasTimestamp()    &&  lCountHT    !=  3   )
        ||  ( ! this->hasTimestamp()    &&  lCountHT    !=  2   ) )
    {
        throw std::runtime_error("pData doesn't have the right amount of spacing chars!");
    }

//    if( pData[pData.length() -1] != TIC::CHAR_CR )
//    {
//        throw std::runtime_error("pData doesn't end with CR!");
//    }


    /*
     *  Processing
     */

    /* Extract the label */
    std::string lLabelStr   = TIC::Datasets::AbstractDataset::extractLabel(
        pDatasetStr
    );

    if( lLabelStr != this->label() )
    {
        throw std::runtime_error(
            "Invalid label in given data!"
            " (expected '" + this->label() + "', got '" + lLabelStr + "').");

    }
    size_t lIdxDataBegin    = lIdxLabelEnd;
    size_t lIdxDataEnd      = pDatasetStr.find(
        lSpacingChar,
        lIdxDataBegin + 1
    );


    /* Extract the timestamp */
    if( this->hasTimestamp() )
    {
        this->setTimestamp( pDatasetStr.substr(
                lIdxDataBegin + 1,
                lIdxDataEnd - (lIdxDataBegin+1)
            )
        );

        /* Find next occurence of HT as the first one is between the label and
         * the timestamp. */
        lIdxDataBegin   = lIdxDataEnd;
        lIdxDataEnd
            = pDatasetStr.find(
                lSpacingChar,
                lIdxDataBegin + 1
            );
    }


    /* Extract the data */
    std::string lDataStr
        = pDatasetStr.substr(
            lIdxDataBegin+1,
            lIdxDataEnd - (lIdxDataBegin+1)
        );

    /* Check the data validity */
    this->checkData( lDataStr );

    /* Forward the data to the pure virtual method that will unpack it in the
     * concrete implementation. */
    this->unpackData( lDataStr );
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Dataset */
}   /*< namespace TIC */
