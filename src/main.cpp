#include <iostream>

#include <QApplication>
#include "exceptions.h"
#include "controleur.h"
#include "litterale_entiere.h"
#include "litterale_rationnelle.h"
#include "litterale_reelle.h"
#include "litterale_complexe.h"
#include "operateur.h"
#include "operateur_binaire.h"
#include "qcalculateur.h"
#include "pile.h"

class Base
{
};
int main(int argc, char *argv[])
{
    LitteraleNombre *r1 = new LitteraleRationnelle{-20, -30};
    LitteraleNombre *r2 = new LitteraleReelle{123.34};
    LitteraleNombre *r3 = new LitteraleEntier{34};
    LitteraleNombre *r4 = new LitteraleRationnelle{12, 34};
    LitteraleEntier* r5 = new LitteraleEntier{4};
    LitteraleNombre *c1 = new LitteraleComplexe{r1->cloneOnHeap(), r2->cloneOnHeap()};
    LitteraleNombre *c2 = new LitteraleComplexe{r3->cloneOnHeap(), r4->cloneOnHeap()};
    Pile p = Pile{};
    p.push(*r1);
    p.push(*r2);
    p.push(*r3);
    p.push(*c2);
    PileIterator pitr = PileIterator{&p};
    for (auto itr = pitr.begin(); itr != pitr.end(); itr++)
    {
        //    std::cout << (*itr)->affichage().toStdString() << '\n';
    }
    // p.affichage();
    // std::cout << r3->affichage().toStdString() << '\n';
    // std::cout << (*r2 / *r2)->affichage().toStdString() << '\n';
    // std::cout << (*r3 - *r4)->affichage().toStdString() << '\n';
    // std::cout << (*c2 - *c1)->affichage().toStdString() << '\n';
    Operateur *op = new Power{};
    // std::cout << op->traitement(std::vector<Litterale *>{r1, r4})->affichage().toStdString() << '\n';
    try
    {
        // std::cout << op->traitement(std::vector<Litterale *>{r1, c2})->affichage().toStdString();
        // Controleur &controleur = Controleur::getInstance();
        // std::cout << controleur.commande("1 2.5 12 /").toStdString() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    QApplication app = QApplication{argc, argv};
    QCalculateur cal = QCalculateur();
    cal.show();
    return app.exec();
}
