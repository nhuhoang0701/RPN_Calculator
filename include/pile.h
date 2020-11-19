#ifndef __PILE_H__
#define __PILE_H__

#include <memory>
#include <vector>
#include <QString>
#include <QObject>

#include "item.h"
#include "exceptions.h"

class Pile : public QObject
{
private:
    Q_OBJECT

    std::vector<std::unique_ptr<Item>> items_;
    unsigned int nombre_;
    static unsigned int nombreAffiche_;
    QString message_;

public:
    Pile() : nombre_{0} {}

    bool estVide() const { return nombre_ == 0; }
    unsigned int getTaille() const { return nombre_; }
    void setMessage(const QString &message) { message_ = message; }
    QString getMessage() const { return message_; }
    static void setNombreItemsAffiche(unsigned int nombreAffiche) { nombreAffiche_ = nombreAffiche; }
    static unsigned int getNombreItemsAffiche() { return nombreAffiche_; }

    Litterale &top() const;
    void push(Litterale &litterale);
    void pop();
};

#endif // __PILE_H_
