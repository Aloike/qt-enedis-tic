/* Corresponding header inclusion */
#include "FrameBuffer.h"

/* System includes */
#include <algorithm>
#include <stdexcept>

/* Libraries includes */

/* Project includes */
#include "transport/Frame.h"


namespace TIC {

/* ########################################################################## */
/* ########################################################################## */

FrameBuffer::FrameBuffer()
{

}

/* ########################################################################## */
/* ########################################################################## */

void
    FrameBuffer::append(const char pData)
{
    std::string lString;

    lString += pData;

    this->append( lString );
}

/* ########################################################################## */
/* ########################################################################## */

void
    FrameBuffer::append(const std::string &pData)
{
    this->m_inputBuffer += pData;

    this->processBuffer();
}

/* ########################################################################## */
/* ########################################################################## */

size_t
    FrameBuffer::framesCount() const
{
    return this->m_framesList.size();
}

/* ########################################################################## */
/* ########################################################################## */

bool
    FrameBuffer::hasFrames() const
{
    return( this->m_framesList.empty() != true );
}

/* ########################################################################## */
/* ########################################################################## */

std::string
    FrameBuffer::popOne()
{
    std::string retval;

    if( this->m_framesList.empty() )
    {
        throw std::logic_error("No frame available in the buffer!");
    }
    else
    {
        retval  = this->m_framesList.front();
        this->m_framesList.pop_front();
    }

    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

void
    FrameBuffer::processBuffer(void)
{
    /* Look for an End Of Frame */
    auto lIdxEOF    = this->m_inputBuffer.find(
        TIC::Transport::Frame::END_OF_FRAME
    );

    /* Look for a Start Of Frame before the End Of Frame */
    auto lIdxSOF    = this->m_inputBuffer.rfind(
        TIC::Transport::Frame::START_OF_FRAME,
        lIdxEOF
    );


    if( lIdxEOF != std::string::npos )
    {
        if( lIdxSOF == std::string::npos )
        {
            /* If there's an EOF without the corresponding SOF,
             * discard data up to the EOF included. */
             this->m_inputBuffer.erase(
                0,
                lIdxEOF + 1
            );
        }
        else
        {
            /* If a frame has been found, extract it,
             * and remove everything up to the EOF included. */
            this->m_framesList.push_back(
                this->m_inputBuffer.substr(
                    lIdxSOF,
                    lIdxEOF - lIdxSOF + 1
                )
            );

             this->m_inputBuffer.erase(0, lIdxEOF + 1);
        }

        /* Continue processing the buffer as there might be some more frames */
         this->processBuffer();
    }
    else /* There's no End Of Frame */
    {
        /* look for a start of frame */
        lIdxSOF    = this->m_inputBuffer.find(
            TIC::Transport::Frame::START_OF_FRAME
        );

        /* Remove everything before the start of frame if it exists,
         * otherwise delete the whole buffer. */
        this->m_inputBuffer.erase(0, lIdxSOF);
    }
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace TIC */
