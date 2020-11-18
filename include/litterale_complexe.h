#ifndef __LITTERALE_COMPLEXE_H__
#define __LITTERALE_COMPLEXE_H__

#include "litterale.h"

class LitteraleComplexe : public LitteraleNombre
{
private:
    LitteraleNombre* partRe_;
    LitteraleNombre* partIm_;

public:
    LitteraleComplexe(LitteraleNombre *re, LitteraleNombre *im);

    const LitteraleNombre &getPartRe() const { return *partRe_; }
    const LitteraleNombre &getPartIm() const { return *partIm_; }

    bool isPos() const { return partRe_->isPos() && partIm_->isPos(); }
    bool isNull() const override { return partRe_->isNull() && partIm_->isNull(); }

    const QString affichage(QString f) const override;
    LitteraleComplexe *simplifier() override;
    LitteraleNombre *cloneOnHeap() const override;
    LitteraleNombre *convertToComplexe() override { return cloneOnHeap(); }

    LitteraleNombre *operator+(LitteraleNombre &l);
    LitteraleNombre *operator-(LitteraleNombre &l);
    LitteraleNombre *operator*(LitteraleNombre &l);
    LitteraleNombre *operator/(LitteraleNombre &l);
};

#endif // __LITTERALE_COMPLEXE_H__
