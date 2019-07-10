#include "mainwindow.h"
#include <QApplication>
#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QDataStream io;
    QFile arch;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    arch.setFileName("saveMainWindow.txt");
    arch.open(QIODevice::WriteOnly);
    io.setDevice(&arch);
    io << w;
    arch.flush();
    arch.close();
    return a.exec();

}
