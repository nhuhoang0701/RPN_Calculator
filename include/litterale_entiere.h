#ifndef __LITTERALE_ENTIERE_H__
#define __LITTERALE_ENTIERE_H__

#include "litterale.h"

class LitteraleEntier : public LitteraleNumerique
{
private:
    long long int valeur_;

public:
    LitteraleEntier(long long int valeur = 0);

    Litterale *cloneOnHeapGeneral() const override { return cloneOnHeapNombre(); }
    LitteraleNumerique *cloneOnHeapNombre() const override;
    const QString affichage(QString f = "") const override { return f.append(QString::number(valeur_)); }
    LitteraleNumerique *simplifier() override { return this; }
    bool isNull() const override { return valeur_ == 0; }
    bool isPos() const override { return valeur_ > 0; }
    double getValeur() const { return valeur_; }

    virtual LitteraleNumerique *puissance(LitteraleReelle &l) override;
    virtual LitteraleNombre *traiterTrigonometrique(const std::function<double(double)> &fonction, QString operateur) override;
    virtual LitteraleNombre *traiterUnaireSpeciale(QString operateur) override;
    virtual LitteraleNumerique *convertToNumerique(TypeLitterale type) override;
    virtual LitteraleNombre *convertToComplexe() override;

    LitteraleNombre *operator+(LitteraleNombre &l) override;
    LitteraleNombre *operator-(LitteraleNombre &l) override;
    LitteraleNombre *operator*(LitteraleNombre &l) override;
    LitteraleNombre *operator/(LitteraleNombre &l) override;
};

#endif // __LITTERALE_ENTIERE_H__
