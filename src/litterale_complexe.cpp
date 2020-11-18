// #include <iostream>

// #include "litterale_complexe.h"

// LitteraleComplexe::LitteraleComplexe(LitteraleNumerique *re, LitteraleNumerique *im)
//     : partRe_{re}, partIm_{im}
// {
//     typeLitterale_ = TypeLitterale::COMPLEXE;
// }
// LitteraleComplexe *LitteraleComplexe::simplifier()
// {
//     partRe_->simplifier();
//     partIm_->simplifier();
//     return this;
// }

// LitteraleNombre *LitteraleComplexe::cloneOnHeap() const
// {
//     LitteraleNumerique *re = partRe_->cloneOnHeap();
//     LitteraleNumerique *im = partIm_->cloneOnHeap();
//     return new LitteraleComplexe{re, im};
// }

// const QString LitteraleComplexe::affichage() const
// {
//     return partRe_->affichage() + QString{"+"} + partIm_->affichage() + QString{"i"};
// }

// LitteraleNombre *LitteraleComplexe::operator+(LitteraleNombre &l)
// {
//     if (l.getType() != TypeLitterale::COMPLEXE)
//     {
//         return *this + *l.convertToComplexe();
//     }
//     LitteraleComplexe &l_cast = dynamic_cast<LitteraleComplexe &>(l);
//     return new LitteraleComplexe{*partRe_ + *(l_cast.partRe_),
//                                  *partIm_ + *(l_cast.partIm_)};
// }

// LitteraleNombre *LitteraleComplexe::operator-(LitteraleNombre &l)
// {
//     if (l.getType() != TypeLitterale::COMPLEXE)
//     {
//         return *this - *l.convertToComplexe();
//     }
//     LitteraleComplexe &l_cast = dynamic_cast<LitteraleComplexe &>(l);
//     return new LitteraleComplexe{*partRe_ - *(l_cast.partRe_),
//                                  *partIm_ - *(l_cast.partIm_)};
// }

// LitteraleNombre *LitteraleComplexe::operator*(LitteraleNombre &l)
// {
//     if (l.getType() != TypeLitterale::COMPLEXE)
//     {
//         return *this + *l.convertToComplexe();
//     }
//     LitteraleComplexe &l_cast = dynamic_cast<LitteraleComplexe &>(l);
//     return new LitteraleComplexe{*partRe_ * *(l_cast.partRe_),
//                                  *partIm_ * *(l_cast.partIm_)};
// }

// LitteraleNombre *LitteraleComplexe::operator/(LitteraleNombre &l)
// {
//     if (l.getType() != TypeLitterale::COMPLEXE)
//     {
//         return *this + *l.convertToComplexe();
//     }
//     LitteraleComplexe &l_cast = dynamic_cast<LitteraleComplexe &>(l);
//     return new LitteraleComplexe{*partRe_ / *(l_cast.partRe_),
//                                  *partIm_ + *(l_cast.partIm_)};
// }
