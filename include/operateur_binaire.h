#include "operateur.h"

class OperateurBinaire : public Operateur
{
public:
    OperateurBinaire(QString symbol) : Operateur{2, symbol} {}
    void checkNotProgramme(const std::vector<Litterale *> &arguments)
    {
        for (auto &argument : arguments)
        {
            if (argument->getType() == TypeLitterale::PROGRAMME)
            {
                std::string name = argument->affichage().toStdString();
                throw CalculateurException(("Programme trouvés dans l'opérateur de nombre et expression: " + name).c_str());
            }
        }
    }
};

/*
** Addition operateur
*/
class Addition : public OperateurBinaire
{
public:
    Addition();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Soustraction operateur
*/
class Soustraction : public OperateurBinaire
{
public:
    Soustraction();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Multiplication operateur
*/
class Multiplication : public OperateurBinaire
{
public:
    Multiplication();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Division operateur
*/
class Division : public OperateurBinaire
{
public:
    Division();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Quotient operateur
*/
class Quotient : public OperateurBinaire
{
public:
    Quotient();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Module operateur
*/
class Module : public OperateurBinaire
{
public:
    Module();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Pow operateur
*/
class Power : public OperateurBinaire
{
public:
    Power();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Egalite operateur
*/
class Egalite : public OperateurBinaire
{
public:
    Egalite();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Inegalite operateur
*/
class Inegalite : public OperateurBinaire
{
public:
    Inegalite();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** InferieurOuEgal operateur
*/
class InferieurOuEgal : public OperateurBinaire
{
public:
    InferieurOuEgal();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** SuperieurOuEgal operateur
*/
class SuperieurOuEgal : public OperateurBinaire
{
public:
    SuperieurOuEgal();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Inferieur operateur
*/
class Inferieur : public OperateurBinaire
{
public:
    Inferieur();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Superieur operateur
*/
class Superieur : public OperateurBinaire
{
public:
    Superieur();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** And operateur
*/
class And : public OperateurBinaire
{
public:
    And();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};

/*
** Or operateur
*/
class Or : public OperateurBinaire
{
public:
    Or();
    LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) override;
};
