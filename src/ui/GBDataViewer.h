#ifndef GBDATAVIEWER_H
#define GBDATAVIEWER_H

/* Inherited classes */
#include <QGroupBox>

/* System includes */

/* Libraries includes */
class   QTableWidget;
class   QVBoxLayout;

/* Project includes */
#include "core/comm/protocol/tic/utils.h"



/* ########################################################################## */
/* ########################################################################## */

class   GBDataViewer
        :   public  QGroupBox
{
    Q_OBJECT

public:

    explicit GBDataViewer(QWidget *parent = nullptr);


    void    updateData(const TIC::TDatasetsPtrList &pDatasetsList);



protected:
private:

    void    _createLayout(void);
    void    _createUi(void);



public:
protected:
private:

    enum    EColumns
    {
        EColumnLabel,
        EColumnValue,
        EColumnUnit,

        EColumnsCount
    };

    enum    ERows
    {
        ERowADSC,
        ERowCCASN,
        ERowCCASN_1,
        ERowDATE,
        ERowEASD01,
        ERowEASD02,
        ERowEASD03,
        ERowEASD04,
        ERowEASF01,
        ERowEASF02,
        ERowEASF03,
        ERowEASF04,
        ERowEASF05,
        ERowEASF06,
        ERowEASF07,
        ERowEASF08,
        ERowEASF09,
        ERowEASF10,
        ERowEAST,
        ERowIRMS1,
        ERowIRMS2,
        ERowIRMS3,
        ERowLTARF,
        ERowMSG1,
        ERowMSG2,
        ERowNGTF,
        ERowNJOURF,
        ERowNJOURF_1,
        ERowNTARF,
        ERowPCOUP,
        ERowPJOURF_1,
        ERowPPOINTE,
        ERowPREF,
        ERowPRM,
        ERowRELAIS,
        ERowSINSTS,
        ERowSINSTS1,
        ERowSINSTS2,
        ERowSINSTS3,
        ERowSMAXSN,
        ERowSMAXSN_1,
        ERowSMAXSN1,
        ERowSMAXSN1_1,
        ERowSMAXSN2,
        ERowSMAXSN2_1,
        ERowSMAXSN3,
        ERowSMAXSN3_1,
        ERowSTGE,
        ERowUMOY1,
        ERowUMOY2,
        ERowUMOY3,
        ERowURMS1,
        ERowURMS2,
        ERowURMS3,
        ERowVTIC,

        ERowsCount
    };


    QVBoxLayout*    p_layoutMain;
    QTableWidget*   p_table;



signals:

public slots:
};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< GBDATAVIEWER_H */
