/* Corresponding header inclusion */
#include "WDataViewer.h"

/* System includes */

/* Libraries includes */
#include <QHBoxLayout>
#include <QTableWidget>
#include <QVBoxLayout>

/* Project includes */
#include "core/comm/protocol/tic/datasets.h"
#include "core/comm/protocol/tic/utils.h"
#include "ui/dataDisplay/GBCourantTension.h"
#include "ui/dataDisplay/GBEnergieActive.h"
#include "ui/dataDisplay/GBInfosCompteur.h"
#include "ui/dataDisplay/GBPuissanceApparente.h"
#include "ui/dataDisplay/GBTarification.h"


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

#define M_TABLEITEMS_FROM_DATASET(pTablePtr, pRow, pDatasetClass) \
        pTablePtr->setItem( \
            pRow, \
            EColumnLabel, \
            new QTableWidgetItem( \
                QString(TIC::Datasets::pDatasetClass::LABEL.c_str()) \
            ) \
        );

/* ########################################################################## */
/* ########################################################################## */

WDataViewer::WDataViewer(QWidget *parent)
    :   QWidget( parent )
    ,   p_energieActiveGB(new GBEnergieActive(this))
    ,   p_infosCompteurGB(new GBInfosCompteur(this))
    ,   p_puissanceApparenteGB(new GBPuissanceApparente(this))
    ,   p_tarificationGB(new GBTarification(this))
    ,   p_tensionCourantGB(new GBCourantTension(this))
{
    this->_createUi();

    this->_createLayout();
}

/* ########################################################################## */
/* ########################################################################## */

void
    WDataViewer::_createLayout(void)
{
    this->p_layoutMain  = new   QHBoxLayout(this);
    this->p_layoutMain->addWidget( this->p_infosCompteurGB );
    this->p_layoutMain->addWidget( this->p_tarificationGB );

    this->p_layoutReadings  = new QVBoxLayout();
    this->p_layoutMain->addLayout(this->p_layoutReadings);
    this->p_layoutReadings->addWidget( this->p_energieActiveGB );
    this->p_layoutReadings->addSpacerItem(
        new QSpacerItem(
            0,
            0,
            QSizePolicy::Expanding,
            QSizePolicy::Expanding
        )
    );
    this->p_layoutReadings->addWidget( this->p_puissanceApparenteGB );
    this->p_layoutReadings->addSpacerItem(
        new QSpacerItem(
            0,
            0,
            QSizePolicy::Expanding,
            QSizePolicy::Expanding
        )
    );
    this->p_layoutReadings->addWidget( this->p_tensionCourantGB );
}

/* ########################################################################## */
/* ########################################################################## */

void
    WDataViewer::_createUi(void)
{
}

/* ########################################################################## */
/* ########################################################################## */

