#ifndef GBPUISSANCEAPPARENTE_H
#define GBPUISSANCEAPPARENTE_H

#include <QGroupBox>

class QLabel;

#include <enedisTIC/utils.h>


namespace Ui {
class GBPuissanceApparente;
}

class GBPuissanceApparente : public QGroupBox
{
    Q_OBJECT

public:
    explicit GBPuissanceApparente(QWidget *parent = nullptr);
    ~GBPuissanceApparente();


    void    clear(void);

    void    setPCOUP(const TIC::TDatasetPtr& pDatasetPtr);
    void    setPREF(const TIC::TDatasetPtr& pDatasetPtr);

    void    setSINSTS(const TIC::TDatasetPtr& pDatasetPtr);
    void    setSINSTS1(const TIC::TDatasetPtr& pDatasetPtr);
    void    setSINSTS2(const TIC::TDatasetPtr& pDatasetPtr);
    void    setSINSTS3(const TIC::TDatasetPtr& pDatasetPtr);

    void    setSMAXSN(const TIC::TDatasetPtr& pDatasetPtr);
    void    setSMAXSN1(const TIC::TDatasetPtr& pDatasetPtr);
    void    setSMAXSN2(const TIC::TDatasetPtr& pDatasetPtr);
    void    setSMAXSN3(const TIC::TDatasetPtr& pDatasetPtr);

    void    setSMAXSN_1(const TIC::TDatasetPtr& pDatasetPtr);
    void    setSMAXSN1_1(const TIC::TDatasetPtr& pDatasetPtr);
    void    setSMAXSN2_1(const TIC::TDatasetPtr& pDatasetPtr);
    void    setSMAXSN3_1(const TIC::TDatasetPtr& pDatasetPtr);


private:
    Ui::GBPuissanceApparente *ui;

    void    setLabel2kVA(
                    const TIC::TDatasetPtr& pDataset,
                    QLabel*                 pLabelPtr );

    void    setLabel5VA(
                    const TIC::TDatasetPtr& pDataset,
                    QLabel*                 pLabelValuePtr ,
                    QLabel*                 pLabelTimestampPtr=nullptr );
};

#endif  /*< GBPUISSANCEAPPARENTE_H */
