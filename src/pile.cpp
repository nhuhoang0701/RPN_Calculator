#include "pile.h"

unsigned int Pile::nombreAffiche_ = 5;

Litterale &Pile::top() const
{
    if (nombre_ == 0)
    {
        throw CalculateurException{"Il n'y a aucun item dans le pile!"};
    }
    return items_[nombre_ - 1]->getLitterale();
}

void Pile::push(Litterale &litterale)
{
    auto item = std::make_unique<Item>(&litterale);
    items_.push_back(std::move(item));
}

void Pile::pop()
{
    if (nombre_ == 0)
    {
        throw CalculateurException{"Il n'y a aucun item dans le pile!"};
    }
    items_.pop_back();
}
