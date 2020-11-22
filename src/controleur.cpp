#include <QRegExp>
#include <QStringList>
#include <iostream>
#include <deque>
#include <stack>

#include "controleur.h"
#include "litterale_entiere.h"
#include "litterale_rationnelle.h"
#include "litterale_reelle.h"
#include "operateur_binaire.h"

Controleur &Controleur::getInstance()
{
    static Controleur instance_ = Controleur{};
    return instance_;
}

bool Controleur::estOperateur(const QString &s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/")
    {
        return true;
    }
    return false;
}

TypeLitterale Controleur::estLitterale(const QString &s)
{
    if (!s.size())
    {
        return TypeLitterale::NONE;
    }
    bool flag = false;
    s.toInt(&flag);
    if (flag)
    {
        return TypeLitterale::ENTIER;
    }
    s.toDouble(&flag);
    if (flag)
    {
        return TypeLitterale::REEL;
    }
    if (s[0] == '\'' && s.back() == '\'')
    {
        return TypeLitterale::EXPRESSION;
    }
    return TypeLitterale::NONE;
}

bool Controleur::estLitteraleAtome(const QString &s)
{
}

Litterale *Controleur::creerLitterale(QString str, TypeLitterale type)
{
    if (type == TypeLitterale::ENTIER)
    {
        return new LitteraleEntier{str.toInt()};
    }
    else if (type == TypeLitterale::REEL)
    {
        return new LitteraleReelle{str.toDouble()};
    }
}


QString Controleur::commande(const QString &c)
{
    std::unique_ptr<Pile> pileCopy{litteraleAffiche_->cloneOnHeap()};

    QRegExp regex{"(\\ )"};
    QStringList listOperande = c.split(regex, QString::SkipEmptyParts);
    for (size_t i = 0; i < listOperande.size(); i++)
    {
        TypeLitterale type = estLitterale(listOperande[i]);
        if (type != TypeLitterale::NONE)
        {
            // std::cout << "Littrale" << '\n';
            litteraleAffiche_->push(*creerLitterale(listOperande[i], type));
        }
        else
        {
            // std::cout << "Operateur" << '\n';
            Operateur *op = Operateur::getOperateur(listOperande[i]);
            if (op != nullptr)
            {
                int arite = op->getArite();
                std::vector<Litterale *> arguments{};
                while (arite-- != 0 && !litteraleAffiche_->estVide())
                {
                    arguments.insert(arguments.begin(), litteraleAffiche_->top().cloneOnHeap());
                    litteraleAffiche_->pop();
                }
                try
                {
                    LitteraleNombre *lit = op->traitement(arguments);
                    litteraleAffiche_->push(*lit);
                }
                catch (const CalculateurException &e)
                {
                    litteraleAffiche_ = std::move(pileCopy);
                    throw;
                }
            }
        }
    }
    // litteraleAffiche_->affichage();
    return QString("Dump");
    throw CalculateurException("Impossible de traiter cetter commande!");
}

void Controleur::save()
{
}

void Controleur::loadPrecedent()
{
}

void Controleur::loadSuivant()
{
}

void Controleur::reload()
{
}
