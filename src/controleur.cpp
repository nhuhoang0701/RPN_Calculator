#include <QStringList>
#include <iostream>
#include <stack>

#include "controleur.h"
#include "litterale_entiere.h"
#include "litterale_rationnelle.h"
#include "litterale_reelle.h"
#include "litterale_programme.h"
#include "operateur_binaire.h"
#include "operateur_evaluatif.h"

Controleur &Controleur::getInstance()
{
    static Controleur instance_ = Controleur{};
    return instance_;
}

bool Controleur::estOperateurNumerique(const QString &s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/")
    {
        return true;
    }
    if (OperateurNumerique::getOperateurNumerique(s) != nullptr)
    {
        return true;
    }
    return false;
}

bool Controleur::estOperateurAccessible(const QString &s)
{
    if (OperateurAccessible::getOperateurAccessible(s, litteraleAffiche_, &identifieurMap_) != nullptr)
    {
        return true;
    }
    return false;
}

bool Controleur::checkOperateurPile(const QString &s)
{
    if (s == "DUP")
    {
        if (litteraleAffiche_->estVide())
        {
            throw CalculateurException("Le pile est vide, impossible de traiter DUP!");
        }
        Litterale &top = litteraleAffiche_->top();
        if (top.getType() == TypeLitterale::EXPRESSION)
        {
            throw CalculateurException("Impossible de trater DUP sur une littérale expression!");
        }
        litteraleAffiche_->push(*(top.cloneOnHeapGeneral()));
        return true;
    }
    if (s == "DROP")
    {
        if (litteraleAffiche_->estVide())
        {
            throw CalculateurException("Le pile est vide, impossible de traiter DROP!");
        }
        litteraleAffiche_->pop();
        return true;
    }
    if (s == "SWAP")
    {
        if (litteraleAffiche_->getTaille() < 2)
        {
            throw CalculateurException((std::string("Le pile n'a pas assez littérales de traiter SWAP, trouvé ") +
                                        std::to_string(litteraleAffiche_->getTaille()))
                                           .c_str());
        }
        Litterale *t1 = litteraleAffiche_->top().cloneOnHeapGeneral();
        litteraleAffiche_->pop();
        Litterale *t2 = litteraleAffiche_->top().cloneOnHeapGeneral();
        litteraleAffiche_->pop();
        litteraleAffiche_->push(*t1);
        litteraleAffiche_->push(*t2);
        return true;
    }
    if (s == "CLEAR")
    {
        litteraleAffiche_->clearPile();
        return true;
    }
    if (s == "UNDO")
    {
        loadPrecedent();
        return true;
    }
    if (s == "REDO")
    {
        loadSuivant();
        return true;
    }
    return false;
}

TypeLitterale Controleur::estLitterale(const QString &s)
{
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
    if (s[0] == '\'')
    {
        return TypeLitterale::EXPRESSION;
    }
    if (s[0] == '[')
    {
        return TypeLitterale::PROGRAMME;
    }
    return TypeLitterale::NONE;
}

bool Controleur::estIdentifieur(const QString &s)
{
    auto pos = identifieurMap_.find(s);
    if (pos != identifieurMap_.end())
    {
        return true;
    }
    return false;
}

QStringList Controleur::toLitteraleEtOperateur(const QString &s)
{
    std::string str = s.toStdString();
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);

    QStringList list;
    auto first = str.begin(), second = str.begin();

    while (second != str.end())
    {
        if (*first != '[' && *first != '\'')
        {
            second = std::find_if(first, str.end(), [](char c) { return c == ' '; });
            list.push_back(QString::fromStdString(str.substr(first - str.begin(), second - first)));
        }
        else if (*first == '\'')
        {
            second = std::find_if(first + 1, str.end(), [](char c) { return c == '\''; });
            if (second == str.end() || (second != (str.end() - 1) && *(second + 1) != ' '))
            {
                throw CalculateurException("Littérale expression invalide trouvée!");
            }
            list.push_back(QString::fromStdString(str.substr(first - str.begin(), second - first + 1)));
        }
        else if (*first == '[')
        {
            std::string substr;
            do
            {
                second = std::find_if(second + 1, str.end(), [](char c) { return c == ']'; });
                substr = str.substr(first - str.begin(), second - first + 1);
            } while (second != str.end() && (std::count(substr.begin(), substr.end(), '[') !=
                                             std::count(substr.begin(), substr.end(), ']')));

            if (second == str.end() || (second != (str.end() - 1) && *(second + 1) != ' '))
            {
                throw CalculateurException("Programme n'est pas correcte syntaxiquement!");
            }
            list.push_back(QString::fromStdString(substr));
        }
        first = second = std::find_if(second + 1, str.end(), [](char c) { return c != ' '; });
    }
    return list;
}

