#ifndef __OPERATEUR_UNAIRE_H__
#define __OPERATEUR_UNAIRE_H__

#include <QString>

#include "operateur_numerique.h"

class OperateurUnaire : public OperateurNumerique
{
private:
public:
    OperateurUnaire(const QString &symbol);
};

// NOT opérateur
class Not : public OperateurUnaire
{
public:
    Not();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// NUM opérateur
class Numerateur : public OperateurUnaire
{
public:
    Numerateur();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// DEN opérateur
class Denominateur : public OperateurUnaire
{
public:
    Denominateur();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// SQRT opérateur
class Sqrt : public OperateurUnaire
{
public:
    Sqrt();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// NEG opérateur
class Negative : public OperateurUnaire
{
public:
    Negative();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// SIN opérateur
class Sin : public OperateurUnaire
{
public:
    Sin();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// COS opérateur
class Cos : public OperateurUnaire
{
public:
    Cos();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// TAN opérateur
class Tan : public OperateurUnaire
{
public:
    Tan();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// ARCSIN opérateur
class Arcsin : public OperateurUnaire
{
public:
    Arcsin();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// ARCCOS opérateur
class Arccos : public OperateurUnaire
{
public:
    Arccos();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// ARCTAN opérateur
class Arctan : public OperateurUnaire
{
public:
    Arctan();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// IM opérateur
class Imagine : public OperateurUnaire
{
public:
    Imagine();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// EXP opérateur
class Exponent : public OperateurUnaire
{
public:
    Exponent();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// LN opérateur
class LogNaturel : public OperateurUnaire
{
public:
    LogNaturel();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

#endif // __OPERATEUR_UNAIRE_H__
