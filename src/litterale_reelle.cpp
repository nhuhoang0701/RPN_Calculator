#include <cmath>
#include <iostream>

#include "exceptions.h"
#include "litterale_reelle.h"
#include "litterale_entiere.h"
#include "litterale_rationnelle.h"
#include "litterale_complexe.h"

// LitteraleReelle::LitteraleReelle(long long int entier, double decimal)
//     : entier_{entier}, decimal_{decimal}, valeur_{entier + decimal}
// {
//     typeLitterale_ = TypeLitterale::REEL;
// }

LitteraleReelle::LitteraleReelle(double valeur) : valeur_{valeur}
{
    typeLitterale_ = TypeLitterale::REEL;
    auto pair = getIntDecimal(valeur);
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
        throw CalculateurException{"Pas possible de converter de réel à rationel"};
        break;
    }
    return this;
}

LitteraleNombre *LitteraleReelle::convertToComplexe()
{
    return new LitteraleComplexe{cloneOnHeapNombre(), new LitteraleEntier{0}};
}

LitteraleNombre *LitteraleReelle::cloneOnHeapNombre() const
{
    return new LitteraleReelle{valeur_};
}

LitteraleNumerique *LitteraleReelle::puissance(LitteraleReelle &l)
{
    return new LitteraleReelle{std::pow(valeur_, l.valeur_)};
}

LitteraleNombre *LitteraleReelle::traiterTrigonometrique(const std::function<double(double)> &fonction, QString operateur)
{
    return (new LitteraleReelle{fonction(valeur_)})->simplifier();
}

LitteraleNombre *LitteraleReelle::traiterUnaireSpeciale(QString operateur)
{
    if (operateur == "IM")
    {
        return new LitteraleComplexe{new LitteraleEntier{0}, cloneOnHeapNombre()};
    }
    if (operateur == "NEG")
    {
        return (new LitteraleReelle{-valeur_});
    }
    if (operateur == "SQRT")
    {
        if (valeur_ < 0)
        {
            throw CalculateurException(("Pas possible de traiter SQRT sur une valeur < 0, " +
                                        affichage().toStdString() + " est passé!")
                                           .c_str());
        }
        return new LitteraleReelle{std::sqrt(valeur_)};
    }
    if (operateur == "EXP")
    {
        return new LitteraleReelle{std::exp(valeur_)};
    }
    if (operateur == "LN")
    {
        if (valeur_ <= 0)
        {
            throw CalculateurException(("Pas possible de traiter LN sur une valeur négative, " +
                                        affichage().toStdString() + " est passé!")
                                           .c_str());
        }
        return new LitteraleReelle{std::log(valeur_)};
    }

    Litterale::traiterUnaireSpeciale(operateur);
    return nullptr;
}

std::pair<int, double> LitteraleReelle::getIntDecimal(double valeur)
{
    bool isPos = (valeur >= 0 ? true : false);

    valeur = std::abs(valeur);
    double partDecimal = valeur - std::floor(valeur);
    double partInt = valeur - partDecimal;

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
    return new LitteraleReelle{valeur_ + l_cast.getValeur()};
}

LitteraleNombre *LitteraleReelle::operator-(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::REEL)
    {
        return LitteraleNumerique::operator-(l);
    }
    LitteraleReelle &l_cast = dynamic_cast<LitteraleReelle &>(l);
    return new LitteraleReelle{valeur_ - l_cast.getValeur()};
}

LitteraleNombre *LitteraleReelle::operator*(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::REEL)
    {
        return LitteraleNumerique::operator*(l);
    }
    LitteraleReelle &l_cast = dynamic_cast<LitteraleReelle &>(l);
    auto pairDivide = getIntDecimal(valeur_ * l_cast.getValeur());
    return new LitteraleReelle{valeur_ * l_cast.getValeur()};
}

LitteraleNombre *LitteraleReelle::operator/(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::REEL)
    {
        return LitteraleNumerique::operator/(l);
    }
    LitteraleReelle &l_cast = dynamic_cast<LitteraleReelle &>(l);
    if (l_cast.isNull())
    {
        throw CalculateurException{"Impossible de divider à 0!"};
    }
    return new LitteraleReelle{valeur_ / l_cast.getValeur()};
}
