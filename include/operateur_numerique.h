#ifndef __OPERATEUR_NUMERIQUE_H__
#define __OPERATEUR_NUMERIQUE_H__


#include <QString>
#include <vector>
#include <string>

#include "litterale.h"
#include "operateur.h"
#include "exceptions.h"

class OperateurNumerique : public Operateur
{
private:
    unsigned int arite_;
    QString symbol_;

public:
    OperateurNumerique(unsigned int arite, QString symbol) : Operateur{arite, symbol} {}

    virtual LitteraleNombre *traitement(std::vector<Litterale *> &arguments) = 0;
    virtual void checkPrequisite(std::vector<Litterale *> &arguments);

    static OperateurNumerique *getOperateurNumerique(const QString &symbol);
};

#endif // __OPERATEUR_NUMERIQUE_H__
