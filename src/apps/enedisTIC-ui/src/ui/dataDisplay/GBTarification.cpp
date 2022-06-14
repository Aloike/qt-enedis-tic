#include "GBTarification.h"
#include "ui_GBTarification.h"

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

GBTarification::GBTarification(QWidget *parent)
    :   QGroupBox(parent)
    ,   ui(new Ui::GBTarification)
{
    ui->setupUi(this);

    this->clear();
}

GBTarification::~GBTarification()
{
    delete ui;
}

void    GBTarification::clear()
{
    const QString   c_strNoData16("----------------");
    const QString   c_strNoData2("--");


    this->ui->LTARFValue->setText(c_strNoData16);
    this->ui->NGTFValue->setText(c_strNoData16);

    this->ui->NJOURFValue->setText(c_strNoData2);
    this->ui->NJOURF_1Value->setText(c_strNoData2);

    this->ui->NTARFValue->setText(c_strNoData2);

    this->ui->PJOURF_1TB->clear();
    this->ui->PPOINTETB->clear();
}

void    GBTarification::setLTARF(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->ui->LTARFValue->setText(QString::fromStdString(pDatasetPtr->data()));
}

void    GBTarification::setNGTF(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->ui->NGTFValue->setText(QString::fromStdString(pDatasetPtr->data()));
}

void    GBTarification::setNJOURF(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->ui->NJOURFValue->setText(QString::fromStdString(pDatasetPtr->data()));
}

void    GBTarification::setNJOURF_1(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->ui->NJOURF_1Value->setText(
        QString::fromStdString(pDatasetPtr->data())
    );
}

void    GBTarification::setNTARF(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->ui->NTARFValue->setText(QString::fromStdString(pDatasetPtr->data()));
}

void    GBTarification::setPJOURF_1(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->ui->PJOURF_1TB->setText(
        Ui::TICProfilJourToText(
            QString::fromStdString(pDatasetPtr->data())
        )
    );
}

void    GBTarification::setPPOINTE(const TIC::TDatasetPtr &pDatasetPtr)
{
    this->ui->PPOINTETB->setText(
        Ui::TICProfilJourToText(
            QString::fromStdString(pDatasetPtr->data())
        )
    );
}
