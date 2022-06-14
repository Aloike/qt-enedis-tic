#include "GBPuissanceApparente.h"
#include "ui_GBPuissanceApparente.h"

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

GBPuissanceApparente::GBPuissanceApparente(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::GBPuissanceApparente)
{
    ui->setupUi(this);

    this->clear();
}

GBPuissanceApparente::~GBPuissanceApparente()
{
    delete ui;
}

void    GBPuissanceApparente::clear()
{
    const QString   c_strNoData2kVA("-- kVA");
    const QString   c_strNoData5charsVA("----- VA");
    const QString   c_strNoDataTimestamp("@ --/--/---- --:--:-- (-)");

    this->ui->PCOUPValue->setText(c_strNoData2kVA);
    this->ui->PREFValue->setText(c_strNoData2kVA);
    this->ui->SINSTSValue->setText(c_strNoData5charsVA);
    this->ui->SINSTS1Value->setText(c_strNoData5charsVA);
    this->ui->SINSTS2Value->setText(c_strNoData5charsVA);
    this->ui->SINSTS3Value->setText(c_strNoData5charsVA);

    this->ui->SMAXSNTimestamp->setText(c_strNoDataTimestamp);
    this->ui->SMAXSNValue->setText(c_strNoData5charsVA);
    this->ui->SMAXSN1Timestamp->setText(c_strNoDataTimestamp);
    this->ui->SMAXSN1Value->setText(c_strNoData5charsVA);
    this->ui->SMAXSN2Timestamp->setText(c_strNoDataTimestamp);
    this->ui->SMAXSN2Value->setText(c_strNoData5charsVA);
    this->ui->SMAXSN3Timestamp->setText(c_strNoDataTimestamp);
    this->ui->SMAXSN3Value->setText(c_strNoData5charsVA);

    this->ui->SMAXSN_1Timestamp->setText(c_strNoDataTimestamp);
    this->ui->SMAXSN_1Value->setText(c_strNoData5charsVA);
    this->ui->SMAXSN1_1Timestamp->setText(c_strNoDataTimestamp);
    this->ui->SMAXSN1_1Value->setText(c_strNoData5charsVA);
    this->ui->SMAXSN2_1Timestamp->setText(c_strNoDataTimestamp);
    this->ui->SMAXSN2_1Value->setText(c_strNoData5charsVA);
    this->ui->SMAXSN3_1Timestamp->setText(c_strNoDataTimestamp);
    this->ui->SMAXSN3_1Value->setText(c_strNoData5charsVA);
}

void    GBPuissanceApparente::setLabel2kVA(
                const TIC::TDatasetPtr  &pDataset,
                QLabel                  *pLabelPtr )
{
    pLabelPtr->setText(
        QString::asprintf(
            "%2d kVA",
            QString::fromStdString(pDataset->data()).toInt()
        )
    );
}

void    GBPuissanceApparente::setLabel5VA(
                const TIC::TDatasetPtr  &pDataset,
                QLabel                  *pLabelValuePtr,
                QLabel                  *pLabelTimestampPtr )
{
    pLabelValuePtr->setText(
        QString::asprintf(
            "%5d VA",
            QString::fromStdString(pDataset->data()).toInt()
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

void    GBPuissanceApparente::setPCOUP(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel2kVA(
        pDatasetPtr,
        this->ui->PCOUPValue
    );
}

void    GBPuissanceApparente::setPREF(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel2kVA(
        pDatasetPtr,
        this->ui->PREFValue
    );
}

void    GBPuissanceApparente::setSINSTS(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel5VA(
        pDatasetPtr,
        this->ui->SINSTSValue
    );
}

void    GBPuissanceApparente::setSINSTS1(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel5VA(
        pDatasetPtr,
        this->ui->SINSTS1Value
    );
}

void    GBPuissanceApparente::setSINSTS2(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel5VA(
        pDatasetPtr,
        this->ui->SINSTS2Value
    );
}

void    GBPuissanceApparente::setSINSTS3(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel5VA(
        pDatasetPtr,
        this->ui->SINSTS3Value
    );
}

void    GBPuissanceApparente::setSMAXSN(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel5VA(
        pDatasetPtr,
        this->ui->SMAXSNValue,
        this->ui->SMAXSNTimestamp
    );
}

void    GBPuissanceApparente::setSMAXSN_1(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel5VA(
        pDatasetPtr,
        this->ui->SMAXSN_1Value,
        this->ui->SMAXSN_1Timestamp
    );
}

void    GBPuissanceApparente::setSMAXSN1(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel5VA(
        pDatasetPtr,
        this->ui->SMAXSN1Value,
        this->ui->SMAXSN1Timestamp
    );
}

void    GBPuissanceApparente::setSMAXSN1_1(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel5VA(
        pDatasetPtr,
        this->ui->SMAXSN1_1Value,
        this->ui->SMAXSN1_1Timestamp
    );
}

void    GBPuissanceApparente::setSMAXSN2(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel5VA(
        pDatasetPtr,
        this->ui->SMAXSN2Value,
        this->ui->SMAXSN2Timestamp
    );
}

void    GBPuissanceApparente::setSMAXSN2_1(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel5VA(
        pDatasetPtr,
        this->ui->SMAXSN2_1Value,
        this->ui->SMAXSN2_1Timestamp
    );
}

void    GBPuissanceApparente::setSMAXSN3(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel5VA(
        pDatasetPtr,
        this->ui->SMAXSN3Value,
        this->ui->SMAXSN3Timestamp
    );
}

void    GBPuissanceApparente::setSMAXSN3_1(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel5VA(
        pDatasetPtr,
        this->ui->SMAXSN3_1Value,
        this->ui->SMAXSN3_1Timestamp
    );
}
