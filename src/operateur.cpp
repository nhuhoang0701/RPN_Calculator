#include <map>
#include <iostream>
#include <memory>

#include "operateur.h"
#include "operateur_binaire.h"
#include "operateur_unaire.h"

void Operateur::checkArite(unsigned int taille)
{
    std::string message = "Opérande " + symbol_.toStdString() + " demande " + std::to_string(arite_) +
                          " arguments, " + std::to_string(taille) + " passé(s)!";

    if (arite_ != taille)
    {
        throw CalculateurException{message.c_str()};
    }
}

Operateur *Operateur::getOperateur(const QString &symbol)
{
    static std::map<QString, std::shared_ptr<Operateur>> operateurMap_ = {
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
    };

    if (operateurMap_.find(symbol) == operateurMap_.end())
    {
        std::cout << "Not found operator" << '\n';
        return nullptr;
    }
    return operateurMap_.at(symbol).get();
}
