#ifndef GBINFOSCOMPTEUR_H
#define GBINFOSCOMPTEUR_H

#include <QGroupBox>

namespace Ui {
class GBInfosCompteur;
}

class GBInfosCompteur : public QGroupBox
{
    Q_OBJECT

public:
    explicit GBInfosCompteur(QWidget *parent = nullptr);
    ~GBInfosCompteur();

    void    clear(void);

    void    setADSC(const QString& pValue);
    void    setDATE(const QString& pValue);
    void    setMSG1(const QString& pValue);
    void    setMSG2(const QString& pValue);
    void    setPRM(const QString& pValue);
    void    setRELAIS(const QString& pValue);
    void    setSTGE(const QString& pValue);
    void    setVTIC(const QString& pValue);

private:
    Ui::GBInfosCompteur *ui;
};

#endif // GBINFOSCOMPTEUR_H
