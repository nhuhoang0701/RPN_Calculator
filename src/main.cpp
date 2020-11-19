#include <iostream>

#include "exceptions.h"
#include "litterale_entiere.h"
#include "litterale_rationnelle.h"
#include "litterale_reelle.h"
#include "litterale_complexe.h"
#include "operateur.h"
#include "operateur_numerique.h"

class Base
{
};
int main(int argc, char *argv[])
{
    LitteraleNombre *r1 = new LitteraleRationnelle{-20, -30};
    LitteraleNombre *r2 = new LitteraleReelle{123.34};
    LitteraleNombre *r3 = new LitteraleEntier{34};
    LitteraleNombre *r4 = new LitteraleRationnelle{12, 34};
    LitteraleNombre *c1 = new LitteraleComplexe{r1, r2};
    LitteraleNombre *c2 = new LitteraleComplexe{r3, r4};
    std::cout << r3->affichage().toStdString() << '\n';
    std::cout << (*r2 / *r2)->affichage().toStdString() << '\n';
    std::cout << (*r3 - *r4)->affichage().toStdString() << '\n';
    std::cout << (*c2 - *c2)->affichage().toStdString() << '\n';
    Operateur *op = new Division{};
    try
    {
        std::cout << op->traitement(std::vector<Litterale *>{r1, r2})->affichage().toStdString();
        /* code */
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
