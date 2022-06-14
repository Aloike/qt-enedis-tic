/* Corresponding header inclusion */
#include "FrameProcessor.h"

/* System includes */
#include <iostream>
#include <stdexcept>

/* Libraries includes */

/* Project includes */
#include "transport/Frame.h"
#include "DatasetFactory.h"


/* ########################################################################## */
/* ########################################################################## */

namespace   TIC {

/* ########################################################################## */
/* ########################################################################## */

FrameProcessor::FrameProcessor(void)
{

}

/* ########################################################################## */
/* ########################################################################## */

TDatasetsPtrList
    FrameProcessor::decode(
        const std::string pData
    )
{
    /* Check conditions on inputs */
    if( pData.empty() == true)
    {
        throw std::invalid_argument(
            "In " + std::string(__PRETTY_FUNCTION__) + ": "
            + "Input data can't be empty!"
        );
    }


    /* Unpack the transport layer */
    Transport::Frame lFrame;
    lFrame.unpack( pData );


    /* Create datasets from the content of the frame */
    DatasetFactory lFactory;
    std::list<std::shared_ptr<Datasets::AbstractDataset>>   retval;
    for( auto const& lRawDataset : lFrame.datasets() )
    {
#ifdef  TRACE_DEBUG
        std::cout
            <<  __FILE__ << " +" << __LINE__ << " \t"
            <<  "Decoding: " << lRawDataset
            <<  std::endl;
#endif

        auto lDataset   = lFactory.createDataset( lRawDataset );

#ifdef  TRACE_DEBUG
        std::cout
            <<  __FILE__ << " +" << __LINE__ << " \t"
            <<  "Decoded: "
            << lDataset.get()->toJsonStr()
            << std::endl;
#endif

        retval.push_back(lDataset);
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace TIC */

/* ########################################################################## */
/* ########################################################################## */
