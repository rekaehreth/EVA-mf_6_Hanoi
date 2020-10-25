#include "hanoiwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HanoiWidget w;
    w.show();
    return a.exec();
}
