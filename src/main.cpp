#include <QApplication>

#include "qcalculateur.h"

int main(int argc, char *argv[])
{
    QApplication app = QApplication{argc, argv};
    QCalculateur cal = QCalculateur();
    cal.show();
    return app.exec();
}
