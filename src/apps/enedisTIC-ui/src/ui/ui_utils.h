#ifndef UI_UTILS_H
#define UI_UTILS_H


#include <QString>
class   QLabel;

#include <enedisTIC/utils.h>


namespace Ui {

extern const QString    c_strNoDataTimestamp;
extern const QString    c_strNoData2;
extern const QString    c_strNoData12;
extern const QString    c_strNoData14;
extern const QString    c_strNoData16;
extern const QString    c_strNoData32;

void    setLabel_fromDatasetInt(
                const TIC::TDatasetPtr  &pDataset,
                QLabel                  *pLabelValuePtr,
                const uint&             pFieldWidth,
                QLabel                  *pLabelTimestampPtr=nullptr );

QString TICProfilJourToText(
                const QString&  pProfilStr );


}   /*< namespace Ui */

#endif  /*< UI_UTILS_H */
