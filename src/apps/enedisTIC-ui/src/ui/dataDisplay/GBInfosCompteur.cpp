#include "GBInfosCompteur.h"
#include "ui_GBInfosCompteur.h"

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

GBInfosCompteur::GBInfosCompteur(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::GBInfosCompteur)
{
    ui->setupUi(this);

    this->clear();
}

GBInfosCompteur::~GBInfosCompteur()
{
    delete ui;
}

void    GBInfosCompteur::clear()
{
    const QString   c_defaultText   = "----";

    this->ui->labelADSCValue->setText(Ui::c_strNoData12);
    this->ui->labelDATEValue->setText(Ui::c_strNoDataTimestamp);
    this->ui->labelMSG1Value->setText(Ui::c_strNoData32);
    this->ui->labelMSG2Value->setText(Ui::c_strNoData16);
    this->ui->labelPRMValue->setText(Ui::c_strNoData14);
    this->ui->labelRELAISValue_1->setText(c_defaultText);
    this->ui->labelRELAISValue_2->setText(c_defaultText);
    this->ui->labelRELAISValue_3->setText(c_defaultText);
    this->ui->labelRELAISValue_4->setText(c_defaultText);
    this->ui->labelRELAISValue_5->setText(c_defaultText);
    this->ui->labelRELAISValue_6->setText(c_defaultText);
    this->ui->labelRELAISValue_7->setText(c_defaultText);
    this->ui->labelRELAISValue_8->setText(c_defaultText);
    this->ui->labelVTICValue->setText(Ui::c_strNoData2);

    this->ui->STGE_contactSec->setText(c_defaultText);
    this->ui->STGE_couleurTempoJour->setText(c_defaultText);
    this->ui->STGE_couleurTempoLendemain->setText(c_defaultText);
    this->ui->STGE_depassementPuissanceReference->setText(c_defaultText);
    this->ui->STGE_etatCacheBorneDistributeur->setText(c_defaultText);
    this->ui->STGE_etatCommEuridis->setText(c_defaultText);
    this->ui->STGE_modeFonctionnement->setText(c_defaultText);
    this->ui->STGE_modeHorloge->setText(c_defaultText);
    this->ui->STGE_modeTIC->setText(c_defaultText);
    this->ui->STGE_organeCoupure->setText(c_defaultText);
    this->ui->STGE_pointeMobileEnCours->setText(c_defaultText);
    this->ui->STGE_preavisPointesMobiles->setText(c_defaultText);
    this->ui->STGE_presenceSurtension->setText(c_defaultText);
    this->ui->STGE_sensEnergieActive->setText(c_defaultText);
    this->ui->STGE_statutCPL->setText(c_defaultText);
    this->ui->STGE_synchroCPL->setText(c_defaultText);
    this->ui->STGE_tarifEnCoursDistributeur->setText(c_defaultText);
    this->ui->STGE_tarifEnCoursFourniture->setText(c_defaultText);
}

void    GBInfosCompteur::setADSC(const QString &pValue)
{
    this->ui->labelADSCValue->setText(pValue);
}

void    GBInfosCompteur::setDATE(const QString &pValue)
{
    QString lDate;


    /* Extract day, month, year */
    lDate   += pValue.mid( 5, 2 );
    lDate   += "/";
    lDate   += pValue.mid( 3, 2 );
    lDate   += "/";
    lDate   += "20" + pValue.mid( 1, 2 );
    lDate   += " ";

    /* Extract time */
    lDate   += pValue.mid( 7, 2 );
    lDate   += ":";
    lDate   += pValue.mid( 9, 2 );
    lDate   += ":";
    lDate   += pValue.mid( 11, 2 );
    lDate   += " ";
    lDate   += "(" + pValue.mid( 0, 1 ) + ")";


    this->ui->labelDATEValue->setText(lDate);
}

void    GBInfosCompteur::setMSG1(const QString &pValue)
{
    this->ui->labelMSG1Value->setText(pValue);
}

void    GBInfosCompteur::setMSG2(const QString &pValue)
{
    this->ui->labelMSG2Value->setText(pValue);
}

void    GBInfosCompteur::setPRM(const QString &pValue)
{
    this->ui->labelPRMValue->setText(pValue);
}

