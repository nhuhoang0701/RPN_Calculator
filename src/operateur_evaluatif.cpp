#include "operateur_evaluatif.h"
#include <QString>

// IFT opérateur
IfThen::IfThen()
    : OperateurEvaluatif{2, "IFT"} {}

void IfThen::traitement()
{
}

// IFTE opérateur
IfThenElse::IfThenElse()
    : OperateurEvaluatif{3, "IFTE"} {}

void IfThenElse::traitement()
{
}

// WHILE opérateur
While::While()
    : OperateurEvaluatif{std::numeric_limits<unsigned int>::max(), "WHILE"} {}

void While::traitement()
{
}

// EVAL opérateur
Evaluer::Evaluer()
    : OperateurEvaluatif{1, "EVAL"} {}

void Evaluer::traitement()
{
    Litterale &top = pile_->top();
    if (top.getType() != TypeLitterale::EXPRESSION)
    {
        throw CalculateurException(("Opérateur EVAL ne traite que littérale expression, " +
                                    top.affichage().toStdString() + " trouvé!")
                                       .c_str());
    }
    QString atome = top.affichage().mid(1, top.affichage().length() - 2);
    std::cout << atome.toStdString() << '\n';
    auto pos = identifieurMap_->find(atome);
    if (pos != identifieurMap_->end())
    {
        if (pos->second->getLitterale()->getType() == TypeLitterale::PROGRAMME)
        {
            pos->second->evaluer();
            return;
        }
        pile_->pop();
        pile_->push(*(pos->second->evaluer()->cloneOnHeapGeneral()));
    }
    else
    {
        std::cout << "Special" << '\n';
        throw CalculateurException((top.affichage().toStdString() + " n'est pas une variable!").c_str());
    }
}

// STO opérateur
Stocker::Stocker()
    : OperateurEvaluatif{2, "STO"} {}

void Stocker::traitement()
{
    Litterale *argument_2 = pile_->top().cloneOnHeapGeneral();
    pile_->pop();
    Litterale *argument_1 = pile_->top().cloneOnHeapGeneral();
    pile_->pop();
    if (argument_1->getType() == TypeLitterale::EXPRESSION)
    {
        throw CalculateurException("Le première littérale ne faut pas une littérale expression!");
    }
    if (argument_2->getType() != TypeLitterale::EXPRESSION)
    {
        throw CalculateurException("Le seconde littérale faut une littérale expression!");
    }
    QString atome = argument_2->affichage().mid(1, argument_2->affichage().length() - 2);
    if (OperateurNumerique::getOperateurNumerique(atome) != nullptr)
    {
        throw CalculateurException(("Opérateur " + atome.toStdString() + " est prédifini!").c_str());
    }

    auto pos = identifieurMap_->find(atome);
    if (pos != identifieurMap_->end())
    {
        (*identifieurMap_)[atome]->setLitterale(argument_1);
    }
    else
    {
        LitteraleExpression *variable = new LitteraleExpression{"'" + atome + "'"};
        variable->setLitterale(argument_1);
        (*identifieurMap_)[atome] = variable;
        std::cout << argument_1->affichage().toStdString() << '\n';
    }
}

// FORGET opérateur
Forget::Forget(const QString &atome)
    : OperateurEvaluatif{1, "FORGET"}, atome_{atome} {}

void Forget::traitement()
{
    auto pos = identifieurMap_->find(atome_);
    if (pos != identifieurMap_->end())
    {
        identifieurMap_->erase(atome_);
    }
    else
    {
        throw CalculateurException(("Atome " + atome_.toStdString() + " n'est pas stocké!").c_str());
    }
}
