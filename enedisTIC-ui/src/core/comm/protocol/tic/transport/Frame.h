#ifndef FRAME_H
#define FRAME_H

/* Inherited classes */

/* System includes */
#include <list>
#include <string>

/* Libraries includes */

/* Project includes */



/* ########################################################################## */
/* ########################################################################## */

namespace   TIC {
namespace   Transport {

/* ########################################################################## */
/* ########################################################################## */

class   Frame
{
public:

    Frame(void);


    std::string pack(void) const;
    void        unpack(const std::string& pData);

    std::list<std::string>  datasets(void) const;



protected:
private:



public:
protected:
private:

    std::list<std::string>  m_datasets;

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Transport */
}   /*< namespace TIC */

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< FRAME_H */
