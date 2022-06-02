#ifndef FRAMEPROCESSOR_H
#define FRAMEPROCESSOR_H

/* Inherited classes */

/* System includes */
#include <list>
#include <memory>
#include <string>

/* Libraries includes */

/* Project includes */
#include "datasets/AbstractDataset.h"
#include "TDatasetsList.h"
#include "utils.h"


/* ########################################################################## */
/* ########################################################################## */

namespace   TIC {

/* ########################################################################## */
/* ########################################################################## */

class   FrameProcessor
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
