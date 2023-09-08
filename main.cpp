#include "mainwindow.h"

#include <QApplication>

#include "menuxy.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget widget;


    auto * menu = new MenuXY(&widget,nullptr);
    menu->move(33,33);
    menu->show();

    widget.show();
    return a.exec();
}
