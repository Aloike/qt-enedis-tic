/* Corresponding header inclusion */
#include "Frame.h"

/* System includes */
#include <iostream>
#include <stdexcept>

/* Libraries includes */

/* Project includes */
#include "../utils.h"

/* ########################################################################## */
/* ########################################################################## */

namespace   TIC {
namespace   Transport {

const char  Frame::START_OF_FRAME   = TIC::CHAR_STX;
const char  Frame::END_OF_FRAME     = TIC::CHAR_ETX;

/* ########################################################################## */
/* ########################################################################## */

Frame::Frame(void)
{

}

/* ########################################################################## */
/* ########################################################################## */

std::list<std::string>  Frame::datasets(void) const
{
    return this->m_datasets;
}

/* ########################################################################## */
/* ########################################################################## */

std::string
    Frame::pack(void) const
{
    std::string retval;

    retval  += START_OF_FRAME;

    retval  += END_OF_FRAME;

    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

void
    Frame::unpack(const std::string& pData)
{
    /*
     *  Check pre-conditions
     */
    if( pData[0] != START_OF_FRAME )
    {
        throw std::runtime_error("pData doesn't start with a Start Of Frame!");
    }

    if( pData[pData.length() - 1] != END_OF_FRAME )
    {
        throw std::runtime_error("pData doesn't end with an End Of Frame!");
    }

    /*
     *  Processing
     */

    size_t      lPosDatasetStart    = 0;
    size_t      lPosDatasetEnd      = 0;
    size_t      lPosDatasetSearchFrom   = 0;
    std::string lDatasetStr;
    while(  (lPosDatasetStart = pData.find(TIC::CHAR_LF, lPosDatasetSearchFrom))
            !=  std::string::npos )
    {
//        std::cout << "----------" << std::endl;
//        std::cout << "lPosDatasetStart:" << lPosDatasetStart << std::endl << std::flush;

        /* Find the end of the dataset */
        lPosDatasetEnd  = pData.find(
            TIC::CHAR_CR,
            lPosDatasetStart+1
        );
//        std::cout << "lPosDatasetEnd:" << lPosDatasetEnd << std::endl << std::flush;

        if( lPosDatasetEnd == std::string::npos )
        {
            throw std::runtime_error("pData contains an incomplete dataset!");
        }


        /* Extract the dataset */
        lDatasetStr = pData.substr(
            lPosDatasetStart,
            lPosDatasetEnd - lPosDatasetStart
        );

//        std::cout << "Dataset str:" << lDatasetStr << std::endl << std::flush;
        this->m_datasets.push_back( lDatasetStr );


//        throw std::logic_error("Unimplemented method!");
//        #warning TODO: Use a factory to create datasets based on their type?

        lPosDatasetSearchFrom   = lPosDatasetEnd + 1;
//        std::cout << "----------" << std::endl;
    }
//    std::cout << s << std::endl;
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Transport */
}   /*< namespace TIC */

/* ########################################################################## */
/* ########################################################################## */
