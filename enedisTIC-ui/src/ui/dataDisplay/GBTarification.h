#ifndef GBTARIFICATION_H
#define GBTARIFICATION_H

#include <QGroupBox>

#include "core/comm/protocol/tic/utils.h"

namespace Ui {
class GBTarification;
}

class   GBTarification
        :   public  QGroupBox
{
    Q_OBJECT

public:

    explicit GBTarification(QWidget *parent = nullptr);
    ~GBTarification();


    void    clear(void);


    void    setLTARF(const TIC::TDatasetPtr& pDatasetPtr);
    void    setNGTF(const TIC::TDatasetPtr& pDatasetPtr);

    void    setNJOURF(const TIC::TDatasetPtr& pDatasetPtr);
    void    setNJOURF_1(const TIC::TDatasetPtr& pDatasetPtr);

    void    setNTARF(const TIC::TDatasetPtr& pDatasetPtr);

    void    setPJOURF_1(const TIC::TDatasetPtr& pDatasetPtr);
    void    setPPOINTE(const TIC::TDatasetPtr& pDatasetPtr);


private:

    Ui::GBTarification *ui;

};

#endif  /*< GBTARIFICATION_H */
