在Qt中，如果你想获取当前线程的线程号，可以使用`QThread`类提供的方法。Qt提供了几种方法来获取线程相关的信息，其中包括线程ID。你可以使用`QThread::currentThreadId()`来获取当前线程的线程ID。

以下是一个简单的示例代码，演示如何在Qt中获取当前线程的线程ID：

```cpp
#include <QCoreApplication>
#include <QThread>
#include <QDebug>

void printThreadId() {
    qint64 threadId = reinterpret_cast<qint64>(QThread::currentThreadId());
    qDebug() << "Current thread ID:" << threadId;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    printThreadId();

    QThread thread;
    QObject::connect(&thread, &QThread::started, &printThreadId);
    thread.start();
    thread.wait();

    return a.exec();
}
```

在这个示例中，`QThread::currentThreadId()`返回一个`Qt::HANDLE`，这实际上是一个平台相关的类型。为了打印线程ID，我们将它转换为一个整数类型（在这个例子中是`qint64`）。

主要步骤如下：

1. 在主线程中调用`printThreadId()`函数，打印主线程的线程ID。
2. 创建一个新的`QThread`对象，并将它的`started`信号连接到`printThreadId()`槽，以便在新线程启动时打印其线程ID。
3. 启动新线程，并等待其完成。

这段代码将显示主线程和新线程的线程ID。

请注意，在不同的平台上，`QThread::currentThreadId()`返回的类型可能有所不同，但通常可以通过强制转换为整数类型来处理。