void    GBInfosCompteur::setRELAIS(const QString &pValue)
{
    const QString   c_relaisOpenStr     = tr("Ouvert");
    const QString   c_relaisClosedStr   = tr("Fermé");

    bool    lConversionOk   = false;

    uint    lValue  = pValue.toUInt(&lConversionOk);
    if( lConversionOk == false )
    {
        TRACE_ERR(
            "An error occured while converting string to uint!"
            " (pValue=='%s')",
            pValue.toStdString().c_str()
        )
    }
    else
    {
        this->ui->labelRELAISValue_1->setText(
            ((lValue & 0x01) != 0U)
            ?   c_relaisClosedStr
            :   c_relaisOpenStr
        );

        this->ui->labelRELAISValue_2->setText(
            ((lValue & 0x02) != 0U)
            ?   c_relaisClosedStr
            :   c_relaisOpenStr
        );

        this->ui->labelRELAISValue_3->setText(
            ((lValue & 0x04) != 0U)
            ?   c_relaisClosedStr
            :   c_relaisOpenStr
        );

        this->ui->labelRELAISValue_4->setText(
            ((lValue & 0x08) != 0U)
            ?   c_relaisClosedStr
            :   c_relaisOpenStr
        );

        this->ui->labelRELAISValue_5->setText(
            ((lValue & 0x10) != 0U)
            ?   c_relaisClosedStr
            :   c_relaisOpenStr
        );

        this->ui->labelRELAISValue_6->setText(
            ((lValue & 0x20) != 0U)
            ?   c_relaisClosedStr
            :   c_relaisOpenStr
        );

        this->ui->labelRELAISValue_7->setText(
            ((lValue & 0x40) != 0U)
            ?   c_relaisClosedStr
            :   c_relaisOpenStr
        );

        this->ui->labelRELAISValue_8->setText(
            ((lValue & 0x80) != 0U)
            ?   c_relaisClosedStr
            :   c_relaisOpenStr
        );
    }
}

