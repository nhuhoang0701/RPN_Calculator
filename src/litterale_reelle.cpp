#include <cmath>

#include "exceptions.h"
#include "litterale_reelle.h"
#include "litterale_entiere.h"
#include "litterale_rationnelle.h"
#include "litterale_complexe.h"

LitteraleReelle::LitteraleReelle(int entier, double decimal)
    : entier_{entier}, decimal_{decimal}, valeur_{entier + decimal}
{
    typeLitterale_ = TypeLitterale::REEL;
}

LitteraleReelle::LitteraleReelle(double valeur) : valeur_{valeur}
{
    typeLitterale_ = TypeLitterale::REEL;
    auto pair = getRelleDivide(valeur);
    entier_ = pair.first;
    decimal_ = pair.second;
}

LitteraleNumerique *LitteraleReelle::convertToNumerique(TypeLitterale type)
{
    switch (type)
    {
    case TypeLitterale::ENTIER:
        return new LitteraleEntier{int(std::floor(valeur_))};
        break;
    case TypeLitterale::RATIONNEL:
        throw CalculateurException{"Cannot convert real to rational"};
        break;
    }
    return this;
}

LitteraleNombre *LitteraleReelle::convertToComplexe()
{
    return new LitteraleComplexe{cloneOnHeap(), new LitteraleEntier{1}};
}

LitteraleNumerique *LitteraleReelle::cloneOnHeap() const
{
    return new LitteraleReelle{entier_, decimal_};
}

std::pair<int, double> LitteraleReelle::getRelleDivide(double valeur)
{
    bool isPos = (valeur >= 0 ? true : false);

    valeur = std::abs(valeur);
    int partInt = int(valeur - std::floor(valeur));
    double partDecimal = valeur - partInt;

    partInt = (isPos ? partInt : -partInt);
    return std::make_pair(partInt, partDecimal);
}

LitteraleNombre *LitteraleReelle::operator+(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::REEL)
    {
        return LitteraleNumerique::operator+(l);
    }
    LitteraleReelle &l_cast = dynamic_cast<LitteraleReelle &>(l);
    auto pairDivide = getRelleDivide(valeur_ + l_cast.getValeur());
    return new LitteraleReelle{pairDivide.first, pairDivide.second};
}

LitteraleNombre *LitteraleReelle::operator-(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::REEL)
    {
        return LitteraleNumerique::operator-(l);
    }
    LitteraleReelle &l_cast = dynamic_cast<LitteraleReelle &>(l);
    auto pairDivide = getRelleDivide(valeur_ - l_cast.getValeur());
    return new LitteraleReelle{pairDivide.first, pairDivide.second};
}

LitteraleNombre *LitteraleReelle::operator*(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::REEL)
    {
        return LitteraleNumerique::operator*(l);
    }
    LitteraleReelle &l_cast = dynamic_cast<LitteraleReelle &>(l);
    auto pairDivide = getRelleDivide(valeur_ * l_cast.getValeur());
    return new LitteraleReelle{pairDivide.first, pairDivide.second};
}

LitteraleNombre *LitteraleReelle::operator/(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::REEL)
    {
        return LitteraleNumerique::operator/(l);
    }
    LitteraleReelle &l_cast = dynamic_cast<LitteraleReelle &>(l);
    auto pairDivide = getRelleDivide(valeur_ / l_cast.getValeur());
    return new LitteraleReelle{pairDivide.first, pairDivide.second};
}
