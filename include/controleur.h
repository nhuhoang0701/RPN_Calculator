#ifndef __CONTROLEUR__H__
#define __CONTROLEUR__H__

#include <QString>
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
    identifieurMap_t identifieurMap_;
    unsigned int historyIndex_;
    std::vector<Pile> pileHistory_;
    bool redoable_;

    Controleur() : litteraleAffiche_{std::make_unique<Pile>()}, historyIndex_{0}, redoable_{false} {}

public:
    static Controleur &getInstance();

    Pile &getPile() { return *litteraleAffiche_; }
    identifieurMap_t *getIdentifieurMap() { return &identifieurMap_; }

    void commande(const QString &c);
    bool estOperateurNumerique(const QString &s);
    bool estOperateurAccessible(const QString &s);
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
