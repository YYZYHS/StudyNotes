# Qt模块列表,在这里添加需要的模块
QT       += core gui

# 条件判断,如果Qt版本大于4,则添加widgets模块
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# 通用配置选项
CONFIG += c++17

# 预处理定义列表,下面的例子是添加一个Qt6.0.0之前的所有API的宏定义
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# 源文件列表,在这里添加需要的源文件,以符号\衔接下一行
SOURCES += \
    main.cpp \
    widget.cpp

# 头文件列表,在这里添加需要的头文件,以符号\衔接下一行
HEADERS += \
    widget.h

# UI文件列表,在这里添加需要的UI文件,以符号\衔接下一行
FORMS += \
    widget.ui

# 模板,在这里定义该项目是app(应用程序)还是lib(库),默认是app
TEMPLATE = app

# 默认部署规则,在这里定义部署规则,默认是在当前目录下创建一个bin目录
# $$为替换函数的前缀,如$$TARGET,表示替换TARGET变量的值
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# 更多内容参见Qt文档(qmake Manual) https://doc.qt.io/qt-5/qmake-manual.html
