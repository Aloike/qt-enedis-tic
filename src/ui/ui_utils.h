#ifndef UI_UTILS_H
#define UI_UTILS_H


#include <QString>
class   QLabel;

#include "core/comm/protocol/tic/utils.h"


namespace Ui {

extern const QString    c_strNoDataTimestamp;

void    setLabel_fromDatasetInt(
                const TIC::TDatasetPtr  &pDataset,
                QLabel                  *pLabelValuePtr,
                const uint&             pFieldWidth,
                QLabel                  *pLabelTimestampPtr=nullptr );

QString TICProfilJourToText(
                const QString&  pProfilStr );


}   /*< namespace Ui */

#endif  /*< UI_UTILS_H */
