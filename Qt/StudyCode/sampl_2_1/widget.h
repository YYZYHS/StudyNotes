#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {  // 命名空间
class Widget;   // ui_widget.h中定义的类,外部声明
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT// 宏,使用Qt信号与槽机制时必须添加

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;// Ui::Widget类的指针,指向可视化设计生成的窗口
};
#endif // WIDGET_H
