/* Corresponding header inclusion */
#include "GBDataViewer.h"

/* System includes */

/* Libraries includes */
#include <QHBoxLayout>
#include <QTableWidget>
#include <QVBoxLayout>

/* Project includes */
#include "core/comm/protocol/tic/datasets.h"
#include "core/comm/protocol/tic/utils.h"
#include "ui/dataDisplay/GBInfosCompteur.h"
#include "ui/dataDisplay/GBPuissanceApparente.h"
#include "ui/dataDisplay/GBCourantTension.h"


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

GBDataViewer::GBDataViewer(QWidget *parent)
    :   QGroupBox(
            tr("Received data"),
            parent
        )
    ,   p_infosCompteurGB(new GBInfosCompteur(this))
    ,   p_puissanceApparenteGB(new GBPuissanceApparente(this))
    ,   p_table(new QTableWidget(this))
    ,   p_tensionCourantGB(new GBCourantTension(this))
{
    this->_createUi();

    this->_createLayout();
}

/* ########################################################################## */
/* ########################################################################## */

void
    GBDataViewer::_createLayout(void)
{
    this->p_layoutMain  = new   QHBoxLayout(this);
    this->p_layoutMain->addWidget( this->p_infosCompteurGB );
    this->p_layoutMain->addWidget( this->p_table );

    this->p_layoutReadings  = new QVBoxLayout();
    this->p_layoutMain->addLayout(this->p_layoutReadings);
    this->p_layoutReadings->addWidget( this->p_puissanceApparenteGB );
    this->p_layoutReadings->addWidget( this->p_tensionCourantGB );
}

/* ########################################################################## */
/* ########################################################################## */

void
    GBDataViewer::_createUi(void)
{
    this->p_table->setColumnCount(EColumnsCount);
    this->p_table->setRowCount(ERowsCount);

//    this->p_table->setItem(
//            ERowADSC,
//            EColumnLabel,
//            new QTableWidgetItem( "ADSC" )
//        );

//    M_TABLEITEMS_FROM_DATASET( p_table, ERowADSC, ADSC )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowCCASN_1, CCASN_1 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowCCASN, CCASN )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowDATE, DATE )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASD01, EASD01 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASD02, EASD02 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASD03, EASD03 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASD04, EASD04 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASF01, EASF01 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASF02, EASF02 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASF03, EASF03 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASF04, EASF04 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASF05, EASF05 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASF06, EASF06 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASF07, EASF07 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASF08, EASF08 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASF09, EASF09 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEASF10, EASF10 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowEAST, EAST )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowIRMS1, IRMS1 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowIRMS2, IRMS2 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowIRMS3, IRMS3 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowLTARF, LTARF )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowMSG1, MSG1 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowMSG2, MSG2 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowNGTF, NGTF )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowNJOURF_1, NJOURF_1 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowNJOURF, NJOURF )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowNTARF, NTARF )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowPCOUP, PCOUP )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowPJOURF_1, PJOURF_1 )
    M_TABLEITEMS_FROM_DATASET( p_table, ERowPPOINTE, PPOINTE )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowPREF, PREF )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowPRM, PRM )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowRELAIS, RELAIS )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowSINSTS1, SINSTS1 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowSINSTS2, SINSTS2 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowSINSTS3, SINSTS3 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowSINSTS, SINSTS )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowSMAXSN1_1, SMAXSN1_1 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowSMAXSN_1, SMAXSN_1 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowSMAXSN1, SMAXSN1 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowSMAXSN2_1, SMAXSN2_1 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowSMAXSN2, SMAXSN2 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowSMAXSN3_1, SMAXSN3_1 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowSMAXSN3, SMAXSN3 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowSMAXSN, SMAXSN )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowSTGE, STGE )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowUMOY1, UMOY1 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowUMOY2, UMOY2 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowUMOY3, UMOY3 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowURMS1, URMS1 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowURMS2, URMS2 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowURMS3, URMS3 )
//    M_TABLEITEMS_FROM_DATASET( p_table, ERowVTIC, VTIC )
}

/* ########################################################################## */
/* ########################################################################## */

void
    GBDataViewer::updateData(
        const TIC::TDatasetsPtrList &pDatasetsList
    )
{
    foreach( TIC::TDatasetPtr lDatasetPtr, pDatasetsList)
    {
        int lRow    = -1;

        TRACE_DBG(
            "Processing dataset with label '%s'.",
            lDatasetPtr->label().c_str()
        )


//        if(lDatasetPtr->label() == TIC::Datasets::ADSC::LABEL )
//        {
//            lRow    = ERowADSC;
////            auto p_dataset
////                = std::static_pointer_cast<TIC::Datasets::ADCO>(lDatasetPtr);
//        }
        if(lDatasetPtr->label() == TIC::Datasets::ADSC::LABEL )
        {
//            lRow    = ERowADSC;
            this->p_infosCompteurGB->setADSC(
                QString::fromStdString(lDatasetPtr->data())
            );
            continue;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::CCASN_1::LABEL )
        {
            lRow    = ERowCCASN_1;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::CCASN::LABEL )
        {
            lRow    = ERowCCASN;
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
            lRow    = ERowEASD01;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASD02::LABEL )
        {
            lRow    = ERowEASD02;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASD03::LABEL )
        {
            lRow    = ERowEASD03;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASD04::LABEL )
        {
            lRow    = ERowEASD04;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF01::LABEL )
        {
            lRow    = ERowEASF01;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF02::LABEL )
        {
            lRow    = ERowEASF02;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF03::LABEL )
        {
            lRow    = ERowEASF03;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF04::LABEL )
        {
            lRow    = ERowEASF04;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF05::LABEL )
        {
            lRow    = ERowEASF05;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF06::LABEL )
        {
            lRow    = ERowEASF06;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF07::LABEL )
        {
            lRow    = ERowEASF07;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF08::LABEL )
        {
            lRow    = ERowEASF08;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF09::LABEL )
        {
            lRow    = ERowEASF09;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EASF10::LABEL )
        {
            lRow    = ERowEASF10;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::EAST::LABEL )
        {
            lRow    = ERowEAST;
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
            lRow    = ERowLTARF;
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
            lRow    = ERowNGTF;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::NJOURF_1::LABEL )
        {
            lRow    = ERowNJOURF_1;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::NJOURF::LABEL )
        {
            lRow    = ERowNJOURF;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::NTARF::LABEL )
        {
            lRow    = ERowNTARF;
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
            lRow    = ERowPJOURF_1;
        }
        else if(lDatasetPtr->label() == TIC::Datasets::PPOINTE::LABEL )
        {
            lRow    = ERowPPOINTE;
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


        this->p_table->setItem(
            lRow,
            EColumnValue,
            new QTableWidgetItem( QString::fromStdString(lDatasetPtr->data()) )
        );
        this->p_table->selectRow(lRow);
    }
}

/* ########################################################################## */
/* ########################################################################## */
