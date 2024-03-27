#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);// 实现了可视化设计的窗口中设计的内容
}

Widget::~Widget()
{
    delete ui;
}
