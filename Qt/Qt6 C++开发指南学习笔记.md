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

### 1.2.1 Qt6如何安装？

- 在线安装包下载地址：https://download.qt.io/official_releases/online_installers/

  - ![8250ad01956742c9b7a0f2f1504ef2e6-1711546777430-4](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/8250ad01956742c9b7a0f2f1504ef2e6-1711546777430-4.png)

  - ![img](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/31af299bc6b64b8fa9c140aa6574eec6.png)
  - 根据操作系统选择对应的下载文件
  - ![img](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/f4ed9c9675b54d2db878400cfed37d3c.png)

- 只需要安装需要使用的组件，后期可以添加删除。
  - ![img](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/5fbf01a555814440bbe06024d973a498.png)
- 运行Qt Creator,打开一个自带例子进行测试。

### 1.2.2 可能遇到的错误

qt国内下载安装过程中可能会遇到镜像获取不到的错误,如下图所示:

![在这里插入图片描述](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/c95a396135374b1787cc361477ee30dc.png)

**解决方法:**更换国内的镜像,下面以Windows操作系统为例

- 在`在线安装包`的文件夹下打开`cmd命令行`

- 手动输入安装包的文件名,也可直接将安装包拖入到cmd命令行中,并在后面添加参数`--mirror 国内镜像地址`,例如

  ```shell
  MaintenanceTool.exe --mirror 国内镜像地址
  ```

  这样，安装程序就会尝试从国内镜像地址获取所需文件，解决了因无法访问外网镜像而导致的下载错误。

  ![image-20240327213353587](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/image-20240327213353587.png)

- 常用的国内镜像
  - 南京大学：https://mirror.nju.edu.cn/qt 
  - 腾讯：https://mirrors.cloud.tencent.com/qt/
  - 中国科学技术大学：http://mirrors.ustc.edu.cn/qtproject/
  - 清华大学：https://mirrors.tuna.tsinghua.edu.cn/qt/
  - 北京理工大学：http://mirror.bit.edu.cn/qtproject/
  - 中国互联网络信息中心：https://mirrors.cnnic.cn/qt/

## 1.3 Qt Creator初识

### 1.3.1 Qt Creator简介

- Qt Creator为应用程序开发人员提供了一个完整的`跨平台、集成开发环境(IDE)`以便为`桌面`、`嵌入式`和`移动设备平台(如Android和iOS)`创建应用程序。
- Qt Creator提供了在整个`应用程序开发生命周期`所需的工具，从创建项目到将应用程序部署到目标平台

### 1.3.2 Qt Creator 欢迎界面

从开始菜单或者快捷方式打开 QtCreator 集成开发环境，启动之后看到类似下面的界面：

![Qt Creator 欢迎界面](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/79c23e94062903d55afb6cb8c682c830.gif)

QtCreator 最左边是一排功能按钮。上半部分按钮是 QtCreator 工作模式选择，共有七种工作模式，分别是欢迎、编辑（编写代码）、设计（GUI可视化编辑）、Debug（调试程序）、项目（项目参数配置）、分析（程序执行效率分析）、帮助。下面四个按钮是构建调试区，由上到下依次是 Qt 套件选择、运行、调试运行和构建。

左边的设计按钮、项目按钮和构建调试区只有在打开或新建了项目之后才会变得可用。

QtCreator 下方的是定位工具和输出面板，在编写项目代码和运行、调试程序时会使用到。输出面板包括七个，分别是问题（项目构建时的问题）、Search Results（搜索项目文件内容）、应用程序输出（运行和调试信息显示）、编译输出（编译、链接命令及其输出信息）、QML/JS Console（QML 命令窗口）、概要信息（项目信息摘要）、Version Control（版本控制系统）。

QtCreator 中间的区域是所选择的工作模式界面，默认是欢迎模式。欢迎模式有三个子功能，第一个 Project 是项目显示，包括之前的会话和项目记录。项目记录比较好理解，而会话涵盖内容比较广，一个会话可以是多个项目的列表，并含有它们的配置以及上次编辑位置记录、调试 断点等等。会话记录的上方是新建项目的快捷按钮，项目记录的上方是打开项目的快捷按钮。欢迎模式另外两个子功能是浏览 Qt 库自带的示例和教程，感兴趣的读者可以自行打开看看。

