#ifndef GBENERGIEACTIVE_H
#define GBENERGIEACTIVE_H

#include <QGroupBox>

#include "core/comm/protocol/tic/utils.h"

namespace Ui {
class GBEnergieActive;
}

class   GBEnergieActive
        :   public  QGroupBox
{
    Q_OBJECT

public:
    explicit GBEnergieActive(QWidget *parent = nullptr);
    ~GBEnergieActive();


    void    clear(void);


    void    setEASD01(const TIC::TDatasetPtr& pDatasetPtr);
    void    setEASD02(const TIC::TDatasetPtr& pDatasetPtr);
    void    setEASD03(const TIC::TDatasetPtr& pDatasetPtr);
    void    setEASD04(const TIC::TDatasetPtr& pDatasetPtr);

    void    setEASF01(const TIC::TDatasetPtr& pDatasetPtr);
    void    setEASF02(const TIC::TDatasetPtr& pDatasetPtr);
    void    setEASF03(const TIC::TDatasetPtr& pDatasetPtr);
    void    setEASF04(const TIC::TDatasetPtr& pDatasetPtr);
    void    setEASF05(const TIC::TDatasetPtr& pDatasetPtr);
    void    setEASF06(const TIC::TDatasetPtr& pDatasetPtr);
    void    setEASF07(const TIC::TDatasetPtr& pDatasetPtr);
    void    setEASF08(const TIC::TDatasetPtr& pDatasetPtr);
    void    setEASF09(const TIC::TDatasetPtr& pDatasetPtr);
    void    setEASF10(const TIC::TDatasetPtr& pDatasetPtr);

    void    setEAST(const TIC::TDatasetPtr& pDatasetPtr);

    void    setCCASN(const TIC::TDatasetPtr& pDatasetPtr);
    void    setCCASN_1(const TIC::TDatasetPtr& pDatasetPtr);


private:
    Ui::GBEnergieActive *ui;
};

#endif  /*< GBENERGIEACTIVE_H */
