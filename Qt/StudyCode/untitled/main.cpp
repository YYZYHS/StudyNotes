#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <iostream>
int main(int argc, char *argv[])
{
    std::cout << "this is a test1";
    QApplication a(argc, argv);
    qDebug() << "this is a test2";
    MainWindow w;
    w.show();
    qDebug() << "this is a test3";
    return a.exec();
}
