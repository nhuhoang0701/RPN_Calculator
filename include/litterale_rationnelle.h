#ifndef __LITTERALE_RATIONNELLE_H__
#define __LITTERALE_RATIONNELLE_H__

#include "litterale.h"

class LitteraleRationnelle : public LitteraleNumerique
{
private:
    int num_;
    int den_;

public:
    LitteraleRationnelle(int num, int den = 1);

    int getNum() const { return num_; }
    int getDen() const { return den_; }

    const QString affichage(QString f) const override;
    bool isNull() const override { return num_ == 0; }
    bool isPos() const override { return num_ * den_ > 0; }
    LitteraleNumerique *cloneOnHeap() const override;
    LitteraleNumerique *simplifier() override;
    // double getValeur() const { return double(num_) / den_; }

    virtual LitteraleNumerique* puissance(LitteraleReelle& l) override;
    virtual LitteraleNumerique *convertToNumerique(TypeLitterale type) override;
    virtual LitteraleNombre *convertToComplexe() override;

    LitteraleNombre *operator+(LitteraleNombre &l) override;
    LitteraleNombre *operator-(LitteraleNombre &l) override;
    LitteraleNombre *operator*(LitteraleNombre &l)override;
    LitteraleNombre *operator/(LitteraleNombre &l) override;
};
#endif // __LITTERALE_RATIONNELLE_H__
