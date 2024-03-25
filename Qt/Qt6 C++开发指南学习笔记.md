<center style="font-family: 华文新魏"><font size="12px" color="#4870ac">Qt6 C++开发指南学习笔记</font></center>

[toc]

# 第1章认识Qt

## 1.1 Qt简介

### 1.1.1 Qt的基本情况

- Qt是一个跨平台的应用程序开发框架。也是最主流的C+开发框架
- Qt于1995年5月首次公开发布。
- Qt官网：www.qt.io
- Qt具有其他编程语言的扩展，但Qt本身是用`C++`开发的
- ![image-20240325235424363](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/image-20240325235424363.png)

### 1.1.2 Qt的跨平台开发能力

只要熟悉一种平台的开发，就能很快适应其他平台的开发。并且Qt源代码编译后生成`目标平台的原生二进制代码`，不像Java那样需要虚拟机，`运行效率更高`。

| 目标设备   | 目标平台（运行平台）                                 | 主机平台（开发平台）                                         |
| ---------- | ---------------------------------------------------- | ------------------------------------------------------------ |
| 计算机     | 桌面Linux<br />macOS<br />Windows                    | 桌面Linux<br />macOS<br />Windows                            |
| 移动设备   | Android<br />iOS<br />手机Windows                    | 桌面Linux、macOS、Windows<br />macOS<br />Windows            |
| 嵌入式设备 | 嵌入式Linux<br />QNX<br />VxWorks<br />嵌入式Windows | 桌面Linux<br />桌面Linux、Windows<br />桌面Linux、Windows<br />Windows |
| 单片机     | FreeRTOS或无操作系统                                 | Windows、桌面Linux                                           |

`注：`目标平台和主机平台每一行都一一对应

### 1.1.3 Qt的许可类型和安装包

- Qt的许可类型：
  - 商业许可：按年付费，模块更多，开发者可以不公开自己的源码。
  - 开源许可：
    - GPLv2/GPLv3许可：使用了GLP许可的Qt代码允许销售但必须开源。GPLv3
      还要求公开相关硬件信息。
    - LGPLv3许可：与GPL类似，但更宽松。若只是链接或调用GPL许可协议的Qt代冯，可以不开源。
  - Qt安装包：根据目标设备不同，提供了不同的安装包。

### 1.1.4 Qt支持的开发语言

1. C++和QML:

   - Qt对标准C++语言进行了扩展，引入了信号与槽等机制。（本教程内容）
   - QML(Qt Meta Language)是一个用来描述应用程序界面的`声明式脚本语言`。
   - C++和QML可以混合使用。

2. Python

   - Qt C++可以被转换为Python绑定，使用Python调用Qt类库进行GUI程序开发。

   - 常用的Qt类库Python绑定有：PyQt(GPLv3许可)和PySide(LGPLv3许可)

### 1.1.5 Qt6新特性

- 2020年12月正式发布了Qt6.0,引入的主要新特性包括：
  - 支持C+17标准。
  - Qt核心库的改动：新的属性和绑定系统；全面支持Unicode字符串；修改了QListl的实现方式，将QVector类和QList类统一为QList类；QMetaType和QVariant,几乎被重写。
  - 新的图形架构：Qt5中3D渲染依赖DpenGL.Qt6中引入了新的技术RHI(rendering hardware interface），它是一个抽象层，使得Qt可以使用平台本地化的3D图形API（Linux：Vulkan，Windows：Direct 3D，macOS：Metal)
  - CMake构建系统：Qt6仍然支持gmake但建议使用CMake
  - 其他（多媒体、网络、Qt Quick3D等模块的改进

## 1.2 Qt6安装



## 1.3 编写一个Hello World程序

# 第2章 GUI程序设计基础



# 第3章Qt框架功能概述



# 第4章常用界面组件的使用



