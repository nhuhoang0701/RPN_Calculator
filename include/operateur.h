#ifndef __OPERATEUR_H__
#define __OPERATEUR_H__

#include <QString>

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
};

#endif // __OPERATEUR_H__
