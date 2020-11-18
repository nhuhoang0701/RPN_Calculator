// #ifndef __LITTERALE_COMPLEXE_H__
// #define __LITTERALE_COMPLEXE_H__

// #include "litterale.h"

// class LitteraleComplexe : public LitteraleNombre
// {
// private:
//     LitteraleNumerique* partRe_;
//     LitteraleNumerique* partIm_;

// public:
//     LitteraleComplexe(LitteraleNumerique *re, LitteraleNumerique *im);
//     const LitteraleNumerique &getPartRe() const { return *partRe_; }
//     const LitteraleNumerique &getPartIm() const { return *partIm_; }

//     bool isPos() const { return partRe_->isPos() && partIm_->isPos(); }
//     bool isNull() const override { return partRe_->isNull() && partIm_->isNull(); }

//     const QString affichage() const override;
//     LitteraleComplexe *simplifier() override;
//     LitteraleNombre *cloneOnHeap() const override;
//     LitteraleNombre *convertToComplexe() override { return this; }

//     LitteraleNombre *operator+(LitteraleNombre &l);
//     LitteraleNombre *operator-(LitteraleNombre &l);
//     LitteraleNombre *operator*(LitteraleNombre &l);
//     LitteraleNombre *operator/(LitteraleNombre &l);
// };

// #endif // __LITTERALE_COMPLEXE_H__
