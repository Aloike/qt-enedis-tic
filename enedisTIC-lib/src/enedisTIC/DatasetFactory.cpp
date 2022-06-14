/* Corresponding header inclusion */
#include "enedisTIC/DatasetFactory.h"

/* System includes */
#include <iostream>

/* Libraries includes */

/* Project includes */
#include "enedisTIC/datasets/historical/ADCO.h"
#include "enedisTIC/datasets/historical/BBRHCJB.h"
#include "enedisTIC/datasets/historical/BBRHCJR.h"
#include "enedisTIC/datasets/historical/BBRHCJW.h"
#include "enedisTIC/datasets/historical/BBRHPJB.h"
#include "enedisTIC/datasets/historical/BBRHPJR.h"
#include "enedisTIC/datasets/historical/BBRHPJW.h"
#include "enedisTIC/datasets/historical/DEMAIN.h"
#include "enedisTIC/datasets/historical/HHPHC.h"
#include "enedisTIC/datasets/historical/IINST1.h"
#include "enedisTIC/datasets/historical/IINST2.h"
#include "enedisTIC/datasets/historical/IINST3.h"
#include "enedisTIC/datasets/historical/IMAX1.h"
#include "enedisTIC/datasets/historical/IMAX2.h"
#include "enedisTIC/datasets/historical/IMAX3.h"
#include "enedisTIC/datasets/historical/ISOUSC.h"
#include "enedisTIC/datasets/historical/MOTDETAT.h"
#include "enedisTIC/datasets/historical/OPTARIF.h"
#include "enedisTIC/datasets/historical/PAPP.h"
#include "enedisTIC/datasets/historical/PMAX.h"
#include "enedisTIC/datasets/historical/PPOT.h"
#include "enedisTIC/datasets/historical/PTEC.h"
#include "enedisTIC/datasets/standard/ADSC.h"
#include "enedisTIC/datasets/standard/CCASN.h"
#include "enedisTIC/datasets/standard/CCASN_1.h"
#include "enedisTIC/datasets/standard/DATE.h"
#include "enedisTIC/datasets/standard/EASD01.h"
#include "enedisTIC/datasets/standard/EASD02.h"
#include "enedisTIC/datasets/standard/EASD03.h"
#include "enedisTIC/datasets/standard/EASD04.h"
#include "enedisTIC/datasets/standard/EASF01.h"
#include "enedisTIC/datasets/standard/EASF02.h"
#include "enedisTIC/datasets/standard/EASF03.h"
#include "enedisTIC/datasets/standard/EASF04.h"
#include "enedisTIC/datasets/standard/EASF05.h"
#include "enedisTIC/datasets/standard/EASF06.h"
#include "enedisTIC/datasets/standard/EASF07.h"
#include "enedisTIC/datasets/standard/EASF08.h"
#include "enedisTIC/datasets/standard/EASF09.h"
#include "enedisTIC/datasets/standard/EASF10.h"
#include "enedisTIC/datasets/standard/EAST.h"
#include "enedisTIC/datasets/standard/IRMS1.h"
#include "enedisTIC/datasets/standard/IRMS2.h"
#include "enedisTIC/datasets/standard/IRMS3.h"
#include "enedisTIC/datasets/standard/LTARF.h"
#include "enedisTIC/datasets/standard/MSG1.h"
#include "enedisTIC/datasets/standard/MSG2.h"
#include "enedisTIC/datasets/standard/NGTF.h"
#include "enedisTIC/datasets/standard/NJOURF.h"
#include "enedisTIC/datasets/standard/NJOURF_1.h"
#include "enedisTIC/datasets/standard/NTARF.h"
#include "enedisTIC/datasets/standard/PCOUP.h"
#include "enedisTIC/datasets/standard/PJOURF_1.h"
#include "enedisTIC/datasets/standard/PREF.h"
#include "enedisTIC/datasets/standard/PRM.h"
#include "enedisTIC/datasets/standard/RELAIS.h"
#include "enedisTIC/datasets/standard/SINSTS.h"
#include "enedisTIC/datasets/standard/SINSTS1.h"
#include "enedisTIC/datasets/standard/SINSTS2.h"
#include "enedisTIC/datasets/standard/SINSTS3.h"
#include "enedisTIC/datasets/standard/SMAXSN.h"
#include "enedisTIC/datasets/standard/SMAXSN1.h"
#include "enedisTIC/datasets/standard/SMAXSN2.h"
#include "enedisTIC/datasets/standard/SMAXSN3.h"
#include "enedisTIC/datasets/standard/SMAXSN_1.h"
#include "enedisTIC/datasets/standard/SMAXSN1_1.h"
#include "enedisTIC/datasets/standard/SMAXSN2_1.h"
#include "enedisTIC/datasets/standard/SMAXSN3_1.h"
#include "enedisTIC/datasets/standard/STGE.h"
#include "enedisTIC/datasets/standard/UMOY1.h"
#include "enedisTIC/datasets/standard/UMOY2.h"
#include "enedisTIC/datasets/standard/UMOY3.h"
#include "enedisTIC/datasets/standard/URMS1.h"
#include "enedisTIC/datasets/standard/URMS2.h"
#include "enedisTIC/datasets/standard/URMS3.h"
#include "enedisTIC/datasets/standard/VTIC.h"
#include "enedisTIC/utils.h"


