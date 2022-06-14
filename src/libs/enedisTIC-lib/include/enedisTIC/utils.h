#ifndef TIC_UTILS_H
#define TIC_UTILS_H

#include <list>
#include <memory>
#include <string>

namespace TIC::Datasets {
class   AbstractDataset;
}


namespace TIC {

extern const char   CHAR_STX;
extern const char   CHAR_ETX;

extern const char   CHAR_CR;
extern const char   CHAR_LF;
extern const char   CHAR_HT;
extern const char   CHAR_SP;

typedef enum    ETICMode   {
    E_TIC_MODE_HISTORICAL,
    E_TIC_MODE_STANDARD
}   TeTICMode;


typedef std::shared_ptr<Datasets::AbstractDataset>  TDatasetPtr;
typedef std::list<TDatasetPtr>                      TDatasetsPtrList;


unsigned char   calculateChecksum(const std::string& pPayload);

TeTICMode       dataset_getType(const std::string& pDatasetStr);
char            dataset_spacingChar(
                    const TeTICMode pMode=E_TIC_MODE_HISTORICAL );

}

#endif  /*< TIC_UTILS_H */
