#ifndef __QCALCULATEUR_H__
#define __QCALCULATEUR_H__

#include <QMainWindow>
#include <QWidget>
#include <QTableWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <memory>
#include <vector>
#include <queue>
#include <map>

#include "controleur.h"
#include "qclavier.h"

class QClavier;

class QCalculateur : public QMainWindow
{
private:
    Q_OBJECT

    bool waitingForOperand;
    unsigned int rowCount_;
    QString currentText_;

    QWidget* mainWidget_;
    QVBoxLayout* mainLayout_;
    QLineEdit* message_;
    QTableWidget* vuePile_;
    QLineEdit* commandeBar_;

    std::map<QString, QPushButton *> keyboardMap_;
    QWidget* keyboard_;
    std::unique_ptr<QClavier> clavier_;
    QGridLayout* keyboardLayout_;

    std::unique_ptr<std::queue<double>> operandQueue_;

    Controleur &controleur_;

    // void createButton(const QString &text, const char *member);

public:
    QCalculateur();
    QLineEdit &getCommandBar() { return *commandeBar_; }
    Controleur &getControleur() { return controleur_; }
    void setMessage(const QString &s) { message_->setText(s); }
    bool calculerOperateurSimple(QString op = "");
    void renderVuePile();

private slots:
    void enterClicked();
};

#endif // __QCALCULATEUR_H__
