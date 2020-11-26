
#include <cmath>
#include <functional>

#include "operateur_unaire.h"
#include "litterale_entiere.h"

OperateurUnaire::OperateurUnaire(const QString &symbol) : OperateurNumerique{1, symbol} {}

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
    checkPrequisite(arguments);
    return (arguments[0]->evaluer()->traiterUnaireSpeciale("NUM"));
}

// DEN opérateur
Denominateur::Denominateur() : OperateurUnaire{"DEN"} {}

LitteraleNombre *Denominateur::traitement(std::vector<Litterale *> &arguments)
{
    checkPrequisite(arguments);
    return (arguments[0]->evaluer()->traiterUnaireSpeciale("DEN"));
}

// SQRT opérateur
Sqrt::Sqrt() : OperateurUnaire{"SQRT"} {}

LitteraleNombre *Sqrt::traitement(std::vector<Litterale *> &arguments)
{
    checkPrequisite(arguments);
    return (arguments[0]->evaluer()->traiterUnaireSpeciale("SQRT"));
}

// NEG opérateur
Negative::Negative() : OperateurUnaire{"NEG"} {}

LitteraleNombre *Negative::traitement(std::vector<Litterale *> &arguments)
{
    checkPrequisite(arguments);
    return (arguments[0]->evaluer()->traiterUnaireSpeciale("NEG"));
}

// SIN opérateur
Sin::Sin() : OperateurUnaire{"SIN"} {}

LitteraleNombre *Sin::traitement(std::vector<Litterale *> &arguments)
{
    checkPrequisite(arguments);
    return arguments[0]->traiterTrigonometrique([](double x) { return std::sin(x); }, "SIN");
}

// COS opérateur
Cos::Cos() : OperateurUnaire{"COS"} {}

LitteraleNombre *Cos::traitement(std::vector<Litterale *> &arguments)
{
    checkPrequisite(arguments);
    return arguments[0]->traiterTrigonometrique([](double x) { return std::cos(x); }, "COS");
}

// TAN opérateur
Tan::Tan() : OperateurUnaire{"TAN"} {}

LitteraleNombre *Tan::traitement(std::vector<Litterale *> &arguments)
{
    checkPrequisite(arguments);
    return arguments[0]->traiterTrigonometrique([](double x) { return std::tan(x); }, "TAN");
}

// ARCSIN opérateur
Arcsin::Arcsin() : OperateurUnaire{"ARCSIN"} {}

LitteraleNombre *Arcsin::traitement(std::vector<Litterale *> &arguments)
{
    checkPrequisite(arguments);
    return arguments[0]->traiterTrigonometrique([](double x) { return std::asin(x); }, "ARCSIN");
}

// ARCCOS opérateur
Arccos::Arccos() : OperateurUnaire{"ARCCOS"} {}

LitteraleNombre *Arccos::traitement(std::vector<Litterale *> &arguments)
{
    checkPrequisite(arguments);
    return arguments[0]->traiterTrigonometrique([](double x) { return std::acos(x); }, "ARCCOS");
}

// ARCTAN opérateur
Arctan::Arctan() : OperateurUnaire{"ARCTAN"} {}

LitteraleNombre *Arctan::traitement(std::vector<Litterale *> &arguments)
{
    checkPrequisite(arguments);
    return arguments[0]->traiterTrigonometrique([](double x) { return std::atan(x); }, "ARCTAN");
}

// IM opérateur
Imagine::Imagine() : OperateurUnaire{"IM"} {}

LitteraleNombre *Imagine::traitement(std::vector<Litterale *> &arguments)
{
    checkPrequisite(arguments);
    return (arguments[0]->evaluer()->traiterUnaireSpeciale("IM"));
}

// EXP opérateur
Exponent::Exponent() : OperateurUnaire{"EXP"} {}

LitteraleNombre *Exponent::traitement(std::vector<Litterale *> &arguments)
{
    checkPrequisite(arguments);
    return (arguments[0]->evaluer()->traiterUnaireSpeciale("EXP"));
}

// LN opérateur
LogNaturel::LogNaturel() : OperateurUnaire{"LN"} {}

LitteraleNombre *LogNaturel::traitement(std::vector<Litterale *> &arguments)
{
    checkPrequisite(arguments);
    return (arguments[0]->evaluer()->traiterUnaireSpeciale("LN"));
}
