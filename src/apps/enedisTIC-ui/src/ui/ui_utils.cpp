#include "ui_utils.h"

#include <QLabel>
#include <QString>

#include <enedisTIC/datasets/AbstractDataset.h>


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
const QString   c_strNoData2    = "--";
const QString   c_strNoData12   = "------------";
const QString   c_strNoData14   = "--------------";
const QString   c_strNoData16   = "----------------";
const QString   c_strNoData32   = "--------------------------------";


void    setLabel_fromDatasetInt(
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
    else if( pDataset->timestampStr().length() != 13 )
    {
        TRACE_ERR(
            "Invalid timestamp length of %ld! ('%s')",
            pDataset->timestampStr().length(),
            pDataset->timestampStr().c_str()
        );

        pLabelTimestampPtr->setText(c_strNoDataTimestamp);
    }
    else
    {
        QString lTimestampInputStr
            = QString::fromStdString(pDataset->timestampStr());
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

QString TICProfilJourToText(const QString &pProfilStr)
{
    QString retval;


    if( pProfilStr.isEmpty() )
    {
        TRACE_DBG(
            "Empty input string."
        );
    }
    else
    {
        QStringList lTimeSlotsList   = pProfilStr.split(TIC::CHAR_SP);
        TRACE_DBG(
            "Found %d time slots.",
            lTimeSlotsList.count()
        );


        for( QString lTimeSlotStr : lTimeSlotsList )
        {
            if( lTimeSlotStr.length() != 8 )
            {
                TRACE_ERR(
                    "Unexpected string length! (expected 8, got %d, str='%s')",
                    lTimeSlotStr.length(),
                    lTimeSlotStr.toStdString().c_str()
                );
                retval  += "<" + lTimeSlotStr + ">";
                continue;
            }
            else if( lTimeSlotStr == "NONUTILE" )
            {
                /* Ignore this entry */
                continue;
            }
            else
            {
                const QString   c_prefix_dataLineL1("\n+-- ");
                const QString   c_prefix_dataLineL2("\n    +-- ");

                if( ! retval.isEmpty() )
                {
                    retval  += "\n------------------------------\n";
                }

                /* Extract time */
                retval  += lTimeSlotStr.mid(0, 2);
                retval  += ":";
                retval  += lTimeSlotStr.mid(2, 2);

                /* Extract action value */
                QString lTmpStr;
                lTmpStr = "0x" + lTimeSlotStr.mid(4, 4);

                uint16_t    lActionValue    = 0x0000;
                bool    lTmpBool    = false;
                lActionValue    = lTmpStr.toUInt(&lTmpBool, 16);
                if( ! lTmpBool )
                {
                    TRACE_ERR(
                        "Unable to convert string to hex! ('%s')",
                        lTmpStr.toStdString().c_str()
                    )
                    retval  += "<Conv. error::" + lTmpStr + ">";
                }
                else
                {
                    /* Generate action strings */
                    uint16_t    lTmpUInt;

                    lTmpUInt    = (lActionValue & 0x000F);
                    retval  += c_prefix_dataLineL1 + "Idx. Ventilation: ";
                    if( lTmpUInt == 0 )
                    {
                        retval  += "Inchangé";
                    }
                    else if(    lTmpUInt >= 1U
                            &&  lTmpUInt <= 10U )
                    {
                        retval  += QString::asprintf(
                            "Idx %2u",
                            lTmpUInt
                        );
                    }
                    else
                    {
                        retval  += QString::asprintf(
                            "Inchangé %2u",
                            lTmpUInt
                        );
                    }

                    retval  += c_prefix_dataLineL1 + "Contact sec: ";
                    lTmpUInt    = (lActionValue & 0xC000);
                    switch(lTmpUInt)
                    {
                        case 0x0000:
                            retval  += "Aucune manoeuvre.";
                            break;

                        case 0x4000:
                            retval  += "Tempo.";
                            break;

                        case 0x8000:
                            retval  += "Ouverture.";
                            break;

                        case 0xC000:
                            retval  += "Fermeture.";
                            break;

                        default:
                            retval  += "??";
                            break;
                    }

                    retval  += c_prefix_dataLineL1 + "Contacts virtuels:";
                    lTmpUInt    = (lActionValue & 0x07F0) >> 4;
                    for( uint8_t lContactNbr = 0 ; lContactNbr < 7 ; ++lContactNbr )
                    {
                        retval  += c_prefix_dataLineL2;
                        retval  += QString::asprintf(
                            "Contact %u: ",
                            lContactNbr + 1
                        );
                        if( lTmpUInt & (0x0001 << lContactNbr) )
                        {
                            retval  += "Fermé";
                        }
                        else
                        {
                            retval  += "Ouvert";
                        }
                    }
                }
            }
        }
    }


    if(retval.isEmpty())
    {
        retval  = "N/A";
    }

    return retval;
}

}   /*< namespace Ui */
