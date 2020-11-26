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
#include "litterale_expression.h"
#include "operateur_numerique.h"
#include "operateur_accessible.h"
#include "pile.h"

using identifieurMap_t = std::map<QString, LitteraleExpression *>;
class Controleur
{
    std::unique_ptr<Pile> litteraleAffiche_;
    // operateurManager &opeMng;
    // CareTaker careTaker;
    unsigned int history_index;
    identifieurMap_t identifieurMap_;

    Controleur() : litteraleAffiche_{std::make_unique<Pile>()} {}
    // Controleur(operateurManager &o, Pile &v) : littAff(v), history_index(0)
    // {
    //     QRegExp rx("^[A-Z]([A-Z]|[0-9])*");
    // for (operateurManager::iterator it = opeMng.begin(); it != opeMng.end(); ++it)
    // {
    //     if (rx.exactMatch((*it).getSymbol()))
    //         identifieurMap_.insert((*it).getSymbol(), &(*it));
    // }
    // save();
    // }
    // Controleur(Controleur &c) : littAff(c.littAff), opeMng(c.opeMng), careTaker(), history_index(0) {}

public:
    static Controleur &getInstance();

    Pile &getPile() { return *litteraleAffiche_; }

    void commande(const QString &c);
    bool estOperateurNumerique(const QString &s);
    bool estOperateurAccessible(const QString& s);
    bool checkOperateurPile(const QString &s);
    TypeLitterale estLitterale(const QString &s);
    bool estIdentifieur(const QString &s);
    QStringList toLitteraleEtOperateur(const QString &s);
    Litterale *creerLitterale(QString str, TypeLitterale type);

    // Memento &saveEtatToMemento(Pile &p) { return *(new Memento(p)); }
    void save();
    void loadPrecedent();
    void loadSuivant();
    void reload();
};

#endif // __CONTROLEUR__H__
