#ifndef __PILE_H__
#define __PILE_H__

#include <memory>
#include <iostream>
#include <list>
#include <QString>

#include "exceptions.h"
#include "litterale.h"

class PileIterator;

class Pile
{
private:
    std::list<Litterale *> litteralePile_;
    static unsigned int nombreAffiche_;
    QString message_;

public:
    friend PileIterator;
    ~Pile();

    bool estVide() const { return litteralePile_.size() == 0; }
    unsigned int getTaille() const { return litteralePile_.size(); }
    void setMessage(const QString &message) { message_ = message; }
    QString getMessage() const { return message_; }
    static void setNombreItemsAffiche(unsigned int nombreAffiche) { nombreAffiche_ = nombreAffiche; }
    static unsigned int getNombreItemsAffiche() { return nombreAffiche_; }

    Litterale &top() const;
    void push(Litterale &litterale);
    void pop();
    void affichage()
    {
        for (auto &p : litteralePile_)
        {
            std::cout << p->affichage().toStdString() << '\n';
        }
    }
};

class PileIterator
{
private:
    Pile *pile_;
    std::list<Litterale *>::reverse_iterator iterator_;

public:
    PileIterator(Pile *pile)
        : pile_{pile} {}
    PileIterator begin();
    PileIterator end();
    PileIterator operator++(int);
    bool operator!=(const PileIterator& p);
    Litterale *operator*();
};

#endif // __PILE_H_