### 1.3.3 Qt Creator 新建项目

接下来我们新建一个 HelloWorld 项目。打开 Qt Creator 文件菜单，点击“新建文件或项目”（快捷键 Ctrl+N），或者直接在欢迎模式点击快捷按钮“New Project”，都可以打开如下所示的新建项目对话框：

![Qt Creator新建项目对话框](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/95497b022af2a4039a8aab38f87a7239.gif)

新建项目对话框里有五类项目模板：

| 项目模板       | 说明                                                         |
| :------------- | :----------------------------------------------------------- |
| Application    | Qt 应用程序，包括普通窗体程序和 QtQuick 程序。               |
| Library        | 可以创建动态库、静态库以及 QtQuick 扩展插件、QtCreator 自身插件。 |
| 其他项目       | 可以创建单元测试项目、Qt4 设计师自定义控件、子目录项目等。   |
| Non-Qt Project | 非 Qt 项目。可以创建纯 C 或 纯 C++ 项目。                    |
| Import Project | 导入项目。从版本控制系统管理的软件项目导入旧的项目。         |

本教程常用的只有第一类 Application，选择它，在右侧会看到 Qt 应用程序的五个子模板：

- Qt Widgets Application：普通窗体模板，传统基于部件的窗体界面程序。
- Qt Console Application：Qt 控制台应用程序。因为 Qt 主要用于图形界面设计，这个控制台项目模板基本不用的。
- Qt Quick Application、Qt Quick Controls 2 Application 和 Qt Canvas 3D Application 工程将会使用 QML 代码，Quick Control 主要比 Quick 多一些控件，Canvas 3D 用来创建3D动画。

本教程使用第一个子模板 Qt Widgets Application，开发普通的 Qt 窗体应用程序。选择该项目模板，点击对话框下方的“Choose...”按钮，进入 Qt Widgets Application 项目新建的向导界面：

![Qt Widgets Application向导页面](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/026a7fba6f02803d83686aba8f764e90.gif)

将项目名称设置为 HelloWord，创建路径设置为 D:\QtDemo，点击“下一步”，进入“Kit Selection”界面：

![Qt套件设置界面](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/911064880d5f7680be2cd0a8672d2270.gif)

这一步是为 HelloWord 设置 Qt 套件（Qt Kits），默认只有第一个“Desktop Qt 5.9.0 MinGW 32bit”，如果安装配置了多个 Qt 套件，就可以都选上。

Qt 套件是指 Qt 程序从编译链接到运行环境的全部工具和 Qt 类库的集合，对于 MinGW 版本 Qt 程序生成和调试，至少需要 MinGW 中的编译器 g++（自动调用链接器）、g++ 配套的基础库、调试器 gdb 还有使用 MinGW 环境编译而成的 Qt 类库自身。默认情况下，在上面 Kit Selection 里选中全部套件，然后点击“下一步”，进入“类信息”设置界面：

![类信息设置界面](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/ef91833411d991063e7f9f52ed6c8df2.gif)

类信息设置界面，最关键的是基类的选择，目前是三种基类：

| 基类        | 说明                                                         |
| :---------- | :----------------------------------------------------------- |
| QMainWindow | 基于主窗口类的程序，一般用于较为复杂的应用程序，除了中央客户区界面，还可以包括菜单栏、工具栏、状态栏以及多个可停靠的 工具对话框等等。 |
| QWidget     | 最简单最基本的窗体程序，里面可以放置多个控件实现程序功能。   |
| QDialog     | 基于对话框的程序，对话框一般用于弹窗，也可以用于主界面显示。对话框是从 QWidget 继承而来的，并丰富了一些功能，如模态显示和返回值等。 |


我们当然从最简单的学起，在基类里选择 QWidget ，类名和文件名会根据基类自动修改，不需要额外设置。点击“下一步”，进入“项目管理”界面：

![项目管理界面](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/a61062d0e00983d1743a35fcf0542433.gif)

在项目管理界面可以设置作为子项目，以及加入版本控制系统管理。这两个功能暂时用不到，都用默认的 <None> ，然后点击 “完成”。

项目创建完成之后，Qt Creator 会直接进入代码编辑模式，可以看到类似下图界面：

![Qt Creator代码编辑模式](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/7ad89a32b57af6ba818d50082b9718b2.gif)

