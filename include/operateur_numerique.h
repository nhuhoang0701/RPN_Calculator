#include "operateur.h"

class OperateurNumerique : public Operateur
{
public:
    OperateurNumerique(unsigned int arite, QString symbol) : Operateur{arite, symbol} {}
};

/*
** Addition operateur
*/
class Addition : public OperateurNumerique
{
public:
    Addition();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Soustraction operateur
*/
class Soustraction : public OperateurNumerique
{
public:
    Soustraction();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Multiplication operateur
*/
class Multiplication : public OperateurNumerique
{
public:
    Multiplication();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Division operateur
*/
class Division : public OperateurNumerique
{
public:
    Division();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};
