#ifndef __CONTROLEUR__H__
#define __CONTROLEUR__H__

#include <QString>
#include <QObject>
#include <QList>
#include <QRegExp>
#include <QStringList>
#include <map>
#include <memory>

#include "exceptions.h"
#include "litterale.h"
#include "operateur.h"
#include "pile.h"

class Controleur
{
    std::unique_ptr<Pile> litteraleAffiche_;
    // operateurManager &opeMng;
    // CareTaker careTaker;
    unsigned int history_index;
    std::map<QString, Operateur *> mapAtome;

    Controleur() : litteraleAffiche_{std::make_unique<Pile>()} {}
    // Controleur(operateurManager &o, Pile &v) : littAff(v), history_index(0)
    // {
    //     QRegExp rx("^[A-Z]([A-Z]|[0-9])*");
    // for (operateurManager::iterator it = opeMng.begin(); it != opeMng.end(); ++it)
    // {
    //     if (rx.exactMatch((*it).getSymbol()))
    //         mapAtome.insert((*it).getSymbol(), &(*it));
    // }
    // save();
    // }
    // Controleur(Controleur &c) : littAff(c.littAff), opeMng(c.opeMng), careTaker(), history_index(0) {}

public:
    static Controleur &getInstance();

    Pile &getPile() { return *litteraleAffiche_; }

    QString commande(const QString &c);
    bool estOperateurNumerique(const QString &s);
    TypeLitterale estLitterale(const QString &s);
    bool estLitteraleAtome(const QString &s);
    // QList<Operateur *> FactoryMethod(QString str);
    Litterale *creerLitterale(QString str, TypeLitterale type);
    Operateur *creerOperateur(QString str);

    // Memento &saveEtatToMemento(Pile &p) { return *(new Memento(p)); }
    void save();
    void loadPrecedent();
    void loadSuivant();
    void reload();
};

#endif // __CONTROLEUR__H__
