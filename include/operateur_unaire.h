#include <QString>

#include "operateur.h"

class OperateurUnaire : public Operateur
{
private:
public:
    OperateurUnaire(const QString &symbol);
    void checkPrequisite(std::vector<Litterale *> &arguments)
    {
        // Tester le taille du vecteur arguments
        if (arguments.size() != 1)
        {
            std::string message = "Opérande " + getSymbol().toStdString() + " réaquis 1 argument, " +
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
};

// NOT opérateur
class Not : public OperateurUnaire
{
    Not();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// NUM opérateur
class Numerateur : public OperateurUnaire
{
    Numerateur();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// DEN opérateur
class Denominateur : public OperateurUnaire
{
    Denominateur();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// SQRT opérateur
class Sqrt : public OperateurUnaire
{
    Sqrt();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// NEG opérateur
class Negative : public OperateurUnaire
{
    Negative();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// SIN opérateur
class Sin : public OperateurUnaire
{
    Sin();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// COS opérateur
class Cos : public OperateurUnaire
{
    Cos();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// TAN opérateur
class Tan : public OperateurUnaire
{
    Tan();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// ARCSIN opérateur
class Arcsin : public OperateurUnaire
{
    Arcsin();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// ARCCOS opérateur
class Arccos : public OperateurUnaire
{
    Arccos();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// ARCTAN opérateur
class Arctan : public OperateurUnaire
{
    Arctan();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// IM opérateur
class Imagine : public OperateurUnaire
{
    Imagine();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// EXP opérateur
class Exponent : public OperateurUnaire
{
    Exponent();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};

// LN opérateur
class LogNaturel : public OperateurUnaire
{
    LogNaturel();
    LitteraleNombre *traitement(std::vector<Litterale *> &arguments) override;
};
