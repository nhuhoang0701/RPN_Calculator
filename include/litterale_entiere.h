#ifndef __LITTERALE_ENTIERE_H__
#define __LITTERALE_ENTIERE_H__

#include "litterale.h"

class LitteraleEntier : public LitteraleNumerique
{
private:
    int valeur_;

public:
    LitteraleEntier(int valeur = 0);

    LitteraleNumerique *cloneOnHeap() const override;
    const QString affichage() const override { return QString::number(valeur_); }
    LitteraleNumerique *simplifier() override { return this; }
    bool isNull() const override { return valeur_ != 0; }
    bool isPos() const override { return valeur_ > 0; }
    double getValeur() const { return valeur_; }

    virtual LitteraleNumerique *convertToNumerique(TypeLitterale type) override;
    // virtual LitteraleNombre *convertToComplexe() override;

    LitteraleNumerique *operator+(LitteraleNumerique &l) override;
    LitteraleNumerique *operator-(LitteraleNumerique &l) override;
    LitteraleNumerique *operator*(LitteraleNumerique &l)override;
    LitteraleNumerique *operator/(LitteraleNumerique &l) override;
};

#endif // __LITTERALE_ENTIERE_H__
