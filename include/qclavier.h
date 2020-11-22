#ifndef __QCLAVIER_H__
#define __QCLAVIER_H__

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <memory>
#include "qcalculateur.h"

class QCalculateur;

class QClavier : public QWidget
{
private:
    Q_OBJECT

    QCalculateur &calculateur_;
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

private slots:
    void addTextClicked();
    void deleteClicked();
    void autoOperatorClicked();
    void enterClicked();
    bool calculerAutoOperateur(QString op);
};

#endif // __QCLAVIER_H__