Litterale *Controleur::creerLitterale(QString str, TypeLitterale type)
{
    if (type == TypeLitterale::ENTIER)
    {
        return new LitteraleEntier{str.toInt()};
    }
    if (type == TypeLitterale::REEL)
    {
        return new LitteraleReelle{str.toDouble()};
    }
    if (type == TypeLitterale::EXPRESSION)
    {
        return new LitteraleExpression{str};
    }
    if (type == TypeLitterale::PROGRAMME)
    {
        return new LitteraleProgramme{str, this};
    }
    return nullptr;
}

void Controleur::commande(const QString &s)
{
    Pile *pileCopy{litteraleAffiche_->cloneOnHeapGeneral()};
    try
    {
        QStringList listOperande = toLitteraleEtOperateur(s);
        for (size_t i = 0; i < listOperande.size(); i++)
        {
            QString operande = listOperande[i];
            TypeLitterale type = estLitterale(operande);
            if (type != TypeLitterale::NONE) // littérale entière || réelle || expression || programme
            {
                litteraleAffiche_->push(*creerLitterale(operande, type));
            }
            else // operateur numérique || opérateur pile || identifieur
            {
                if (estOperateurNumerique(operande))
                {
                    OperateurNumerique *op = OperateurNumerique::getOperateurNumerique(operande);
                    int arite = op->getArite();
                    std::vector<Litterale *> arguments{};
                    while (arite-- != 0 && !litteraleAffiche_->estVide())
                    {
                        arguments.insert(arguments.begin(), litteraleAffiche_->top().cloneOnHeapGeneral());
                        litteraleAffiche_->pop();
                    }
                    LitteraleNombre *lit = op->traitement(arguments);
                    litteraleAffiche_->push(*lit);
                }
                else if (estOperateurAccessible(operande))
                {
                    OperateurAccessible *op = OperateurAccessible::getOperateurAccessible(operande, litteraleAffiche_, &identifieurMap_);
                    op->traitement();
                }
                else if (checkOperateurPile(operande))
                {
                    // Faire rien ici, le methode checkOpérateurPile déjà exécute l'opérateur
                }
                else if (estIdentifieur(operande))
                {
                    if (i != listOperande.size() - 1 && listOperande[i + 1] == "FORGET")
                    {
                        (new Forget(operande))->traitement();
                        i++;
                        continue;
                    }
                    auto pos = identifieurMap_.find(operande);
                    if (pos->second->getLitterale()->getType() == TypeLitterale::PROGRAMME)
                    {
                        pos->second->evaluer();
                    }
                    else
                    {
                        litteraleAffiche_->push(*pos->second->evaluer());
                    }
                }
                else // Opérande invalide
                {
                    throw CalculateurException(("Opérande invalide: " + operande.toStdString() + " !").c_str());
                }
            }
        }

        // Pas d'exception jeté, sauvegarder le pile dans careTakerPile_
        if (listOperande.size() != 0 && (listOperande[0] != "UNDO" && listOperande[0] != "REDO"))
        {
            while (careTakerPile_->getTailleHistorique() > historyIndex_ + 1)
            {
                careTakerPile_->pop();
            }
            historyIndex_++;
            MementoPile *mementoPile = new MementoPile(*litteraleAffiche_->cloneOnHeapGeneral());
            careTakerPile_->addMementoPile(*mementoPile, historyIndex_);
        }
    }
    catch (const std::runtime_error &e)
    {
        litteraleAffiche_ = pileCopy;
        throw;
    }
}

void Controleur::loadPrecedent()
{
    if (historyIndex_ > 0)
    {
        historyIndex_--;
        litteraleAffiche_ = &careTakerPile_->getMementoPile(historyIndex_).getEtatPile();
    }
}

void Controleur::loadSuivant()
{
    if (historyIndex_ < careTakerPile_->getTailleHistorique() - 1)
    {
        historyIndex_++;
        litteraleAffiche_ = &careTakerPile_->getMementoPile(historyIndex_).getEtatPile();
    }
}
