#ifndef __OPERATEUR_NUMERIQUE_H__
#define __OPERATEUR_NUMERIQUE_H__

#include "operateur_numerique.h"

// Addition operateur
Addition::Addition() : OperateurNumerique{2, "+"} {}

LitteraleNombre *Addition::traitement(const std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    return *arguments[0]->evaluer() + *arguments[1]->evaluer();
}

// Soustraction operateur
Soustraction::Soustraction() : OperateurNumerique{2, "-"} {}

LitteraleNombre *Soustraction::traitement(const std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    return *arguments[0]->evaluer() - *arguments[1]->evaluer();
}

// Multiplication operateur
Multiplication::Multiplication() : OperateurNumerique{2, "*"} {}

LitteraleNombre *Multiplication::traitement(const std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    return *arguments[0]->evaluer() * *arguments[1]->evaluer();
}

// Division operateur
Division::Division() : OperateurNumerique{2, "/"} {}

LitteraleNombre *Division::traitement(const std::vector<Litterale *> &arguments)
{
    checkArite(arguments.size());
    return *arguments[0]->evaluer() / *arguments[1]->evaluer();
}

#endif // __OPERATEUR_NUMERIQUE_H__
