#include "ui_utils.h"

#include <QLabel>

#include "core/comm/protocol/tic/datasets/AbstractDataset.h"


/* ########################################################################## */
/* ########################################################################## */
/*
 *  Trace macros
 */
#include "core/trace.h"

#if defined  QT_DEBUG
#   if defined D_TRACE_ENABLE_DBGLOW
#       define  TRACE_DBGLOW(format,...)                                       \
                TRACE_DBG_BASE( format, ##__VA_ARGS__ );
#   else
#       define  TRACE_DBGLOW(format,...)
#   endif

#   define TRACE_DBG(format,...)                                               \
           TRACE_DBG_BASE( format, ##__VA_ARGS__ );
#else
#   define  TRACE_DBG(format,...)
#   define  TRACE_DBGLOW(format,...)
#endif

#define TRACE_INFO(format,...)                                                 \
        TRACE_INFO_BASE( format, ##__VA_ARGS__ );

#define TRACE_WARN(format,...)                                                 \
        TRACE_WARN_BASE( format, ##__VA_ARGS__ );

#define TRACE_ERR(format,...)                                                  \
        TRACE_ERR_BASE( format, ##__VA_ARGS__ );

/* ########################################################################## */
/* ########################################################################## */

namespace Ui {


const QString   c_strNoDataTimestamp("@ --/--/---- --:--:-- (-)");


void    setLabel_fromDataset(
                const TIC::TDatasetPtr  &pDataset,
                QLabel                  *pLabelValuePtr,
                const uint&             pFieldWidth,
                QLabel                  *pLabelTimestampPtr )
{
    pLabelValuePtr->setText(
        QString::asprintf(
            "%*d%s%s",
            pFieldWidth,
            QString::fromStdString(pDataset->data()).toInt(),
            pDataset->unit().empty()? "" : " ",
            pDataset->unit().c_str()
        )
    );


    if(pLabelTimestampPtr == nullptr)
    {
        /* Nothing to do */
    }
    else if( pDataset->timestamp().length() != 13 )
    {
        TRACE_ERR(
            "Invalid timestamp length of %ld! ('%s')",
            pDataset->timestamp().length(),
            pDataset->timestamp().c_str()
        );

        pLabelTimestampPtr->setText(c_strNoDataTimestamp);
    }
    else
    {
        QString lTimestampInputStr
            = QString::fromStdString(pDataset->timestamp());
        QString lTimestampOutputStr = "@ ";


        /* Extract day, month, year */
        lTimestampOutputStr   += lTimestampInputStr.mid( 5, 2 );
        lTimestampOutputStr   += "/";
        lTimestampOutputStr   += lTimestampInputStr.mid( 3, 2 );
        lTimestampOutputStr   += "/";
        lTimestampOutputStr   += "20" + lTimestampInputStr.mid( 1, 2 );
        lTimestampOutputStr   += " ";

        /* Extract time */
        lTimestampOutputStr   += lTimestampInputStr.mid( 7, 2 );
        lTimestampOutputStr   += ":";
        lTimestampOutputStr   += lTimestampInputStr.mid( 9, 2 );
        lTimestampOutputStr   += ":";
        lTimestampOutputStr   += lTimestampInputStr.mid( 11, 2 );
        lTimestampOutputStr   += " ";
        lTimestampOutputStr   += "(" + lTimestampInputStr.mid( 0, 1 ) + ")";

        pLabelTimestampPtr->setText(lTimestampOutputStr);
    }
}

}   /*< namespace Ui */
