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

}   /*< namespace TIC */
