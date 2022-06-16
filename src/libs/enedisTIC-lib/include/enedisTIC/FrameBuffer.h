#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

/* Inherited classes */

/* System includes */
#include <list>
#include <string>

/* Libraries includes */

/* Project includes */


namespace TIC {


/* ########################################################################## */
/* ########################################################################## */

class   FrameBuffer
{

public:

    FrameBuffer();
    FrameBuffer(const FrameBuffer&) = delete;
    FrameBuffer& operator=(const FrameBuffer&)  = delete;


    void    append(const char   pData);
    void    append(const std::string& pData);

    bool        hasFrames(void) const;
    size_t      framesCount(void) const;
    std::string popOne(void);



protected:
private:

    void    processBuffer(void);



public:
protected:
private:

    std::list<std::string>  m_framesList;
    std::string             m_inputBuffer;

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace TIC */

#endif  /*< FRAMEBUFFER_H */