1) 左边栏

编辑模式左边竖排的两个窗口叫做“边栏”，上面的默认是项目文件管理窗口，下面的是打开文件列表窗口。在 QtCreator 菜单“控件-->显示边栏 Alt+0”，可以控制边栏的显示和隐藏。

边栏里的窗口数目可以增加，边栏子窗口标题栏（其实是工具条，长得像标题栏，姑且这么称呼）有一排小按钮，最右边的是关闭按钮，倒数第二个是增加分栏按钮，可以添加多个边栏子 窗口。

边栏子窗口标题栏第一个控件是组合框，可以选择该子窗口的功能视图类型，目前可以选择 8 个视图类型：

| 视图类型          | 说明                                                         |
| :---------------- | :----------------------------------------------------------- |
| 项目              | 即项目文件管理视图，可以选择项目里的文件进行编辑，包括 pro 文件也可以手动编辑。 |
| 打开文档          | 当前已经打开的文件列表，文件名右边如果有 * 号，是该文件被修改了但尚未保存。 |
| 书签              | 右击代码编辑器行号位置，看到“切换书签”，可以给代码行添加书签，方便跳转到该位置。 |
| 文件系统          | 相当于系统里的文件资源管理器，可以查看项目文件夹在磁盘里的实际文件列表。 |
| 类视图            | 可以查看项目里包含的类及相应源代码文件里的成员函数、成员变量。 |
| 大纲              | 编辑器所显示的当前文件的大纲列表，如名字空间、类名、成员函数、成员变量等。 |
| 类型层次          | 当前项目包含的类及其基类、派生类列表。                       |
| Include Hierarchy | 包含视图，显示当前项目里 *.h 、*.cpp 以及 Qt 类库头文件之间的包含关系。 |

可见 Qt Creator 提供的功能视图是很丰富的，这些视图不需要死记硬背，只要知道大概有这些东西，以后需要的时候会调出来就行了。一般用头两个就差不多了，当然也可以建立多个分栏，启用其他功能视图。

2) 代码编辑器

说完了左边栏，再来看看右边的代码编辑器：

![Qt Creator代码编辑器](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/549c898b0e4948decd0b355ed924e238.gif)

代码编辑器大致可以分为三个部分，带有一堆控件的标题栏（其实是工具条）、行首区和编辑区。

先看看标题栏的 10 个控件，这些东西不需要记，因为打开 Qt Creator 的时候，这些东西都在那里，用鼠标指向这些控件几秒钟，会自动显示这些控件的工具提示信息，这里将它们罗列出来，方便读者以后查阅而已：

- ①和②：导航按钮“返回”和“前进”，这与网页浏览器的前进和后退按钮类似，可以在之前浏览的多个代码文件或一个代码文件里多个位置之间快速切换。
- ③：标识当前显示的文件是只读还是可写，一般都是可写的。
- ④：文件类型图标，当前显示文件的类型，这个控件其实是一个菜单按钮，点击可以弹出丰富的文件处理功能菜单，感兴趣的读者可以点开看看。
- ⑤：打开的文件名，可以在多个打开的文件之间选择切换，与边栏的“打开文档”视图是对应的。
- ⑥：关闭当前显示的文档。
- ⑦：为当前显示的文件添加额外的C++预处理指令，一般用不着。
- ⑧：选择符号，可以在当前显示的文件里多个函数、类、成员变量等之前快速切换，与边栏“大纲”视图是对应的。
- ⑨：编辑区光标的行号和列号。
- ⑩：代码编辑区分栏，可以增加多个编辑器窗口，显示多个打开的文档或显示较大源码文件的多个位置。


行首区是浅灰色背景的部分，主要用来显示代码行号，以及调试断点标志和代码书签标志。右击行首区可以弹出右键菜单，菜单里可以切换书签、编辑书签以及设置或取消断点。

同一行是既可以打断点也可以设置书签的，二者不冲突，其实它们根本就没关系。单击行号前面的浅灰色空白区可以直接打断点，再次单击可以取消断点，另外也可以用快捷键 F9 设置或取消断点。代码书签一般用右键菜单来设置，也可以用快捷键 Ctrl+M 设置或取消书签。

