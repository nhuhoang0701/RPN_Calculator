#ifndef __LITTERALE_H__
#define __LITTERALE_H__

#include <memory>
#include <QString>
#include <functional>

#include "exceptions.h"

class LitteraleNombre;

enum class TypeLitterale
{
    ENTIER,
    RATIONNEL,
    REEL,
    COMPLEXE,
    EXPRESSION,
    PROGRAMME,
    NONE,
};

/*
** Litterale classe
*/
class Litterale
{
public:
    virtual ~Litterale() {}
    virtual const QString affichage(QString f = "") const = 0;
    virtual TypeLitterale getType() const { return typeLitterale_; }
    virtual bool isNull() const = 0;
    virtual LitteraleNombre *evaluer() = 0;
    virtual Litterale *cloneOnHeapGeneral() const = 0;
    virtual LitteraleNombre *traiterTrigonometrique(const std::function<double(double)> &fonction, QString operateur)
    {
        Litterale::traiterUnaireSpeciale(operateur);
        return nullptr;
    }
    virtual LitteraleNombre *traiterUnaireSpeciale(QString operateur)
    {
        std::string message = affichage().toStdString() + std::string(" n'a pas l'opérateur ") +
                              operateur.toStdString();
        throw CalculateurException(message.c_str());
        return nullptr;
    }

protected:
    TypeLitterale typeLitterale_;
};

class LitteraleNumerique;
class LitteraleReelle;

/*
** LitteraleNombre classe
*/
class LitteraleNombre : public Litterale
{
public:
    virtual bool isPos() const = 0;
    virtual LitteraleNombre *evaluer() override { return cloneOnHeapNombre(); }
    virtual LitteraleNombre *simplifier() = 0;
    virtual LitteraleNombre *puissance(LitteraleReelle &l) = 0;
    virtual LitteraleNombre *convertToComplexe() = 0;
    virtual LitteraleNombre *cloneOnHeapNombre() const = 0;

    virtual LitteraleNombre *operator+(LitteraleNombre &l) = 0;
    virtual LitteraleNombre *operator-(LitteraleNombre &l) = 0;
    virtual LitteraleNombre *operator*(LitteraleNombre &l) = 0;
    virtual LitteraleNombre *operator/(LitteraleNombre &l) = 0;
};

/*
** LitteraleNumerique classe compose LitteraleEntiere, LitteraleRationnelle, LitteraleReelle
*/
class LitteraleNumerique : public LitteraleNombre
{
    static LitteraleNumerique *a;
    static LitteraleNumerique *b;

public:
    virtual LitteraleNombre *operator+(LitteraleNombre &l)
    {
        if (l.getType() != TypeLitterale::COMPLEXE)
        {
            LitteraleNumerique &l_cast = dynamic_cast<LitteraleNumerique &>(l);
            calculation(l_cast);
            return *a + *b;
        }
        else
        {
            return l + *this;
        }
    }
    virtual LitteraleNombre *operator-(LitteraleNombre &l)
    {
        if (l.getType() != TypeLitterale::COMPLEXE)
        {
            LitteraleNumerique &l_cast = dynamic_cast<LitteraleNumerique &>(l);
            calculation(l_cast);
            return *a - *b;
        }
        else
        {
            return l - *this;
        }
    }
    virtual LitteraleNombre *operator*(LitteraleNombre &l)
    {
        if (l.getType() != TypeLitterale::COMPLEXE)
        {
            LitteraleNumerique &l_cast = dynamic_cast<LitteraleNumerique &>(l);
            calculation(l_cast);
            return *a * *b;
        }
        else
        {
            return l * *this;
        }
    }
    virtual LitteraleNombre *operator/(LitteraleNombre &l)
    {
        if (l.getType() != TypeLitterale::COMPLEXE)
        {
            LitteraleNumerique &l_cast = dynamic_cast<LitteraleNumerique &>(l);
            calculation(l_cast);
            return *a / *b;
        }
        else
        {
            return l / *this;
        }
    }

    void calculation(LitteraleNumerique &l)
    {
        int typeMaxInt = std::max(static_cast<int>(getType()), static_cast<int>(l.getType()));
        TypeLitterale typeMax = static_cast<TypeLitterale>(typeMaxInt);
        a = convertToNumerique(typeMax);
        b = l.convertToNumerique(typeMax);
    }

    virtual Litterale *cloneOnHeapGeneral() const = 0;
    virtual LitteraleNumerique *convertToNumerique(TypeLitterale type) = 0;
    virtual LitteraleNumerique *simplifier() = 0;
};

#endif // __LITTERALE_H__
