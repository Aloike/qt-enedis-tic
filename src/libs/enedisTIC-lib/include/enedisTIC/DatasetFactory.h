#ifndef DATASETFACTORY_H
#define DATASETFACTORY_H

/* Inherited classes */
#include "libEnedisTIC_global.h"

/* System includes */
#include <memory>

/* Libraries includes */

/* Project includes */
#include "datasets/AbstractDataset.h"


namespace TIC {


/* ########################################################################## */
/* ########################################################################## */

class   LIBENEDISTIC_EXPORT DatasetFactory
{
public:

    DatasetFactory(void);


    std::shared_ptr<TIC::Datasets::AbstractDataset>
        createDataset(
            const std::string& pDatasetStr
        ) const;



protected:
private:



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

} // namespace TIC

#endif  /*< DATASETFACTORY_H */
