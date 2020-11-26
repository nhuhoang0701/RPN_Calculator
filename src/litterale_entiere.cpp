#include <iostream>
#include <cmath>

#include "exceptions.h"
#include "litterale_entiere.h"
#include "litterale_rationnelle.h"
#include "litterale_reelle.h"
#include "litterale_complexe.h"

LitteraleEntier::LitteraleEntier(long long int valeur) : valeur_{valeur}
{
    typeLitterale_ = TypeLitterale::ENTIER;
}

LitteraleNumerique *LitteraleEntier::cloneOnHeapNombre() const
{
    return new LitteraleEntier(valeur_);
}

LitteraleNumerique *LitteraleEntier::puissance(LitteraleReelle &l)
{
    double valeur = std::pow(valeur_, l.getValeur());
    if (valeur == std::floor(valeur))
    {
        return new LitteraleEntier{static_cast<long long int>(valeur)};
    }
    return new LitteraleReelle{valeur};
}

LitteraleNombre *LitteraleEntier::traiterTrigonometrique(const std::function<double(double)> &fonction, QString operateur)
{
    double result = fonction(valeur_);
    if (result == std::floor(result))
    {
        return new LitteraleEntier{static_cast<long long int>(result)};
    }
    return new LitteraleReelle{result};
}

LitteraleNombre *LitteraleEntier::traiterUnaireSpeciale(QString operateur)
{
    if (operateur == "IM")
    {
        return new LitteraleComplexe{new LitteraleEntier{0}, cloneOnHeapNombre()};
    }
    if (operateur == "NEG")
    {
        return new LitteraleEntier{-valeur_};
    }
    if (operateur == "SQRT")
    {
        if (valeur_ < 0)
        {
            throw CalculateurException(("Pas possible de traiter SQRT sur une valeur < 0, " +
                                        std::to_string(valeur_) + " est passé!")
                                           .c_str());
        }
        double valeur = std::sqrt(valeur_);
        if (valeur == std::floor(valeur))
        {
            return new LitteraleEntier{static_cast<long long int>(valeur)};
        }
        return new LitteraleReelle{valeur};
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
    if (operateur == "NUM")
    {
        return new LitteraleEntier{valeur_};
    }
    if (operateur == "DEN")
    {
        return new LitteraleEntier{1};
    }
    Litterale::traiterUnaireSpeciale(operateur);
    return nullptr;
}

LitteraleNumerique *LitteraleEntier::convertToNumerique(TypeLitterale type)
{
    switch (type)
    {
    case TypeLitterale::RATIONNEL:
        return new LitteraleRationnelle{valeur_, 1};
        break;
    case TypeLitterale::REEL:
        return new LitteraleReelle{static_cast<double>(valeur_)};
        break;
    default:
        return this;
        break;
    }
}

LitteraleNombre *LitteraleEntier::convertToComplexe()
{
    return new LitteraleComplexe{cloneOnHeapNombre(), new LitteraleEntier{0}};
}

LitteraleNombre *LitteraleEntier::operator+(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::ENTIER)
    {
        return LitteraleNumerique::operator+(l);
    }
    LitteraleEntier &l_cast = dynamic_cast<LitteraleEntier &>(l);
    return new LitteraleEntier{valeur_ + l_cast.valeur_};
}

LitteraleNombre *LitteraleEntier::operator-(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::ENTIER)
    {
        return LitteraleNumerique::operator-(l);
    }
    LitteraleEntier &l_cast = dynamic_cast<LitteraleEntier &>(l);
    return new LitteraleEntier{valeur_ - l_cast.valeur_};
}

LitteraleNombre *LitteraleEntier::operator*(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::ENTIER)
    {
        return LitteraleNumerique::operator*(l);
    }
    LitteraleEntier &l_cast = dynamic_cast<LitteraleEntier &>(l);
    return new LitteraleEntier{valeur_ * l_cast.valeur_};
}
LitteraleNombre *LitteraleEntier::operator/(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::ENTIER)
    {
        return LitteraleNumerique::operator/(l);
    }
    LitteraleEntier &l_cast = dynamic_cast<LitteraleEntier &>(l);
    if (l_cast.isNull())
    {
        throw CalculateurException{"Impossible de divider à 0!"};
    }
    if (valeur_ % l_cast.valeur_ == 0)
    {
        return new LitteraleEntier{valeur_ / l_cast.valeur_};
    }
    else
    {
        return new LitteraleRationnelle{valeur_, l_cast.valeur_};
    }
}
