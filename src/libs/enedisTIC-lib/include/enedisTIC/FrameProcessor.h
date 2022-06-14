#ifndef FRAMEPROCESSOR_H
#define FRAMEPROCESSOR_H

/* Inherited classes */
#include "libEnedisTIC_global.h"

/* System includes */
#include <list>
#include <memory>
#include <string>

/* Libraries includes */

/* Project includes */
#include "datasets/AbstractDataset.h"
#include "utils.h"


/* ########################################################################## */
/* ########################################################################## */

namespace   TIC {

/* ########################################################################## */
/* ########################################################################## */

class   LIBENEDISTIC_EXPORT FrameProcessor
{
public:

    FrameProcessor(void);


    TDatasetsPtrList
            decode(const std::string   pData);



protected:
private:



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace TIC */

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< FRAMEPROCESSOR_H */
