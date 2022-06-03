#include "GBEnergieActive.h"
#include "ui_GBEnergieActive.h"

//#include "core/comm/protocol/tic/datasets/AbstractDataset.h"
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

static const uint   C_FIELDWIDTH    = 9U;


GBEnergieActive::GBEnergieActive(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::GBEnergieActive)
{
    ui->setupUi(this);

    this->clear();
}

GBEnergieActive::~GBEnergieActive()
{
    delete ui;
}

void    GBEnergieActive::clear()
{
    const QString   c_strNoData9WhA("--------- Wh");

    this->ui->EASD01Value->setText(c_strNoData9WhA);
    this->ui->EASD02Value->setText(c_strNoData9WhA);
    this->ui->EASD03Value->setText(c_strNoData9WhA);
    this->ui->EASD04Value->setText(c_strNoData9WhA);

    this->ui->EASF01Value->setText(c_strNoData9WhA);
    this->ui->EASF02Value->setText(c_strNoData9WhA);
    this->ui->EASF03Value->setText(c_strNoData9WhA);
    this->ui->EASF04Value->setText(c_strNoData9WhA);
    this->ui->EASF05Value->setText(c_strNoData9WhA);
    this->ui->EASF06Value->setText(c_strNoData9WhA);
    this->ui->EASF07Value->setText(c_strNoData9WhA);
    this->ui->EASF08Value->setText(c_strNoData9WhA);
    this->ui->EASF09Value->setText(c_strNoData9WhA);
    this->ui->EASF10Value->setText(c_strNoData9WhA);

    this->ui->EASTValue->setText(c_strNoData9WhA);
}

void    GBEnergieActive::setEASD01(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASD01Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEASD02(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASD02Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEASD03(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASD03Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEASD04(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASD04Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEASF01(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASF01Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEASF02(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASF02Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEASF03(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASF03Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEASF04(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASF04Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEASF05(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASF05Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEASF06(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASF06Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEASF07(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASF07Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEASF08(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASF08Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEASF09(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASF09Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEASF10(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASF10Value,
        C_FIELDWIDTH
    );
}

void    GBEnergieActive::setEAST(const TIC::TDatasetPtr &pDatasetPtr)
{
    Ui::setLabel_fromDatasetInt(
        pDatasetPtr,
        this->ui->EASTValue,
        C_FIELDWIDTH
    );
}
