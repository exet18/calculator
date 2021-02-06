#include "calculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calculator w;
    w.setMinimumHeight(445);
    w.setMaximumHeight(356);
    w.setMinimumWidth(200);
    w.setMaximumWidth(300);
    w.show();
    return a.exec();
}
