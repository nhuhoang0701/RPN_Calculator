#ifndef __OPERATEUR_NUMERIQUE_H__
#define __OPERATEUR_NUMERIQUE_H__

#include <QString>
#include <iostream>

#include "operateur_binaire.h"
#include "litterale_entiere.h"
#include "litterale_reelle.h"

// Addition operateur
Addition::Addition() : OperateurBinaire{"+"} {}

LitteraleNombre *Addition::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    return *arguments[0]->evaluer() + *arguments[1]->evaluer();
}

// Soustraction operateur
Soustraction::Soustraction() : OperateurBinaire{"-"} {}

LitteraleNombre *Soustraction::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    return *arguments[0]->evaluer() - *arguments[1]->evaluer();
}

// Multiplication operateur
Multiplication::Multiplication() : OperateurBinaire{"*"} {}

LitteraleNombre *Multiplication::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    return *arguments[0]->evaluer() * *arguments[1]->evaluer();
}

// Division operateur
Division::Division() : OperateurBinaire{"/"} {}

LitteraleNombre *Division::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    return *arguments[0]->evaluer() / *arguments[1]->evaluer();
}

// Quotient operateur
Quotient::Quotient() : OperateurBinaire{"DIV"} {}

LitteraleNombre *Quotient::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    std::string argument0 = arguments[0]->affichage().toStdString();
    std::string argument1 = arguments[1]->affichage().toStdString();
    if (arguments[0]->getType() != TypeLitterale::ENTIER &&
        arguments[1]->getType() != TypeLitterale::ENTIER)
    {
        throw CalculateurException(
            ("Operande DIV réaquis 2 entiers, " + argument0 + " et " + argument1 + " sont passés!").c_str());
    }

    if (arguments[0]->getType() != TypeLitterale::ENTIER)
    {
        throw CalculateurException(
            ("Operande DIV réaquis 2 entiers, opérande première " + argument0 + " est passé!").c_str());
    }
    if (arguments[1]->getType() != TypeLitterale::ENTIER)
    {
        throw CalculateurException(
            ("Operande DIV réaquis 2 entiers, opérande seconde " + argument1 + " est passé!").c_str());
    }
    if (arguments[1]->evaluer()->affichage().toInt() == 0)
    {
        throw CalculateurException("Impossible de faire opérande DIV sur 0");
    }
    return new LitteraleEntier{arguments[0]->evaluer()->affichage().toInt() /
                               arguments[1]->evaluer()->affichage().toInt()};
}

// Module opérateur
Module::Module() : OperateurBinaire{"MOD"} {}

LitteraleNombre *Module::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    std::string argument0 = arguments[0]->affichage().toStdString();
    std::string argument1 = arguments[1]->affichage().toStdString();
    if (arguments[0]->getType() != TypeLitterale::ENTIER &&
        arguments[1]->getType() != TypeLitterale::ENTIER)
    {
        throw CalculateurException(
            ("Operande DIV réaquis 2 entiers, " + argument0 + " et " + argument1 + " sont passés!").c_str());
    }

    if (arguments[0]->getType() != TypeLitterale::ENTIER)
    {
        throw CalculateurException(
            ("Operande DIV réaquis 2 entiers, opérande première " + argument0 + " est passé!").c_str());
    }
    if (arguments[1]->getType() != TypeLitterale::ENTIER)
    {
        throw CalculateurException(
            ("Operande DIV réaquis 2 entiers, opérande seconde " + argument1 + " est passé!").c_str());
    }
    if (arguments[1]->evaluer()->affichage().toInt() == 0)
    {
        throw CalculateurException("Impossible de faire opérande MOD sur 0");
    }
    return new LitteraleEntier{arguments[0]->evaluer()->affichage().toInt() %
                               arguments[1]->evaluer()->affichage().toInt()};
}

// Pow opérateur
Power::Power() : OperateurBinaire{"POW"} {}

LitteraleNombre *Power::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    if (arguments[1]->evaluer()->getType() == TypeLitterale::COMPLEXE)
    {
        throw CalculateurException(
            ("Numéro d'index ne faut pas complexe, " + arguments[1]->affichage().toStdString() + " passé!").c_str());
    }
    LitteraleNumerique *index = dynamic_cast<LitteraleNumerique *>(arguments[1]->evaluer());
    LitteraleReelle *indexReel = dynamic_cast<LitteraleReelle *>(index->convertToNumerique(TypeLitterale::REEL));
    return arguments[0]->evaluer()->puissance(*indexReel);
}

// Egalite opérateur
Egalite::Egalite() : OperateurBinaire{"=="} {}

LitteraleNombre *Egalite::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    LitteraleNombre *difference = *arguments[0]->evaluer() - *arguments[1]->evaluer();
    return (difference->isNull() ? new LitteraleEntier{1} : new LitteraleEntier{0});
}

// Inégalité opérateur
Inegalite::Inegalite() : OperateurBinaire{"!="} {}

LitteraleNombre *Inegalite::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    LitteraleNombre *difference = *arguments[0]->evaluer() - *arguments[1]->evaluer();
    return (difference->isNull() ? new LitteraleEntier{0} : new LitteraleEntier{1});
}

// Inférieur ou égal opérateur
InferieurOuEgal::InferieurOuEgal() : OperateurBinaire{"=<"} {}

LitteraleNombre *InferieurOuEgal::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    LitteraleNombre *difference = *arguments[0]->evaluer() - *arguments[1]->evaluer();
    return (difference->isPos() ? new LitteraleEntier{0} : new LitteraleEntier{1});
}

// Supérieur ou égal opérateur
SuperieurOuEgal::SuperieurOuEgal() : OperateurBinaire{">="} {}

LitteraleNombre *SuperieurOuEgal::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    LitteraleNombre *difference = *arguments[0]->evaluer() - *arguments[1]->evaluer();
    return (difference->isPos() || difference->isNull() ? new LitteraleEntier{1} : new LitteraleEntier{0});
}

// Inférieur opérateur
Inferieur::Inferieur() : OperateurBinaire{"<"} {}

LitteraleNombre *Inferieur::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    LitteraleNombre *difference = *arguments[0]->evaluer() - *arguments[1]->evaluer();
    return (difference->isPos() || difference->isNull() ? new LitteraleEntier{0} : new LitteraleEntier{1});
}

// Supérieur opérateur
Superieur::Superieur() : OperateurBinaire{">"} {}

LitteraleNombre *Superieur::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    LitteraleNombre *difference = *arguments[0]->evaluer() - *arguments[1]->evaluer();
    return (difference->isPos() ? new LitteraleEntier{1} : new LitteraleEntier{0});
}

// AND opérateur
And::And() : OperateurBinaire{"AND"} {}

LitteraleNombre *And::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    return (arguments[0]->isNull() || arguments[1]->isNull() ? new LitteraleEntier{0} : new LitteraleEntier{1});
}

// Or opérateur
Or::Or() : OperateurBinaire{"OR"} {}

LitteraleNombre *Or::traitement(std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    checkNul(arguments);
    checkNotProgramme(arguments);
    return (arguments[0]->isNull() && arguments[1]->isNull() ? new LitteraleEntier{0} : new LitteraleEntier{1});
}

#endif // __OPERATEUR_NUMERIQUE_H__
