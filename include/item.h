#ifndef __ITEM_H__
#define __ITEM_H__

#include "litterale.h"
#include "exceptions.h"

class Item
{
private:
    Litterale *litterale_;

public:
    Item(Litterale *litterale = nullptr) : litterale_{litterale} {}
    void erase() { litterale_ == nullptr; }
    void setLitterale(Litterale &litterale)
    {
        litterale_ = &litterale;
    }
    Litterale &getLitterale() const
    {
        if (litterale_ == nullptr)
        {
            throw CalculateurException{"Item points to null pointer"};
        }
        return *litterale_;
    }
};

#endif // __ITEM_H__