void    GBInfosCompteur::setSTGE(const QString &pValue)
{
    const QString   c_relaisOpenStr     = tr("Ouvert");
    const QString   c_relaisClosedStr   = tr("Fermé");

    bool    lConversionOk   = false;

    uint    lValue  = pValue.toUInt(&lConversionOk, 16);
    if( lConversionOk == false )
    {
        TRACE_ERR(
            "An error occured while converting string to uint!"
            " (pValue=='%s')",
            pValue.toStdString().c_str()
        )
    }
    else
    {
        QString lTmpStr;
        uint    lTmpUInt;


        /* bit 0: Contact sec */
        this->ui->STGE_contactSec->setText(
            ((lValue & 0x01) != 0U)
            ?   c_relaisOpenStr
            :   c_relaisClosedStr
        );


        /* bit 1-3: Organe de coupure */
        lTmpUInt    = (lValue & 0x0E) >> 1;
        switch( lTmpUInt )
        {
            case 0:
                lTmpStr = c_relaisClosedStr;
                break;

            case 1:
                lTmpStr = tr("O/Surpuissance");
                break;

            case 2:
                lTmpStr = tr("O/Surtension");
                break;

            case 3:
                lTmpStr = tr("O/Délestage");
                break;

            case 4:
                lTmpStr = tr("O/OrdreCPL");
                break;

            case 5:
                lTmpStr = tr("O/SurchauffeISup");
                break;

            case 6:
                lTmpStr = tr("O/SurchauffeIInf");
                break;

            default:
                TRACE_ERR(
                    "Invalid value for Organe de coupure! (%u)",
                    lTmpUInt
                )
                break;
        }
        this->ui->STGE_organeCoupure->setText( lTmpStr );


        /* Bit 4: Cache-bornes */
        this->ui->STGE_etatCacheBorneDistributeur->setText(
            ((lValue & 0x10) != 0U)
            ?   tr("Ouvert")
            :   tr("Fermé")
        );


        /* Bit 5: Non utilisé */

        /* Bit 6: Surtension */
        this->ui->STGE_presenceSurtension->setText(
            ((lValue & 0x20) != 0U)
            ?   tr("Oui")
            :   tr("Non")
        );


        /* Bit 7: Dépassement puissance de référence */
        this->ui->STGE_depassementPuissanceReference->setText(
            ((lValue & 0x40) != 0U)
            ?   tr("En cours")
            :   tr("Non")
        );


        /* Bit 8: Fonctionnement producteur/consommateur */
        this->ui->STGE_modeFonctionnement->setText(
            ((lValue & 0x80) != 0U)
            ?   tr("Producteur")
            :   tr("Consommateur")
        );


        /* Bit 9: Sens énergie active */
        this->ui->STGE_sensEnergieActive->setText(
            ((lValue & 0x0100) != 0U)
            ?   tr("Négative")
            :   tr("Positive")
        );


        /* Bits 10-13: Tarif en cours fourniture */
        lTmpUInt    = (lValue & 0x3C00) >> 10;
        this->ui->STGE_tarifEnCoursFourniture->setText(
            QString::asprintf("Index %u", lTmpUInt + 1U)
        );


        /* Bits 14-15: Tarif en cours distributeur */
        lTmpUInt    = (lValue & 0xC000) >> 14;
        this->ui->STGE_tarifEnCoursDistributeur->setText(
            QString::asprintf("Index %u", lTmpUInt + 1U)
        );


        /* Bit 16: Mode dégradé de l'horloge */
        this->ui->STGE_modeHorloge->setText(
            ((lValue & 0x10000) != 0U)
            ?   tr("Dégradé")
            :   tr("Nominal")
        );


        /* Bit 17: Etat sortie TIC */
        this->ui->STGE_modeTIC->setText(
            ((lValue & 0x20000) != 0U)
            ?   tr("Standard")
            :   tr("Historique")
        );


        /* Bit 18: Non utilisé. */

        /* Bits 19-20: Etat de la sortie de comm Euridis */
        lTmpUInt    = (lValue & 0x180000) >> 19;
        switch( lTmpUInt )
        {
            case 0:
                lTmpStr = tr("Désactivée");
                break;

            case 1:
                lTmpStr = tr("ActSansSécu");
                break;

            case 3:
                lTmpStr = tr("ActAvecSécu");
                break;

            default:
                TRACE_ERR(
                    "Invalid value for Etat de la sortie communication Euridis! (%u)",
                    lTmpUInt
                )
                lTmpStr = QString::asprintf("%u",lTmpUInt);
                break;
        }
        this->ui->STGE_etatCommEuridis->setText( lTmpStr );


        /* Bits 21-22: Statut du CPL */
        lTmpUInt    = (lValue & 0x600000) >> 21;
        switch( lTmpUInt )
        {
            case 0:
                lTmpStr = tr("New/Unlock");
                break;

            case 1:
                lTmpStr = tr("New/Lock");
                break;

            case 2:
                lTmpStr = tr("Registered");
                break;

            default:
                TRACE_ERR(
                    "Invalid value for Statut du CPL! (%u)",
                    lTmpUInt
                )
                lTmpStr = QString::asprintf("%u",lTmpUInt);
                break;
        }
        this->ui->STGE_statutCPL->setText( lTmpStr );


        /* Bit 23: Synchro CPL */
        this->ui->STGE_synchroCPL->setText(
            ((lValue & 0x800000) != 0U)
            ?   tr("OK")
            :   tr("Non syncro")
        );


        /* Bits 24-25: Couleur tempo du jour */
        lTmpUInt    = (lValue & 0x3000000) >> 24;
        switch( lTmpUInt )
        {
            case 0:
                lTmpStr = tr("Pas d'annonce");
                break;

            case 1:
                lTmpStr = tr("Bleu");
                break;

            case 2:
                lTmpStr = tr("Blanc");
                break;

            case 3:
                lTmpStr = tr("Rouge");
                break;

            default:
                TRACE_ERR(
                    "Invalid value for Couleur Tempo du jour! (%u)",
                    lTmpUInt
                )
                lTmpStr = QString::asprintf("%u",lTmpUInt);
                break;
        }
        this->ui->STGE_couleurTempoJour->setText( lTmpStr );


        /* Bits 26-27: Couleur tempo du lendemain */
        lTmpUInt    = (lValue & 0xC000000) >> 26;
        switch( lTmpUInt )
        {
            case 0:
                lTmpStr = tr("Pas d'annonce");
                break;

            case 1:
                lTmpStr = tr("Bleu");
                break;

            case 2:
                lTmpStr = tr("Blanc");
                break;

            case 3:
                lTmpStr = tr("Rouge");
                break;

            default:
                TRACE_ERR(
                    "Invalid value for Couleur Tempo du lendemain! (%u)",
                    lTmpUInt
                )
                lTmpStr = QString::asprintf("%u",lTmpUInt);
                break;
        }
        this->ui->STGE_couleurTempoLendemain->setText( lTmpStr );


        /* Bits 28-29: Préavis pointes mobiles */
        lTmpUInt    = (lValue & 0x30000000) >> 28;
        switch( lTmpUInt )
        {
            case 0:
                lTmpStr = tr("Aucun");
                break;

            case 1:
                lTmpStr = tr("Préavis PM1");
                break;

            case 2:
                lTmpStr = tr("Préavis PM2");
                break;

            case 3:
                lTmpStr = tr("Préavis PM3");
                break;

            default:
                TRACE_ERR(
                    "Invalid value for Préavis pointes mobiles! (%u)",
                    lTmpUInt
                )
                lTmpStr = QString::asprintf("%u",lTmpUInt);
                break;
        }
        this->ui->STGE_preavisPointesMobiles->setText( lTmpStr );


        /* Bits 30-31: Pointe mobile */
        lTmpUInt    = (lValue & 0xC0000000) >> 30;
        switch( lTmpUInt )
        {
            case 0:
                lTmpStr = tr("Aucun");
                break;

            case 1:
                lTmpStr = tr("PM 1 en cours");
                break;

            case 2:
                lTmpStr = tr("PM 2 en cours");
                break;

            case 3:
                lTmpStr = tr("PM 3 en cours");
                break;

            default:
                TRACE_ERR(
                    "Invalid value for Pointe Mobile! (%u)",
                    lTmpUInt
                )
                lTmpStr = QString::asprintf("%u",lTmpUInt);
                break;
        }
        this->ui->STGE_pointeMobileEnCours->setText( lTmpStr );
    }
}

void    GBInfosCompteur::setVTIC(const QString &pValue)
{
    this->ui->labelVTICValue->setText(pValue);
}