void
    WDataViewer::updateData(
        const TIC::TDatasetsPtrList &pDatasetsList
    )
{
    foreach( TIC::TDatasetPtr lDatasetPtr, pDatasetsList)
    {
        TRACE_DBG(
            "Processing dataset with label '%s'.",
            lDatasetPtr->label().c_str()
        )


        if(lDatasetPtr->label() == TIC::Datasets::ADSC::LABEL )
        {
            this->p_infosCompteurGB->setADSC(
                QString::fromStdString(lDatasetPtr->data())
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::CCASN_1::LABEL )
        {
            this->p_energieActiveGB->setCCASN_1(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::CCASN::LABEL )
        {
            this->p_energieActiveGB->setCCASN(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::DATE::LABEL )
        {
            this->p_infosCompteurGB->setDATE(
                QString::fromStdString(lDatasetPtr->timestamp())
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASD01::LABEL )
        {
            this->p_energieActiveGB->setEASD01(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASD02::LABEL )
        {
            this->p_energieActiveGB->setEASD02(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASD03::LABEL )
        {
            this->p_energieActiveGB->setEASD03(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASD04::LABEL )
        {
            this->p_energieActiveGB->setEASD04(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF01::LABEL )
        {
            this->p_energieActiveGB->setEASF01(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF02::LABEL )
        {
            this->p_energieActiveGB->setEASF02(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF03::LABEL )
        {
            this->p_energieActiveGB->setEASF03(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF04::LABEL )
        {
            this->p_energieActiveGB->setEASF04(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF05::LABEL )
        {
            this->p_energieActiveGB->setEASF05(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF06::LABEL )
        {
            this->p_energieActiveGB->setEASF06(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF07::LABEL )
        {
            this->p_energieActiveGB->setEASF07(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF08::LABEL )
        {
            this->p_energieActiveGB->setEASF08(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF09::LABEL )
        {
            this->p_energieActiveGB->setEASF09(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF10::LABEL )
        {
            this->p_energieActiveGB->setEASF10(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EAST::LABEL )
        {
            this->p_energieActiveGB->setEAST(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::IRMS1::LABEL )
        {
            this->p_tensionCourantGB->setIRMS1(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::IRMS2::LABEL )
        {
            this->p_tensionCourantGB->setIRMS2(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::IRMS3::LABEL )
        {
            this->p_tensionCourantGB->setIRMS3(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::LTARF::LABEL )
        {
            this->p_tarificationGB->setLTARF(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::MSG1::LABEL )
        {
            this->p_infosCompteurGB->setMSG1(
                QString::fromStdString(lDatasetPtr->data())
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::MSG2::LABEL )
        {
            this->p_infosCompteurGB->setMSG2(
                QString::fromStdString(lDatasetPtr->data())
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::NGTF::LABEL )
        {
            this->p_tarificationGB->setNGTF(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::NJOURF_1::LABEL )
        {
            this->p_tarificationGB->setNJOURF_1(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::NJOURF::LABEL )
        {
            this->p_tarificationGB->setNJOURF(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::NTARF::LABEL )
        {
            this->p_tarificationGB->setNTARF(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::PCOUP::LABEL )
        {
            this->p_puissanceApparenteGB->setPCOUP(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::PJOURF_1::LABEL )
        {
            this->p_tarificationGB->setPJOURF_1(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::PPOINTE::LABEL )
        {
            this->p_tarificationGB->setPPOINTE(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::PREF::LABEL )
        {
            this->p_puissanceApparenteGB->setPREF(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::PRM::LABEL )
        {
            this->p_infosCompteurGB->setPRM(
                QString::fromStdString(lDatasetPtr->data())
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::RELAIS::LABEL )
        {
            this->p_infosCompteurGB->setRELAIS(
                QString::fromStdString(lDatasetPtr->data())
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::SINSTS1::LABEL )
        {
            this->p_puissanceApparenteGB->setSINSTS1(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::SINSTS2::LABEL )
        {
            this->p_puissanceApparenteGB->setSINSTS2(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::SINSTS3::LABEL )
        {
            this->p_puissanceApparenteGB->setSINSTS3(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::SINSTS::LABEL )
        {
            this->p_puissanceApparenteGB->setSINSTS(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::SMAXSN1_1::LABEL )
        {
            this->p_puissanceApparenteGB->setSMAXSN1_1(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::SMAXSN_1::LABEL )
        {
            this->p_puissanceApparenteGB->setSMAXSN_1(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::SMAXSN1::LABEL )
        {
            this->p_puissanceApparenteGB->setSMAXSN1(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::SMAXSN2_1::LABEL )
        {
            this->p_puissanceApparenteGB->setSMAXSN2_1(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::SMAXSN2::LABEL )
        {
            this->p_puissanceApparenteGB->setSMAXSN2(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::SMAXSN3_1::LABEL )
        {
            this->p_puissanceApparenteGB->setSMAXSN3_1(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::SMAXSN3::LABEL )
        {
            this->p_puissanceApparenteGB->setSMAXSN3(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::SMAXSN::LABEL )
        {
            this->p_puissanceApparenteGB->setSMAXSN(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::STGE::LABEL )
        {
            this->p_infosCompteurGB->setSTGE(
                QString::fromStdString(lDatasetPtr->data())
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::UMOY1::LABEL )
        {
            this->p_tensionCourantGB->setUMOY1(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::UMOY2::LABEL )
        {
            this->p_tensionCourantGB->setUMOY2(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::UMOY3::LABEL )
        {
            this->p_tensionCourantGB->setUMOY3(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::URMS1::LABEL )
        {
            this->p_tensionCourantGB->setURMS1(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::URMS2::LABEL )
        {
            this->p_tensionCourantGB->setURMS2(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::URMS3::LABEL )
        {
            this->p_tensionCourantGB->setURMS3(
                lDatasetPtr
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::VTIC::LABEL )
        {
            this->p_infosCompteurGB->setVTIC(
                QString::fromStdString(lDatasetPtr->data())
            );
            continue;
        }
        else
        {
            TRACE_ERR(
                "Unknown label %s!",
                lDatasetPtr->label().c_str()
            )
            continue;
        }
    }
}

/* ########################################################################## */
/* ########################################################################## */