namespace TIC {

/* ########################################################################## */
/* ########################################################################## */

DatasetFactory::DatasetFactory(void)
{

}

/* ########################################################################## */
/* ########################################################################## */

std::shared_ptr<Datasets::AbstractDataset>
DatasetFactory::createDataset(
    const std::string& pDatasetStr
) const
{
    std::string lLabel  = extractLabel(pDatasetStr);
#ifdef  TRACE_DEBUG
    std::cout
            <<  __FILE__ << " +" << __LINE__ << " \t"
            <<  "lLabel: " << lLabel
            <<  std::endl;
#endif


    /*
     *  Instanciate the right concrete implementation
     */
    std::shared_ptr<Datasets::AbstractDataset>    retval;


    if( lLabel == Datasets::ADCO::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::ADCO>();
    }

    else if( lLabel == Datasets::BBRHCJB::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::BBRHCJB>();
    }
    else if( lLabel == Datasets::BBRHPJB::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::BBRHPJB>();
    }

    else if( lLabel == Datasets::BBRHCJW::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::BBRHCJW>();
    }
    else if( lLabel == Datasets::BBRHPJW::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::BBRHPJW>();
    }

    else if( lLabel == Datasets::BBRHCJR::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::BBRHCJR>();
    }
    else if( lLabel == Datasets::BBRHPJR::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::BBRHPJR>();
    }


    else if( lLabel == Datasets::DEMAIN::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::DEMAIN>();
    }

    else if( lLabel == Datasets::HHPHC::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::HHPHC>();
    }

    else if( lLabel == Datasets::IINST1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::IINST1>();
    }
    else if( lLabel == Datasets::IINST2::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::IINST2>();
    }
    else if( lLabel == Datasets::IINST3::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::IINST3>();
    }

    else if( lLabel == Datasets::IMAX1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::IMAX1>();
    }
    else if( lLabel == Datasets::IMAX2::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::IMAX2>();
    }
    else if( lLabel == Datasets::IMAX3::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::IMAX3>();
    }

    else if( lLabel == Datasets::ISOUSC::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::ISOUSC>();
    }

    else if( lLabel == Datasets::MOTDETAT::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::MOTDETAT>();
    }

    else if( lLabel == Datasets::OPTARIF::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::OPTARIF>();
    }

    else if( lLabel == Datasets::PAPP::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::PAPP>();
    }

    else if( lLabel == Datasets::PMAX::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::PMAX>();
    }

    else if( lLabel == Datasets::PPOT::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::PPOT>();
    }

    else if( lLabel == Datasets::PTEC::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::PTEC>();
    }

    /*
     * -------------------------------------------------------------------------
     */

    else if( lLabel == Datasets::ADSC::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::ADSC>();
    }

    else if( lLabel == Datasets::CCASN::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::CCASN>();
    }

    else if( lLabel == Datasets::CCASN_1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::CCASN_1>();
    }

    else if( lLabel == Datasets::DATE::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::DATE>();
    }

    else if( lLabel == Datasets::EASD01::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASD01>();
    }
    else if( lLabel == Datasets::EASD02::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASD02>();
    }
    else if( lLabel == Datasets::EASD03::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASD03>();
    }
    else if( lLabel == Datasets::EASD04::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASD04>();
    }

    else if( lLabel == Datasets::EASF01::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASF01>();
    }
    else if( lLabel == Datasets::EASF02::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASF02>();
    }
    else if( lLabel == Datasets::EASF03::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASF03>();
    }
    else if( lLabel == Datasets::EASF04::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASF04>();
    }
    else if( lLabel == Datasets::EASF05::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASF05>();
    }
    else if( lLabel == Datasets::EASF06::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASF06>();
    }
    else if( lLabel == Datasets::EASF07::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASF07>();
    }
    else if( lLabel == Datasets::EASF08::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASF08>();
    }
    else if( lLabel == Datasets::EASF09::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASF09>();
    }
    else if( lLabel == Datasets::EASF10::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EASF10>();
    }

    else if( lLabel == Datasets::EAST::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::EAST>();
    }

    else if( lLabel == Datasets::IRMS1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::IRMS1>();
    }
    else if( lLabel == Datasets::IRMS2::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::IRMS2>();
    }
    else if( lLabel == Datasets::IRMS3::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::IRMS3>();
    }

    else if( lLabel == Datasets::LTARF::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::LTARF>();
    }

    else if( lLabel == Datasets::MSG1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::MSG1>();
    }
    else if( lLabel == Datasets::MSG2::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::MSG2>();
    }

    else if( lLabel == Datasets::NGTF::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::NGTF>();
    }
    
    else if( lLabel == Datasets::NJOURF::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::NJOURF>();
    }
    else if( lLabel == Datasets::NJOURF_1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::NJOURF_1>();
    }
    
    else if( lLabel == Datasets::NTARF::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::NTARF>();
    }
    
    else if( lLabel == Datasets::PCOUP::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::PCOUP>();
    }

    else if( lLabel == Datasets::PJOURF_1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::PJOURF_1>();
    }

    else if( lLabel == Datasets::PREF::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::PREF>();
    }

    else if( lLabel == Datasets::PRM::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::PRM>();
    }

    else if( lLabel == Datasets::RELAIS::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::RELAIS>();
    }

    else if( lLabel == Datasets::SINSTS::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::SINSTS>();
    }
    else if( lLabel == Datasets::SINSTS1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::SINSTS1>();
    }
    else if( lLabel == Datasets::SINSTS2::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::SINSTS2>();
    }
    else if( lLabel == Datasets::SINSTS3::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::SINSTS3>();
    }

    else if( lLabel == Datasets::SMAXSN::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::SMAXSN>();
    }
    else if( lLabel == Datasets::SMAXSN1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::SMAXSN1>();
    }
    else if( lLabel == Datasets::SMAXSN2::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::SMAXSN2>();
    }
    else if( lLabel == Datasets::SMAXSN3::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::SMAXSN3>();
    }

    else if( lLabel == Datasets::SMAXSN_1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::SMAXSN_1>();
    }
    else if( lLabel == Datasets::SMAXSN1_1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::SMAXSN1_1>();
    }
    else if( lLabel == Datasets::SMAXSN2_1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::SMAXSN2_1>();
    }
    else if( lLabel == Datasets::SMAXSN3_1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::SMAXSN3_1>();
    }

    else if( lLabel == Datasets::STGE::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::STGE>();
    }

    else if( lLabel == Datasets::UMOY1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::UMOY1>();
    }
    else if( lLabel == Datasets::UMOY2::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::UMOY2>();
    }
    else if( lLabel == Datasets::UMOY3::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::UMOY3>();
    }

    else if( lLabel == Datasets::URMS1::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::URMS1>();
    }
    else if( lLabel == Datasets::URMS2::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::URMS2>();
    }
    else if( lLabel == Datasets::URMS3::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::URMS3>();
    }

    else if( lLabel == Datasets::VTIC::LABEL )
    {
        retval  = std::make_shared<TIC::Datasets::VTIC>();
    }


    else
    {
        throw std::runtime_error(
            "Unknown dataset label '" + lLabel + "'!"
        );
    }



    /*
     *  Load data
     */
    retval->unpack( pDatasetStr );


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace TIC
