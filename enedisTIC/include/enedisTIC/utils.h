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

//extern const size_t    C_DATASET_IDX_LABELSTART;

/* <LF> <--LABEL--> [<HT> <--TIMESTAMP-->] <HT> <-- DATA --> <HT> <--CS--> <CR>
 * + LABEL
 *   + is strictly 8 chars long.
 * + Timestamp:
 *   + Not always available.
 *   + 13 chars long.
 *   + Format: [SAAMMJJhhmmss]
 * + DATA
 *   + length is variable.
 * + CS / checksum
 *   + 1 char long.
 */
enum EDatasetCharIndex {
    C_DATASET_IDX_LF                = 0,
    C_DATASET_IDX_LABELSTART        = 1,
    C_DATASET_IDX_LABELEND          = 8,
    C_DATASET_IDX_HT_LT             = 9,
    C_DATASET_IDX_TIMESTAMPSTART    = 10,
    C_DATASET_IDX_TIMESTAMPEND      = 22,
};

extern const size_t C_DATASET_LABEL_LENGTH;

typedef enum    ETICMode   {
    E_TIC_MODE_HISTORICAL,
    E_TIC_MODE_STANDARD
}   TeTICMode;


typedef std::shared_ptr<Datasets::AbstractDataset>  TDatasetPtr;
typedef std::list<TDatasetPtr>                      TDatasetsPtrList;


unsigned char   calculateChecksum(const std::string& pPayload);

std::string     extractLabel(const std::string&  pDatasetStr);

TeTICMode       dataset_getType(const std::string& pDatasetStr);
char            dataset_spacingChar(
                    const TeTICMode pMode=E_TIC_MODE_HISTORICAL );

}

#endif  /*< TIC_UTILS_H */
