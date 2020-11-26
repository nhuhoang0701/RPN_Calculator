#ifndef __QCLAVIER_H__
#define __QCLAVIER_H__

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <memory>
#include "qcalculateur.h"

using identifieurMap_t = std::map<QString, LitteraleExpression *>;

class QCalculateur;

class QClavier : public QWidget
{
private:
    Q_OBJECT

    QCalculateur &calculateur_;
    identifieurMap_t *identifieurMap_;

    std::map<QString, QPushButton *> keyboardMap_;
    QSizePolicy sizeButtonPolicy_;
    QFrame *simpleClavier_;
    QFrame *pileClavier_;
    QFrame *fonctionClavier_;
    QFrame *logiqueClavier_;
    QFrame *conditionClavier_;
    QFrame *evaluationClavier_;
    QFrame *userVariableClavier_;
    QFrame *userFonctionClavier_;
    QVBoxLayout *mainLayout_;
    QHBoxLayout *subLayout_1_;
    QHBoxLayout *subLayout_2_;
    QHBoxLayout *subLayout_3_;
    QHBoxLayout *subLayout_4_;
    QGridLayout *variableLayout_;
    QGridLayout *fonctionLayout_;

    void creerButton(const QString &text, const char *member);
    void creerSimpleClavier();
    void creerPileClavier();
    void creerFonctionClavier();
    void creerCondtionClavier();
    void creerLogiqueClavier();
    void creerEvaluationClavier();
    void creerUserClavier();

public:
    QClavier(QCalculateur &calculateur);
    void setIdentifieurMap(identifieurMap_t *mp) { identifieurMap_ = mp; }
    void updateUserClavier();

private slots:
    void addTextClicked();
    void deleteClicked();
    void autoOperatorClicked();
    void enterClicked();
    bool calculerAutoOperateur(QString op);
};

#endif // __QCLAVIER_H__
