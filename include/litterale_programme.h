#ifndef __OPERATEUR_PROGRAMME_H__
#define __OPERATEUR_PROGRAMME_H__

#include "operateur.h"
#include "litterale.h"
#include "controleur.h"

class LitteraleProgramme : public Litterale
{
private:
    QString programme_;
    Controleur *controleur_;

public:
    LitteraleProgramme(const QString &programme, Controleur *controleur)
        : programme_{programme}, controleur_{controleur}
    {
        typeLitterale_ = TypeLitterale::PROGRAMME;
    }
    bool isNull() const override { return programme_ == ""; }
    const QString affichage(QString f = "") const override { return programme_; }
    Litterale *cloneOnHeapGeneral() const override { return new LitteraleProgramme{programme_, controleur_}; }
    LitteraleNombre *evaluer() override;
};

#endif // __OPERATEUR_PROGRAMME_H__
