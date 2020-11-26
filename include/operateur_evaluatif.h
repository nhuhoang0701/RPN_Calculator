#ifndef __OPERATEUR_EVALUATIF_H__
#define __OPERATEUR_EVALUATIF_H__

#include "operateur_numerique.h"
#include "operateur_accessible.h"
#include "controleur.h"

class OperateurEvaluatif : public OperateurAccessible
{
public:
    OperateurEvaluatif(unsigned int arite, QString symbol)
        : OperateurAccessible{arite, symbol} {}
};

// IFT opérateur
class IfThen : public OperateurEvaluatif
{
public:
    IfThen();
    void traitement() override;
};

// IFTE opérateur
class IfThenElse : public OperateurEvaluatif
{
public:
    IfThenElse();
    void traitement() override;
};

// WHILE opérateur
class While : public OperateurEvaluatif
{
public:
    While();
    void traitement() override;
};

// EVAL opérateur
class Evaluer : public OperateurEvaluatif
{
public:
    Evaluer();
    void traitement() override;
};

// STO opérateur
class Stocker : public OperateurEvaluatif
{
public:
    Stocker();
    void traitement() override;
};

// FORGET opérateur
class Forget : public OperateurEvaluatif
{
private:
    QString atome_;

public:
    Forget(const QString &atome);
    void traitement() override;
};
#endif // __OPERATEUR_EVALUATIF_H__
