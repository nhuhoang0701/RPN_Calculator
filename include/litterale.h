#ifndef __LITTERALE_H__
#define __LITTERALE_H__

#include <memory>
#include <QString>

/*
** Litterale classe
*/
class Litterale
{
public:
    virtual ~Litterale() {}

    virtual const QString affichage() const = 0;
    virtual bool isNull() const = 0;
};

enum class TypeLitterale
{
    ENTIER,
    RATIONNEL,
    REEL,
    COMPLEXE,
};

/*
** LitteraleNombre classe
*/
class LitteraleNombre : public Litterale
{
public:
    virtual bool isPos() const = 0;

    virtual TypeLitterale getType() const { return typeLitterale_; }
    virtual LitteraleNombre *cloneOnHeap() const = 0;
    virtual LitteraleNombre *simplifier() = 0;
    // virtual LitteraleNombre *convertToComplexe() = 0;
    // virtual LitteraleNombre *operator+(LitteraleNombre &l) = 0;

protected:
    TypeLitterale typeLitterale_;
};

/*
** LitteraleNumerique classe compose LitteraleEntiere, LitteraleRationnelle, LitteraleReelle
*/
class LitteraleNumerique : public LitteraleNombre
{
    static LitteraleNumerique *a;
    static LitteraleNumerique *b;

public:
    // typedef LitteraleNumerique* (*fonc_t)(LitteraleNumerique&, LitteraleNumerique&);
    virtual LitteraleNumerique *operator+(LitteraleNumerique &l)
    {
        calculation(l);
        return *a + *b;
    }
    virtual LitteraleNumerique *operator-(LitteraleNumerique &l)
    {
        calculation(l);
        return *a - *b;
    }
    virtual LitteraleNumerique *operator*(LitteraleNumerique &l)
    {
        calculation(l);
        return *a * *b;
    }
    virtual LitteraleNumerique *operator/(LitteraleNumerique &l)
    {
        calculation(l);
        return *a / *b;
    }

    void calculation(LitteraleNumerique &l)
    {
        int typeMaxInt = std::max(static_cast<int>(getType()), static_cast<int>(l.getType()));
        TypeLitterale typeMax = static_cast<TypeLitterale>(typeMaxInt);
        a = convertToNumerique(typeMax);
        b = l.convertToNumerique(typeMax);
    }

    virtual LitteraleNumerique *cloneOnHeap() const = 0;
    virtual LitteraleNumerique *convertToNumerique(TypeLitterale type) = 0;
    // virtual double getValeur() const = 0;
    virtual LitteraleNumerique *simplifier() = 0;
    // virtual const LitteraleComplexe *convertToComplexe() const = 0;
};

#endif // __LITTERALE_H__
