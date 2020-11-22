#include "pile.h"

unsigned int Pile::nombreAffiche_ = 10;

Pile::~Pile()
{
    for (auto &p : litteralePile_)
    {
        delete p;
    }
    litteralePile_.clear();
}

Litterale &Pile::top() const
{
    if (litteralePile_.size() == 0)
    {
        throw CalculateurException{"Il n'y a aucun item dans le pile!"};
    }
    return *litteralePile_.back();
}

void Pile::push(Litterale &litterale)
{
    litteralePile_.push_back(&litterale);
}

void Pile::pop()
{
    if (litteralePile_.size() == 0)
    {
        throw CalculateurException{"Il n'y a aucun item dans le pile!"};
    }
    Litterale *topLitterale = &top();
    delete topLitterale;
    litteralePile_.pop_back();
}

PileIterator PileIterator::begin()
{
    PileIterator temp = PileIterator{pile_};
    temp.iterator_ = pile_->litteralePile_.rbegin();
    return temp;
}

PileIterator PileIterator::end()
{
    PileIterator temp = PileIterator{pile_};
    temp.iterator_ = pile_->litteralePile_.rend();
    return temp;
}

bool PileIterator::operator!=(const PileIterator &p)
{
    return iterator_ != p.iterator_;
}

PileIterator PileIterator::operator++(int)
{
    PileIterator temp = PileIterator{pile_};
    temp.iterator_ = ++iterator_;
    return temp;
}

Litterale *PileIterator::operator*()
{
    return *iterator_;
}
