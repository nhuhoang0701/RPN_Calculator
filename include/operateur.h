#ifndef __OPERATEUR_H__
#define __OPERATEUR_H__

#include <QString>
#include <vector>
#include <string>

#include "litterale.h"
#include "exceptions.h"

class Operateur
{
private:
    unsigned int arite_;
    QString symbol_;

public:
    Operateur(unsigned int arite, QString symbol) : arite_{arite}, symbol_{symbol} {}
    virtual ~Operateur() {}

    QString getSymbol() { return symbol_; }
    int getArite() { return arite_; }
    void checkArite(unsigned int taille)
    {
        std::string message = "Opérande " + symbol_.toStdString() + " demande " + std::to_string(arite_) +
                              " arguments, " + std::to_string(taille) + " passé(s)!!";

        if (arite_ != taille)
        {
            throw CalculateurException{message.c_str()};
        }
    }
    virtual LitteraleNombre *traitement(const std::vector<Litterale *> &arguments) = 0;
};

#endif // __OPERATEUR_H__
