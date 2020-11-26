#include "operateur_accessible.h"
#include "operateur_evaluatif.h"

Pile *OperateurAccessible::pile_ = nullptr;
identifieurMap_t *OperateurAccessible::identifieurMap_ = nullptr;

OperateurAccessible *OperateurAccessible::getOperateurAccessible(const QString &symbol, Pile *pile, identifieurMap_t *mp)
{
    pile_ = pile;
    identifieurMap_ = mp;
    static std::map<QString, std::shared_ptr<OperateurAccessible>> operateurMap_ = {
        {"IFT", std::make_shared<IfThen>()},
        {"IFTE", std::make_shared<IfThenElse>()},
        {"WHILE", std::make_shared<While>()},
        {"EVAL", std::make_shared<Evaluer>()},
        {"STO", std::make_shared<Stocker>()},
    };

    if (operateurMap_.find(symbol) == operateurMap_.end())
    {
        std::cout << "return null pointer in operateur" << '\n';
        return nullptr;
    }
    return operateurMap_.at(symbol).get();
}

void OperateurAccessible::setPile(Pile *pile)
{
    pile_ = pile;
}

void OperateurAccessible::setIdentifieurMap(identifieurMap_t *mp)
{
    identifieurMap_ = mp;
}
