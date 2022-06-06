#ifndef GBTENSIONCOURANT_H
#define GBTENSIONCOURANT_H

#include <QGroupBox>

class   QLabel;

#include <enedisTIC/utils.h>

namespace Ui {
class GBCourantTension;
}

class GBCourantTension : public QGroupBox
{
    Q_OBJECT

public:
    explicit GBCourantTension(QWidget *parent = nullptr);
    ~GBCourantTension();


    void    clear(void);


    void    setIRMS1(const TIC::TDatasetPtr& pDatasetPtr);
    void    setIRMS2(const TIC::TDatasetPtr& pDatasetPtr);
    void    setIRMS3(const TIC::TDatasetPtr& pDatasetPtr);

    void    setUMOY1(const TIC::TDatasetPtr& pDatasetPtr);
    void    setUMOY2(const TIC::TDatasetPtr& pDatasetPtr);
    void    setUMOY3(const TIC::TDatasetPtr& pDatasetPtr);

    void    setURMS1(const TIC::TDatasetPtr& pDatasetPtr);
    void    setURMS2(const TIC::TDatasetPtr& pDatasetPtr);
    void    setURMS3(const TIC::TDatasetPtr& pDatasetPtr);

private:
    Ui::GBCourantTension *ui;

    void    setLabel3(
                    const TIC::TDatasetPtr& pDataset,
                    QLabel*                 pLabelValuePtr ,
                    QLabel*                 pLabelTimestampPtr=nullptr );
};

#endif // GBTENSIONCOURANT_H
