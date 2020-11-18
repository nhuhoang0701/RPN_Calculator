#include <iostream>

#include "exceptions.h"
#include "litterale_entiere.h"
#include "litterale_rationnelle.h"
#include "litterale_reelle.h"

class Base
{
};
int main(int argc, char *argv[])
{
    LitteraleNumerique *r1 = new LitteraleRationnelle{-20, -30};
    LitteraleNumerique *r2 = new LitteraleReelle{123.34};
    LitteraleNumerique *r3 = new LitteraleEntier{34};
    LitteraleNumerique *r4 = new LitteraleRationnelle{12, 34};
    std::cout << (*r1 + *r2)->affichage().toStdString() << '\n';
    std::cout << (*r3 + *r4)->affichage().toStdString() << '\n';
    // LitteraleNumerique *r2 = new LitteraleEntier{12};
    // std::cout << (*r1 - *r3)->affichage().toStdString() << '\n';
    // std::cout << (c2->getType() == TypeLitterale::COMPLEXE) << '\n';
}
