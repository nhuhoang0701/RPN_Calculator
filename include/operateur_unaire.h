#include <QString>

#include "operateur.h"

class OperateurUnaire : public Operateur
{
private:
public:
    OperateurUnaire(const QString &symbol);
};
