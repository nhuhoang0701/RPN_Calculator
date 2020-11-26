#include <iostream>
#include <complex>

#include "litterale_reelle.h"
#include "litterale_complexe.h"

LitteraleComplexe::LitteraleComplexe(LitteraleNombre *re, LitteraleNombre *im)
    : partRe_{re}, partIm_{im}
{
    typeLitterale_ = TypeLitterale::COMPLEXE;
}

LitteraleComplexe *LitteraleComplexe::simplifier()
{
    //todo: Fix later
    partRe_->simplifier();
    partIm_->simplifier();
    return this;
}

LitteraleNombre *LitteraleComplexe::cloneOnHeapNombre() const
{
    LitteraleNombre *re = partRe_->cloneOnHeapNombre();
    LitteraleNombre *im = partIm_->cloneOnHeapNombre();
    return new LitteraleComplexe{re, im};
}

LitteraleNombre *LitteraleComplexe::puissance(LitteraleReelle &l)
{
    //todo: Fix later
    double valeur = l.getValeur();
    if (valeur != std::floor(valeur))
    {
        throw CalculateurException("Pas possible de traiter POW sur index non-entier d'un complexe");
    }
    for (size_t i = 0; i < static_cast<long long int>(valeur); i++)
    {
    }
    return nullptr;
}

LitteraleNombre *LitteraleComplexe::traiterUnaireSpeciale(QString operateur)
{
    if (operateur == "IM")
    {
        return (new LitteraleComplexe{
                    (partIm_->traiterUnaireSpeciale("NEG")), partRe_->traiterUnaireSpeciale("NEG")})
            ->simplifier();
    }
    if (operateur == "NEG")
    {
        return (new LitteraleComplexe{
                    (partRe_->traiterUnaireSpeciale("NEG")), partRe_->traiterUnaireSpeciale("NEG")})
            ->simplifier();
    }
    Litterale::traiterUnaireSpeciale(operateur);
    return nullptr;
}

const QString LitteraleComplexe::affichage(QString f) const
{
    //todo: Fix later
    return f.append(partRe_->affichage() + QString{"+"} + partIm_->affichage() + QString{"i"});
}

LitteraleNombre *LitteraleComplexe::operator+(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::COMPLEXE)
    {
        return *this + *l.convertToComplexe();
    }
    LitteraleComplexe &l_cast = dynamic_cast<LitteraleComplexe &>(l);
    return new LitteraleComplexe{*partRe_ + *(l_cast.partRe_),
                                 *partIm_ + *(l_cast.partIm_)};
}

LitteraleNombre *LitteraleComplexe::operator-(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::COMPLEXE)
    {
        return *this - *l.convertToComplexe();
    }
    LitteraleComplexe &l_cast = dynamic_cast<LitteraleComplexe &>(l);
    return new LitteraleComplexe{*partRe_ - *(l_cast.partRe_),
                                 *partIm_ - *(l_cast.partIm_)};
}

LitteraleNombre *LitteraleComplexe::operator*(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::COMPLEXE)
    {
        return *this * *l.convertToComplexe();
    }
    LitteraleComplexe &l_cast = dynamic_cast<LitteraleComplexe &>(l);

    //todo: Fix product of 2 litteraleComplexe
    return new LitteraleComplexe{*partRe_ * *(l_cast.partRe_),
                                 *partIm_ * *(l_cast.partIm_)};
}

LitteraleNombre *LitteraleComplexe::operator/(LitteraleNombre &l)
{
    if (l.getType() != TypeLitterale::COMPLEXE)
    {
        return *this + *l.convertToComplexe();
    }
    LitteraleComplexe &l_cast = dynamic_cast<LitteraleComplexe &>(l);

    //todo: Fix division of 2 litteraleComplexe
    return new LitteraleComplexe{*partRe_ / *(l_cast.partRe_),
                                 *partIm_ + *(l_cast.partIm_)};
}
