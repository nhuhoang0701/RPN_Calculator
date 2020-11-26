#include <iostream>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QScrollBar>
#include <QKeyEvent>
#include <cmath>

#include "qcalculateur.h"
#include "exceptions.h"

// Cette fonction se sert seulement à configurer vuePile_, lecture optionel
void verticalResizeTableViewToContents(QTableWidget *tableView)
{
    int rowTotalHeight = 0;

    int count = tableView->verticalHeader()->count();
    for (int i = 0; i < count; ++i)
    {
        if (!tableView->verticalHeader()->isSectionHidden(i))
        {
            rowTotalHeight += tableView->verticalHeader()->sectionSize(i);
        }
    }

    if (!tableView->horizontalScrollBar()->isHidden())
    {
        rowTotalHeight += tableView->horizontalScrollBar()->height();
    }

    if (!tableView->horizontalHeader()->isHidden())
    {
        rowTotalHeight += tableView->horizontalHeader()->height();
    }
    tableView->setMinimumHeight(rowTotalHeight);
}

void QCalculateur::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return)
        emit returnPressed();
    QMainWindow::keyReleaseEvent(event);
}

QCalculateur::QCalculateur()
    : waitingForOperand{false}, rowCount_{10}, controleur_{Controleur::getInstance()},
      message_{new QLineEdit{}}, vuePile_{new QTableWidget{}},
      commandeBar_{new QLineEdit{}}, clavier_{std::make_unique<QClavier>(*this)}
{
    // setFixedSize(700, 400);
    clavier_->setIdentifieurMap(controleur_.getIdentifieurMap());

    connect(this, SIGNAL(returnPressed()), this, SLOT(enterClicked()));
    setWindowTitle("UTCalculateur");
    mainWidget_ = new QWidget{};
    mainLayout_ = new QVBoxLayout{};
    mainWidget_->setAutoFillBackground(true);
    mainWidget_->setLayout(mainLayout_);
    setCentralWidget(mainWidget_);

    message_->setReadOnly(true);
    message_->setAlignment(Qt::AlignLeft);

    vuePile_->setRowCount(rowCount_);
    vuePile_->setColumnCount(1);
    vuePile_->horizontalHeader()->setStretchLastSection(true);
    vuePile_->horizontalHeader()->setVisible(false);
    vuePile_->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    vuePile_->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vuePile_->setFocusPolicy(Qt::NoFocus);
    vuePile_->setSelectionMode(QAbstractItemView::NoSelection);
    verticalResizeTableViewToContents(vuePile_);
    QStringList labelList;
    for (size_t i = rowCount_; i >= 1; i--)
    {
        labelList.append(QString::number(i));
    }
    vuePile_->setVerticalHeaderLabels(labelList);
    for (size_t i = 0; i < rowCount_; i++)
    {
        vuePile_->setItem(i, 0, new QTableWidgetItem{});
    }

    connect(commandeBar_, SIGNAL(returnPressed()), this, SLOT(enterClicked()));
    mainLayout_->addWidget(message_);
    mainLayout_->addWidget(vuePile_);
    mainLayout_->addWidget(commandeBar_);
    mainLayout_->addWidget(clavier_.get());
}

bool QCalculateur::calculerAutoOperateur(QString op)
{
    controleur_.commande(commandeBar_->text() + " " + op);
    renderVuePile();
    message_->clear();
    commandeBar_->clear();
    return true;
}

void QCalculateur::renderVuePile()
{
    Pile &pile = controleur_.getPile();
    PileIterator pileItr{&pile};
    int count = 1;
    for (auto itr = pileItr.begin(); (itr != pileItr.end()) && (count <= rowCount_); itr++)
    {
        vuePile_->item(rowCount_ - count, 0)->setText((*itr)->affichage());
        count++;
    }

    for (size_t i = count; i <= rowCount_; i++)
    {
        vuePile_->item(rowCount_ - i, 0)->setText("");
    }
    clavier_->updateUserClavier();
}

void QCalculateur::enterClicked()
{
    try
    {
        calculerAutoOperateur();
    }
    catch (const CalculateurException &e)
    {
        message_->setText(e.what());
    }
}
