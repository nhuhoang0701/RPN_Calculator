#ifndef __LITTERALE_REELLE_H__
#define __LITTERALE_REELLE_H__

#include <utility>
#include "litterale.h"

class LitteraleReelle : public LitteraleNumerique
{
private:
    double valeur_;
    long long int entier_;
    double decimal_;

    std::pair<int, double> getIntDecimal(double valeur);

public:
    // LitteraleReelle(long long int entier, double decimal);
    LitteraleReelle(double valeur);
    Litterale *cloneOnHeapGeneral() const override { return cloneOnHeapNombre(); }
    LitteraleNombre *cloneOnHeapNombre() const override;
    const QString affichage(QString f = "") const override
    {
        f.append(QString::number(valeur_));
        return f;
    }
    LitteraleNumerique *simplifier() override { return this; }
    bool isNull() const override { return valeur_ == 0.0; }
    bool isPos() const override { return valeur_ > 0; }
    int getEntier() const { return entier_; }
    double getValeur() const { return valeur_; }
    double getDecimal() const { return decimal_; }

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

#endif // __LITTERALE_REELLE_H__
