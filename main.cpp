#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

#pragma once

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //GameWindow w;
    w.show();
    return a.exec();
}
