#include "litterale_entiere.h"
#include "litterale_rationnelle.h"
#include "litterale_reelle.h"
#include "litterale_complexe.h"

LitteraleEntier::LitteraleEntier(int valeur) : valeur_{valeur}
{
    typeLitterale_ = TypeLitterale::ENTIER;
}

LitteraleNumerique *LitteraleEntier::cloneOnHeap() const
{
    return new LitteraleEntier(valeur_);
}

LitteraleNumerique *LitteraleEntier::convertToNumerique(TypeLitterale type)
{
    switch (type)
    {
    case TypeLitterale::RATIONNEL:
        return new LitteraleRationnelle{valeur_, 1};
        break;
    case TypeLitterale::REEL:
        return new LitteraleReelle{valeur_, 0};
        break;
    default:
        return this;
        break;
    }
}

// LitteraleNombre *LitteraleEntier::convertToComplexe()
// {
//     return new LitteraleComplexe{cloneOnHeap(), new LitteraleEntier{}};
// }

LitteraleNumerique *LitteraleEntier::operator+(LitteraleNumerique &l)
{
    if (l.getType() != TypeLitterale::ENTIER)
    {
        return LitteraleNumerique::operator+(l);
    }
    LitteraleEntier &l_cast = dynamic_cast<LitteraleEntier &>(l);
    return new LitteraleEntier{valeur_ + l_cast.valeur_};
}
LitteraleNumerique *LitteraleEntier::operator-(LitteraleNumerique &l)
{
    if (l.getType() != TypeLitterale::ENTIER)
    {
        return LitteraleNumerique::operator-(l);
    }
    LitteraleEntier &l_cast = dynamic_cast<LitteraleEntier &>(l);
    return new LitteraleEntier{valeur_ - l_cast.valeur_};
}

LitteraleNumerique *LitteraleEntier::operator*(LitteraleNumerique &l)
{
    if (l.getType() != TypeLitterale::ENTIER)
    {
        return LitteraleNumerique::operator*(l);
    }
    LitteraleEntier &l_cast = dynamic_cast<LitteraleEntier &>(l);
    return new LitteraleEntier{valeur_ * l_cast.valeur_};
}
LitteraleNumerique *LitteraleEntier::operator/(LitteraleNumerique &l)
{
    if (l.getType() != TypeLitterale::ENTIER)
    {
        return LitteraleNumerique::operator/(l);
    }
    LitteraleEntier &l_cast = dynamic_cast<LitteraleEntier &>(l);
    if (valeur_ % l_cast.valeur_ == 0)
    {
        return new LitteraleEntier{valeur_ / l_cast.valeur_};
    }
    else
    {
        return new LitteraleRationnelle{valeur_, l_cast.valeur_};
    }
}
