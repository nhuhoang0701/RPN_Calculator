#include <map>
#include <iostream>
#include <memory>

#include "operateur_numerique.h"
#include "operateur_binaire.h"
#include "operateur_unaire.h"

void OperateurNumerique::checkPrequisite(std::vector<Litterale *> &arguments)
{
    // Tester le taille du vecteur arguments
    if (arguments.size() != getArite())
    {
        std::string message = "Opérande " + getSymbol().toStdString() + " demande " +
                              std::to_string(getArite()) + " argument, " +
                              std::to_string(arguments.size()) + " passé(s)!";
        throw CalculateurException(message.c_str());
    }

    // Tester arguments ne contiennent pas littérale programme
    for (auto &argument : arguments)
    {
        if (argument->getType() == TypeLitterale::PROGRAMME)
        {
            std::string name = argument->affichage().toStdString();
            throw CalculateurException(("Programme trouvés dans l'opérateur de nombre et expression: " + name).c_str());
        }
    }

    // Tester arguments ne contiennent pas nullptr
    for (auto &argument : arguments)
    {
        if (argument->evaluer() == nullptr)
        {
            throw CalculateurException("Littérale nul est passé, pas de littérale!");
        }
    }
}

OperateurNumerique *OperateurNumerique::getOperateurNumerique(const QString &symbol)
{
    static std::map<QString, std::shared_ptr<OperateurNumerique>> operateurMap_ = {
        {"+", std::make_shared<Addition>()},
        {"-", std::make_shared<Soustraction>()},
        {"*", std::make_shared<Multiplication>()},
        {"/", std::make_shared<Division>()},
        {"DIV", std::make_shared<Quotient>()},
        {"MOD", std::make_shared<Module>()},
        {"POW", std::make_shared<Power>()},
        {"==", std::make_shared<Egalite>()},
        {"!=", std::make_shared<Inegalite>()},
        {"=<", std::make_shared<InferieurOuEgal>()},
        {">=", std::make_shared<SuperieurOuEgal>()},
        {"<", std::make_shared<Inferieur>()},
        {">", std::make_shared<Superieur>()},
        {"AND", std::make_shared<And>()},
        {"OR", std::make_shared<Or>()},

        {"NOT", std::make_shared<Not>()},
        {"NUM", std::make_shared<Numerateur>()},
        {"DEN", std::make_shared<Denominateur>()},
        {"SQRT", std::make_shared<Sqrt>()},
        {"SIN", std::make_shared<Sin>()},
        {"COS", std::make_shared<Cos>()},
        {"TAN", std::make_shared<Tan>()},
        {"ARCSIN", std::make_shared<Arcsin>()},
        {"ARCCOS", std::make_shared<Arccos>()},
        {"ARCTAN", std::make_shared<Arctan>()},
        {"IM", std::make_shared<Imagine>()},
        {"NEG", std::make_shared<Negative>()},
        {"EXP", std::make_shared<Exponent>()},
        {"LN", std::make_shared<LogNaturel>()},
    };

    if (operateurMap_.find(symbol) == operateurMap_.end())
    {
        return nullptr;
    }
    return operateurMap_.at(symbol).get();
}
