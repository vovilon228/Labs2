#include "mainwindow.h"

#include <QApplication>

#include <QtWidgets>
#include "timer.h"
#include <QDebug>
#include <QFile>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *w = new MainWindow;
    w->setFixedSize(w->size());

    w->show();

    return a.exec();
//    return 0;
}
