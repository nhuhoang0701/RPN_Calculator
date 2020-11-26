#ifndef __MEMENTO_PILE_H__
#define __MEMENTO_PILE_H__

#include "pile.h"

class MementoPile
{
private:
    Pile *etatPile_;

public:
    MementoPile(Pile &pile) { etatPile_ = pile.cloneOnHeapGeneral(); }
    Pile &getEtatPile() const { return *etatPile_; }
    ~MementoPile() { delete etatPile_; }
};

class CareTakerPile
{
    std::vector<MementoPile *> historiquePile_;

public:
    void addMementoPile(MementoPile &etat, unsigned int index)
    {
        if (index < getTailleHistorique())
        {
            historiquePile_[index] = &etat;
        }
        else
        {
            historiquePile_.push_back(&etat);
        }
    }
    MementoPile &getMementoPile(unsigned int index) const { return *historiquePile_[index]; }
    unsigned int getTailleHistorique() const { return historiquePile_.size(); }
    void pop() { historiquePile_.pop_back(); }
};
#endif // __MEMENTO_PILE_H__