编辑区是程序员最为常用的部分了，就是写代码用的。编辑区当然有语法高亮显示了，而且从编辑区的复制出来的内容是 HTML 语法的丰富文本格式，如果粘贴到 Word 之类的文字处理软件中，会直接显示彩色高亮代码，这是很实用的功能。

对于现代集成开发环境常见的变量名、类名、名字空间、函数名、类对象成员变量、结构体成员变量等等名字补全功能，Qt Creator 编辑器当然也能很好地支持。变量/函数调用追踪、变量/函数声明追踪、类名或变量名函数名自动改名等常见的辅助功能，也都是支持的（选择要改或要追踪的名字，右击，在右键 菜单里有一大堆功能，Refactor菜单项里面有自动改名）。

### 1.3.4 Qt Creator 编辑 UI

在 Qt Creator 编辑模式边栏上面的项目视图里，包含一个 HelloWorld.pro 项目文件和 Headers（头文件）、Sources（源文件）、Forms（界面文件）三个虚拟目录。这三个虚拟目录是项目里对文件类型的归类显示，widget.h 和 main.cpp、widget.cpp 三个代码文件在后续小节讲解，本小节先设计图形界面文件 widget.ui。

双击 widget.ui 文件，Qt Creator 会自动进入[设计模式](http://c.biancheng.net/design_pattern/)，可以对图形界面进行可视化编辑：

![Qt Creator进入设计模式](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/0fac1c34d1e0578550154bb0ba914b4a.gif)

这个设计模式界面和《[Qt Designer的简单使用](http://c.biancheng.net/view/3956.html)》中介绍的 Qt 设计师是完全类似的，而且这就是将 Qt Designer 的功能做成插件，集成到 Qt Creator 了。

当然设计师变成插件之后，和原来的独立设计师程序有区别，现在插件设计师自己的菜单集成到 Qt Creator 菜单栏的“工具-->Form Editor”级联菜单里。预览窗口需要点击菜单栏的“工具-->Form Editor-->预览”。

和《[Qt Designer的简单使用](http://c.biancheng.net/view/3956.html)》一节类似的，拖一个 Label 标签控件到窗体编辑区里，然后设置标签控件的 geometry 的四个子属性： X 为 10，Y 为 10，宽度为 200，高度为 40。接着编辑标签控件的 text 属性为“Hello World! ”，看到效果如下：

![添加一个Label控件](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/2195075141931b4b53ec76b724a10be7.gif)

编辑完成以后，注意使用 Ctrl+S 快捷键保存项目。

### 1.3.5 Qt Creator 生成和运行程序

使用 Qt Creator 生成和运行程序是再简单不过的事了。一个按钮就够了。当然，得先认识认识一下 Qt Creator 左下角的按钮：

![Qt Creator构建调试按钮](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/58f979142dca6bd60ce1b3dbafb460a5.gif)

左下角一共有四个按钮，下面分别介绍一下：

- 第一个按钮是选择构建项目使用的 Qt 套件和构建目标程序的类型（Debug 或 Release）。
- 第二个是运行按钮，快捷键是 Ctrl+R，如果还没构建项目或刚修改了代码，直接点击运行的话，QtCreator 会自动构建生成新的目标程序并运行。
- 第三个是调试按钮，快捷键是 F5。调试程序之前，QtCreator 会自动构建生成最新的目标程序，并进入调试模式。在下一节专门讲解调试程序。
- 第四个是构建按钮，快捷键是 Ctrl+B，只构建最新的目标程序，但不运行。


如果只构建而不运行程序，就点第四个。一般都是构建后运行程序查看效果，可以直接点击第二个运行按钮，如果没问题发生，就会显示目标程序主界面：

![编译、链接并运行程序](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/663ca337aede2711e02b5815b7a044cd.gif)

从编译生成到运行，不需要自己敲命令，一个按钮搞定，这就是集成开发环境的好处。

上面示范的是默认 Qt 套件，构建的是 Debug 类型的目标程序。如果需要构建 Release 版目标程序，点开左下角第一个按钮：

![选择构建模式](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/5949682125b9c73d3035b939e61ce273.gif)

这里有三种构建模式：其中 Debug 和 Release 我们都是耳熟能详的，前者是以`-g`模式编译，带着符号信息，便于我们调试，后者是经过优化之后，性能更上一个档次的。profile 则是在这两者之中取一个平衡，兼顾性能和调试，可以类似的看做是性能更优但是又方便调试的版本。

可以选择 Release 构建类型，然后再点击运行按钮就可以构建运行 Release 版本目标程序。

上图是针对项目只用到单一 Qt 套件的，如果之前配置了多个 Qt 套件，看到的类似下图：

![先选择套件，再选择构建类型](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/ad7b58f49c700d277f36d85081ea7574.gif)

如果项目配置了多个可用的 Qt 套件，点开左下角第一个按钮后，会看到各个套件以及构建类型，如果要切换 Qt 套件或构建类型，直接选中相应条目，然后点击运行按钮就行了。如果构建和运行时没出错，就会显示出构建好的目标程序界面。

# 第2章 GUI程序设计基础

## 2.1 GUI程序结构与运行机制

### 2.1.1 创建GUI窗口工程

新建一个Widget Application项目：QWidget作为窗口基类，选中Generate form复选框：

![image-20240327221146623](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/image-20240327221146623.png)

如此，Qt Creator会生成下面这些文件

![image-20240327221304623](./Qt6%20C++%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.assets/image-20240327221304623.png)

- **sampl_2_1.pro**：qmake构建系统的项目配置文件，存储了各种项目设置。
  - 项目管理文件：后缀为`.pro`
  - qmake是构建项目的软件，它根据.pro文件生成`Makefile文件`，然后`C++编译器`可以根据Makefile文件进行`编译和链接`
  - qmake还会自动生成`MOC`(meta-object compiler)和`UIC`(user interface compiler))文件
- **main.cpp**：主程序入口文件，实现`main函数`
- **widget.ui**：使用`XML格式`描述`元件及布局`的界面文件
- **widget.h**：`窗口类定义头文件`，用到了.ui文件
- **widget.cpp**：`窗口类定义实现文件`

### 2.1.2 项目管理文件

```cmake
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

```

常用的

| Variable  | Contents                                                     |
| --------- | ------------------------------------------------------------ |
| CONFIG    | 项目的一般配置选项。                                         |
| DESTDIR   | 可执行文件或二进制文件将放置在其中的目录。                   |
| FORMS     | 要由用户界面编译器（uic）处理的UI文件列表。                  |
| HEADERS   | 构建项目时使用的头文件（.h文件）的文件名列表。               |
| QT        | 项目中使用的Qt模块列表。                                     |
| RESOURCES | 要包含在最终项目中的资源（.qrc文件）列表。有关这些文件的更多信息，请参阅Qt资源系统。 |
| SOURCES   | 构建项目时要使用的源代码文件列表。                           |
| TEMPLATE  | 项目要使用的模板。这将决定构建过程的输出是应用程序、库还是插件。 |

### 2.1.3 主函数文件

```cpp
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
```

**主函数文件解释：**

- `#include "widget.h"`：包含自定义的窗口类头文件，以便在主函数中使用。
- `#include <QApplication>`：包含Qt应用程序类的头文件，以便在主函数中创建和管理应用程序对象。
- `int main(int argc, char *argv[])`：主函数的入口点，接收命令行参数 `argc` 和 `argv[]`。
- `QApplication a(argc, argv);`：创建一个Qt应用程序对象 `a`，用于管理整个程序的生命周期。在一个程序中只能有一个应用程序对象。
- `Widget w;`：声明并创建一个名为 `w` 的窗口对象，使用了自定义的窗口类 `Widget`。
- `w.show();`：显示窗口，使其可见。
- `return a.exec();`：启动应用程序的事件处理循环，并等待事件的发生。这会阻塞程序，直到窗口被关闭。`a.exec()` 的返回值是应用程序的退出码。
  
  注：`a.exec()` 是一个阻塞调用，意味着程序会在此处等待，直到窗口关闭为止。

### 2.1.4 窗体相关文件

  - **widget.h：**
    - `widget.h` 文件通常包含窗口类的声明，其中包括类的成员变量和方法的声明。
    - 这个文件定义了窗口的外观和行为，包括窗口的标题、大小、布局等。

  - **widget.cpp：**
    - `widget.cpp` 文件包含了窗口类的实现，其中包括了类成员函数的具体实现。
    - 在这个文件中，你可以找到窗口类中各个函数的具体实现，例如构造函数、析构函数以及其他自定义的函数。

  - **widget.ui：**
    - `widget.ui` 文件是Qt Designer创建的窗口布局文件，以`XML格式`保存。
    - 它包含了`窗口的布局信息`、`控件的位置和大小`等设计相关的信息。
    - 这个文件通常使用`Qt的可视化设计器工具`进行编辑和设计。

  - **ui_widget.h：**
    - `ui_widget.h` 文件是Qt的用户界面文件自动生成的，它是通过`uic`（用户界面编译器）从 `widget.ui` 文件生成的。
    - 这个文件定义了窗口的用户界面，其中包含了窗口中各个控件的声明和初始化代码。
    - 通常情况下，`不需要手动修改这个文件`，因为它会自动由Qt工具生成和更新。

#### 2.1.4.1 widget.h文件

```cpp
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
    Q_OBJECT // 宏,使用Qt信号与槽机制时必须添加

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui; // Ui::Widget类的指针,指向可视化设计生成的窗口
};
#endif // WIDGET_H
```

**widget.h文件解释：**

- `#ifndef WIDGET_H` 和 `#define WIDGET_H`：头文件保护宏，确保头文件内容只被编译一次，防止重复包含。
- `#include <QWidget>`：包含QWidget类的头文件，QWidget是Qt中所有用户界面类的基类。
- `QT_BEGIN_NAMESPACE` 和 `QT_END_NAMESPACE`：Qt的命名空间开始和结束标记。
- `namespace Ui { ... }`：命名空间Ui，其中包含了在ui_widget.h中定义的Widget类的前向声明。
- `class Widget : public QWidget`：Widget类的声明，继承自QWidget类。
- `Q_OBJECT`：Qt中使用信号与槽机制时必须添加的宏，用于支持Qt的元对象系统。
- `Widget(QWidget *parent = nullptr)`：Widget类的构造函数声明，可以接收一个QWidget类型的父对象指针，默认为nullptr。
- `~Widget()`：Widget类的析构函数声明，用于释放资源和清理工作。
- `Ui::Widget *ui`：指向Ui::Widget类的指针，用于访问在可视化设计中生成的窗口部件。
- `#endif // WIDGET_H`：头文件结束标记，结束头文件保护宏的定义。



#### 2.1.4.2 widget.cpp文件

```cpp
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
```

**widget.cpp文件解释：**

- `#include "widget.h"` 和 `#include "ui_widget.h"`：分别包含了窗口类的头文件和ui_widget.h文件，以便在此文件中使用Widget类和Ui::Widget类。
- `Widget::Widget(QWidget *parent)`：Widget类的构造函数实现，接收一个QWidget类型的父对象指针，默认为nullptr。
  - 在构造函数中，创建了一个新的Ui::Widget对象并将其分配给ui指针。
  - 调用了ui指针的`setupUi()`函数，用于初始化窗口的可视化设计内容。
- `Widget::~Widget()`：Widget类的析构函数实现，用于释放ui指针所指向的对象的内存空间。

#### 2.1.4.3 ui_widget.cpp文件

```cpp
#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget //封装了可视化设计的窗口的类
{
public:

    // 注意:Ui_Widget没有父类,它不是窗口类,只是一个可视化设计的类
    void setupUi(QWidget *Widget)
    {
        // ....
    } // setupUi

    // ....
};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

```

**ui_widget.cpp文件解释：**

- `#ifndef UI_WIDGET_H` 和 `#define UI_WIDGET_H`：头文件保护宏，确保头文件内容只被编译一次，防止重复包含。
- `#include <QtCore/QVariant>`、`#include <QtWidgets/QApplication>` 和 `#include <QtWidgets/QWidget>`：包含了Qt的相关头文件。
- `class Ui_Widget`：封装了可视化设计的窗口的类，用于定义窗口的布局和部件。
- `void setupUi(QWidget *Widget)`：Ui_Widget类的成员函数，用于设置窗口的布局和部件。
- `namespace Ui { class Widget: public Ui_Widget {}; }`：Ui命名空间中的Widget类，继承自Ui_Widget类，用于访问可视化设计的窗口部件。
- `#endif // UI_WIDGET_H`：头文件结束标记，结束头文件保护宏的定义。

# 第3章Qt框架功能概述



# 第4章常用界面组件的使用



