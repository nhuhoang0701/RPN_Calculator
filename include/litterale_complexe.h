#ifndef __LITTERALE_COMPLEXE_H__
#define __LITTERALE_COMPLEXE_H__

#include "litterale.h"

class LitteraleComplexe : public LitteraleNombre
{
private:
    LitteraleNombre *partRe_;
    LitteraleNombre *partIm_;

public:
    LitteraleComplexe(LitteraleNombre *re, LitteraleNombre *im);
    ~LitteraleComplexe()
    {
        delete partRe_;
        delete partIm_;
    }
    const LitteraleNombre &getPartRe() const { return *partRe_; }
    const LitteraleNombre &getPartIm() const { return *partIm_; }

    bool isPos() const { return partRe_->isPos() && partIm_->isPos(); }
    bool isNull() const override { return partRe_->isNull() && partIm_->isNull(); }

    const QString affichage(QString f) const override;
    LitteraleComplexe *simplifier() override;
    Litterale *cloneOnHeapGeneral() const override {return cloneOnHeapNombre();}
    LitteraleNombre *cloneOnHeapNombre() const override;
    LitteraleNombre *puissance(LitteraleReelle &l) override;
    virtual LitteraleNombre *traiterUnaireSpeciale(QString operateur) override;
    LitteraleNombre *convertToComplexe() override { return cloneOnHeapNombre(); }

    LitteraleNombre *operator+(LitteraleNombre &l) override;
    LitteraleNombre *operator-(LitteraleNombre &l) override;
    LitteraleNombre *operator*(LitteraleNombre &l) override;
    LitteraleNombre *operator/(LitteraleNombre &l) override;
};

#endif // __LITTERALE_COMPLEXE_H__
