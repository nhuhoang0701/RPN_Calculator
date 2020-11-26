#ifndef __OPERATEUR_ACCESSIBLE_H__
#define __OPERATEUR_ACCESSIBLE_H__

#include "operateur.h"
#include "controleur.h"
#include "pile.h"

using identifieurMap_t = std::map<QString, LitteraleExpression *>;

class OperateurAccessible : public Operateur
{
public:
    static Pile *pile_;
    static identifieurMap_t *identifieurMap_;

public:
    OperateurAccessible(unsigned int arite, QString symbol)
        : Operateur{arite, symbol} {}
    virtual void traitement() = 0;

    static OperateurAccessible *getOperateurAccessible(const QString &symbol, Pile *pile, identifieurMap_t *mp);
    static void setPile(Pile* pile);
    static void setIdentifieurMap(identifieurMap_t* mp);
};

#endif // __OPERATEUR_ACCESSIBLE_H__
