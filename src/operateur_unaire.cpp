#ifndef __OPERATEUR_UNAIRE_H__
#define __OPERATEUR_UNAIRE_H__

#include "operateur_unaire.h"
#include "litterale_entiere.h"

OperateurUnaire::OperateurUnaire(const QString &symbol) : Operateur{1, symbol} {}

// NOT opérateur
Not::Not() : OperateurUnaire{"NOT"} {}

LitteraleNombre *Not::traitement(std::vector<Litterale *> &arguments)
{
    checkPrequisite(arguments);
    return (arguments[0]->evaluer()->isNull() ? new LitteraleEntier{1} : new LitteraleEntier{0});
}

// NUM opérateur
Numerateur::Numerateur() : OperateurUnaire{"NUM"} {}

LitteraleNombre *Numerateur::traitement(std::vector<Litterale *> &arguments)
{
}

// DEN opérateur
Denominateur::Denominateur() : OperateurUnaire{"DEN"} {}

LitteraleNombre *Denominateur::traitement(std::vector<Litterale *> &arguments)
{
}

// SQRT opérateur
Sqrt::Sqrt() : OperateurUnaire{"SQRT"} {}

LitteraleNombre *Sqrt::traitement(std::vector<Litterale *> &arguments)
{
}

// NEG opérateur
Negative::Negative() : OperateurUnaire{"NEG"} {}

LitteraleNombre *Negative::traitement(std::vector<Litterale *> &arguments)
{
}

// SIN opérateur
Sin::Sin() : OperateurUnaire{"SIN"} {}

LitteraleNombre *Sin::traitement(std::vector<Litterale *> &arguments)
{
}

// COS opérateur
Cos::Cos() : OperateurUnaire{"COS"} {}

LitteraleNombre *Cos::traitement(std::vector<Litterale *> &arguments)
{
}

// TAN opérateur
Tan::Tan() : OperateurUnaire{"TAN"} {}

LitteraleNombre *Tan::traitement(std::vector<Litterale *> &arguments)
{
}

// ARCSIN opérateur
Arcsin::Arcsin() : OperateurUnaire{"ARCSIN"} {}

LitteraleNombre *Arcsin::traitement(std::vector<Litterale *> &arguments)
{
}

// ARCCOS opérateur
Arccos::Arccos() : OperateurUnaire{"ARCCOS"} {}

LitteraleNombre *Arccos::traitement(std::vector<Litterale *> &arguments)
{
}

// ARCTAN opérateur
Arctan::Arctan() : OperateurUnaire{"ARCTAN"} {}

LitteraleNombre *Arctan::traitement(std::vector<Litterale *> &arguments)
{
}

// IM opérateur
Imagine::Imagine() : OperateurUnaire{"IM"} {}

LitteraleNombre *Imagine::traitement(std::vector<Litterale *> &arguments)
{
}

// EXP opérateur
Exponent::Exponent() : OperateurUnaire{"EXP"} {}

LitteraleNombre *Exponent::traitement(std::vector<Litterale *> &arguments)
{
}

// LN opérateur
LogNaturel::LogNaturel() : OperateurUnaire{"LN"} {}

LitteraleNombre *LogNaturel::traitement(std::vector<Litterale *> &arguments)
{
}

#endif // __OPERATEUR_UNAIRE_H__
