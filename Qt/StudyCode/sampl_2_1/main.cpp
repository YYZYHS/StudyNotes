#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);// 应用程序对象,管理整个程序的生命周期,一个程序有且只能有一个
    Widget w;// 声明并创建一个窗口
    w.show();// 显示窗口
    return a.exec();// 应用程序开始运行,进入消息循环,等待事件处理
    // a.exec()会阻塞在这里,直到窗口关闭,返回值是程序的退出码
}
