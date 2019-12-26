#include "widget.h"
#include "deviceselect.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    MainWindow mw;
    mw.show();
    return a.exec();
}
