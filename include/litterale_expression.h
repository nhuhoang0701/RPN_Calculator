#ifndef __LITTERALE_EXPRESSION_H__
#define __LITTERALE_EXPRESSION_H__

#include <QString>
#include <iostream>

#include "litterale.h"
#include "exceptions.h"

class LitteraleExpression : public Litterale
{
private:
    QString identifieur_;
    Litterale *valeur_;

public:
    LitteraleExpression(QString identifieur, Litterale *valeur)
        : identifieur_{identifieur}, valeur_{valeur} { typeLitterale_ = TypeLitterale::EXPRESSION; }
    LitteraleExpression(QString identifieur) : LitteraleExpression{identifieur, nullptr} {}
    ~LitteraleExpression() { delete valeur_; }

    const QString affichage(QString f = "") const override { return identifieur_; }
    bool isNull() const override { return valeur_->isNull(); }
    LitteraleNombre *evaluer() override
    {
        if (valeur_ == nullptr)
        {
            throw CalculateurException{("Impossible de traiter une littérale expression pointée à nul: " +
                                        identifieur_.toStdString())
                                           .c_str()};
        }
        return valeur_->evaluer();
    }
    Litterale *cloneOnHeapGeneral() const override
    {
        return new LitteraleExpression{identifieur_};
    }

    void setLitterale(Litterale *valeur)
    {
        delete valeur_;
        valeur_ = valeur;
    }
    Litterale *getLitterale() { return valeur_; }

    void setIdentifieur(const QString &identifieur) { identifieur_ = identifieur; }
    const QString &getIdentifieur() { return identifieur_; }
};

#endif // __LITTERALE_EXPRESSION_H__
