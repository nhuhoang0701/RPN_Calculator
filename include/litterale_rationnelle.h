#ifndef __LITTERALE_RATIONNELLE_H__
#define __LITTERALE_RATIONNELLE_H__

#include "litterale.h"

class LitteraleRationnelle : public LitteraleNumerique
{
private:
    long long int num_;
    long long int den_;

public:
    LitteraleRationnelle(long long int num, long long int den = 1);

    long long int getNum() const { return num_; }
    long long int getDen() const { return den_; }

    const QString affichage(QString f = "") const override;
    bool isNull() const override { return num_ == 0; }
    bool isPos() const override { return num_ * den_ > 0; }
    Litterale *cloneOnHeapGeneral() const override { return cloneOnHeapNombre(); }
    LitteraleNombre *cloneOnHeapNombre() const override;
    LitteraleNumerique *simplifier() override;
    // double getValeur() const { return double(num_) / den_; }

    virtual LitteraleNumerique *puissance(LitteraleReelle &l) override;
    virtual LitteraleNombre *traiterTrigonometrique(const std::function<double(double)> &fonction, QString operateur);
    virtual LitteraleNombre *traiterUnaireSpeciale(QString operateur) override;
    virtual LitteraleNumerique *convertToNumerique(TypeLitterale type) override;
    virtual LitteraleNombre *convertToComplexe() override;

    LitteraleNombre *operator+(LitteraleNombre &l) override;
    LitteraleNombre *operator-(LitteraleNombre &l) override;
    LitteraleNombre *operator*(LitteraleNombre &l) override;
    LitteraleNombre *operator/(LitteraleNombre &l) override;
};
#endif // __LITTERALE_RATIONNELLE_H__
