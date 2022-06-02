/* Corresponding header inclusion */
#include "utils.h"

/* System includes */
#include <iostream>
#include <stdexcept>

/* Libraries includes */

/* Project includes */


namespace TIC {

/* ########################################################################## */
/* ########################################################################## */

const char  CHAR_STX    = 0x02;
const char  CHAR_ETX    = 0x03;

const char  CHAR_CR = 0x0D;
const char  CHAR_LF = 0x0A;
const char  CHAR_HT = 0x09;
const char  CHAR_SP = 0x20;

//const size_t    C_DATASET_IDX_LABELSTART    = 1;
const size_t C_DATASET_LABEL_LENGTH = 8;

/* ########################################################################## */
/* ########################################################################## */

unsigned char
    calculateChecksum(const std::string &pPayload)
{
    unsigned char retval = 0x00;

    /* Sum all chars of the payload */
    for( size_t i = 0 ; i < pPayload.length() ; ++i )
    {
        retval  += pPayload[ i ];
    }

    /* Truncate the sum over 6 bits */
    retval  &= 0x3F;

    /* Get the resulting char */
    retval  += 0x20;

    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

TeTICMode
    dataset_getType(
        const std::string &pDatasetStr
    )
{
    TeTICMode retval  = E_TIC_MODE_HISTORICAL;

    if( pDatasetStr.find( TIC::CHAR_HT ) != std::string::npos )
    {
        retval  = E_TIC_MODE_STANDARD;
    }
    else if( pDatasetStr.find( TIC::CHAR_SP ) != std::string::npos )
    {
        retval  = E_TIC_MODE_HISTORICAL;
    }
    else
    {
        throw   std::runtime_error(
            "In " + std::string(__PRETTY_FUNCTION__) + ": "
            + "Unable to determine TIC type of frame '" + pDatasetStr + "'!"
        );
    }

    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

char    dataset_spacingChar(const TeTICMode pMode)
{
    char    retval  = 0x00;


    switch( pMode )
    {
        case E_TIC_MODE_HISTORICAL:
            retval  = TIC::CHAR_SP;
            break;

        case E_TIC_MODE_STANDARD:
            retval  = TIC::CHAR_HT;
            break;

        default:
            std::logic_error(
                "Unknown value for pMode (" + std::to_string(pMode) + ")."
            );
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

std::string
extractLabel(const std::string &pDatasetStr )
{
    TeTICMode lLinkyMode  = dataset_getType(pDatasetStr);
    char        lSpacingChar    = dataset_spacingChar( lLinkyMode );

    /* Check label length */
    size_t lIdxLabelEnd    = pDatasetStr.find(
        lSpacingChar,
        C_DATASET_IDX_LABELSTART
    );
    if( lIdxLabelEnd == std::string::npos )
    {
        throw std::runtime_error(
            "In " + std::string(__PRETTY_FUNCTION__) + ": "
            + "Unable to find spacing char separator after label!"
            " (from data '" + pDatasetStr + "')"
        );
    }
    if( lIdxLabelEnd > (C_DATASET_IDX_LABELSTART + C_DATASET_LABEL_LENGTH) )
    {
        throw std::runtime_error(
            "In " + std::string(__PRETTY_FUNCTION__) + ": "
            + "Invalid label length!"
            " (expected length of less than "
            + std::to_string(C_DATASET_LABEL_LENGTH)
            + ", got "
            + std::to_string(lIdxLabelEnd - C_DATASET_IDX_LABELSTART)
            + " from data '" + pDatasetStr + "')"
        );
    }

    /* Extract the label */
    std::string retval  = pDatasetStr.substr(
            C_DATASET_IDX_LABELSTART,
            lIdxLabelEnd - C_DATASET_IDX_LABELSTART
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

}   /*< namespace TIC */
