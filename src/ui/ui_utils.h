#ifndef UI_UTILS_H
#define UI_UTILS_H


#include <QString>
class   QLabel;

#include "core/comm/protocol/tic/utils.h"


namespace Ui {

extern const QString    c_strNoDataTimestamp;

void    setLabel_fromDataset(
                const TIC::TDatasetPtr  &pDataset,
                QLabel                  *pLabelValuePtr,
                const uint&             pFieldWidth,
                QLabel                  *pLabelTimestampPtr=nullptr );


}   /*< namespace Ui */

#endif  /*< UI_UTILS_H */
