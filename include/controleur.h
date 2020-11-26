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
#include "memento_pile.h"

using identifieurMap_t = std::map<QString, LitteraleExpression *>;

class Controleur
{
    Pile *litteraleAffiche_;
    identifieurMap_t identifieurMap_;

    std::unique_ptr<CareTakerPile> careTakerPile_;
    unsigned int historyIndex_;

    Controleur() : litteraleAffiche_{new Pile{}}, historyIndex_{0},
                   careTakerPile_{std::make_unique<CareTakerPile>()}
    {
        MementoPile *memento = new MementoPile{*litteraleAffiche_};
        careTakerPile_->addMementoPile(*memento, historyIndex_);
    }

public:
    static Controleur &getInstance();

    Pile &getPile() { return *litteraleAffiche_; }
    identifieurMap_t *getIdentifieurMap() { return &identifieurMap_; }

    void traiterCommandBar(const QString &c);
    TypeLitterale estLitterale(const QString &s);
    bool estIdentifieur(const QString &s);
    bool estOperateurNumerique(const QString &s);
    bool estOperateurAccessible(const QString &s);
    bool checkOperateurPile(const QString &s);

    QStringList toLitteraleEtOperateur(const QString &s);
    Litterale *creerLitterale(QString str, TypeLitterale type);

    void loadPrecedent();
    void loadSuivant();
};

#endif // __CONTROLEUR__H__
