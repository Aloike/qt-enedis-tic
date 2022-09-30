#include "GBCourantTension.h"
#include "ui_GBCourantTension.h"

#include <enedisTIC/datasets/AbstractDataset.h>

#include "ui/ui_utils.h"


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

GBCourantTension::GBCourantTension(QWidget *parent)
    :   QGroupBox(parent)
    ,   ui(new Ui::GBCourantTension)
{
    ui->setupUi(this);

    this->clear();
}

GBCourantTension::~GBCourantTension()
{
    delete ui;
}

void    GBCourantTension::clear()
{
    const QString   c_strNoData3A("--- A");
    const QString   c_strNoData3V("--- V");

    this->ui->IRMS1Value->setText(c_strNoData3A);
    this->ui->IRMS2Value->setText(c_strNoData3A);
    this->ui->IRMS3Value->setText(c_strNoData3A);

    this->ui->UMOY1Timestamp->setText(Ui::c_strNoDataTimestamp);
    this->ui->UMOY1Value->setText(c_strNoData3V);
    this->ui->UMOY2Timestamp->setText(Ui::c_strNoDataTimestamp);
    this->ui->UMOY2Value->setText(c_strNoData3V);
    this->ui->UMOY3Timestamp->setText(Ui::c_strNoDataTimestamp);
    this->ui->UMOY3Value->setText(c_strNoData3V);

    this->ui->URMS1Value->setText(c_strNoData3V);
    this->ui->URMS2Value->setText(c_strNoData3V);
    this->ui->URMS3Value->setText(c_strNoData3V);
}

void    GBCourantTension::setIRMS1(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel3(
        pDatasetPtr,
        this->ui->IRMS1Value
    );
}

void    GBCourantTension::setIRMS2(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel3(
        pDatasetPtr,
        this->ui->IRMS2Value
    );
}

void    GBCourantTension::setIRMS3(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel3(
        pDatasetPtr,
        this->ui->IRMS3Value
    );
}

void    GBCourantTension::setLabel3(
                const TIC::TDatasetPtr  &pDataset,
                QLabel                  *pLabelValuePtr,
                QLabel                  *pLabelTimestampPtr )
{
    pLabelValuePtr->setText(
        QString::asprintf(
            "%3d%s%s",
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

void    GBCourantTension::setUMOY1(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel3(
        pDatasetPtr,
        this->ui->UMOY1Value,
        this->ui->UMOY1Timestamp
    );
}

void    GBCourantTension::setUMOY2(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel3(
        pDatasetPtr,
        this->ui->UMOY2Value,
        this->ui->UMOY2Timestamp
    );
}

void    GBCourantTension::setUMOY3(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel3(
        pDatasetPtr,
        this->ui->UMOY3Value,
        this->ui->UMOY3Timestamp
    );
}

void    GBCourantTension::setURMS1(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel3(
        pDatasetPtr,
        this->ui->URMS1Value
    );
}

void    GBCourantTension::setURMS2(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel3(
        pDatasetPtr,
        this->ui->URMS2Value
    );
}

void    GBCourantTension::setURMS3(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->setLabel3(
        pDatasetPtr,
        this->ui->URMS3Value
    );
}
