#include <iostream>
#include <windows.h>
using namespace std;

/*运动会管理系统类*/
class SportMeetManager
{
public:
    SportMeetManager();         // 构造函数
    ~SportMeetManager();        // 析构函数
    void showMenu();            // 展示菜单栏
    void showMainMenuContent(); // 展示主菜单内容
private:
};

// 菜单栏展示
void SportMeetManager::showMenu()
{
    // 输出菜单栏,并循环展示
    while(true)
    {
        // 展示菜单
        showMainMenuContent();

        // 接收用户输入
        int select = 0;
        cin >> select;

        // 根据用户输入进行相应操作
        switch(select)
        {
            case 1:
                cout << "添加记录" << endl;
                break;
            case 2:
                cout << "查询比赛详情" << endl;
                break;
            case 3:
                cout << "查询相关信息" << endl;
                break;
            case 4:
                cout << "退出系统" << endl;
                return;
            default:
                cout << "输入有误，请重新输入" << endl;
                // 暂停
                system("pause");
                break;
        }

        // 清空缓冲区
        cin.clear();
        // 忽略缓冲区中的字符
        cin.ignore();

        //清空屏幕
        system("cls");
    }
}

SportMeetManager::SportMeetManager()
{

}

SportMeetManager::~SportMeetManager()
{

}

// 展示主菜单内容
void SportMeetManager::showMainMenuContent()
{
    // 输出菜单栏
    cout << "********************xx高校运动管理系统********************" << endl;
    cout << "**\t\t1.添加记录\t\t\t\t**" << endl;
    cout << "**\t\t2.查询比赛详情\t\t\t\t**" << endl;
    cout << "**\t\t3.查询相关信息\t\t\t\t**" << endl;
    cout << "**\t\t4.退出系统\t\t\t\t**" << endl;
    cout << "**********************************************************" << endl;
}



int main()
{
    /*当输出中文产生乱码时，可以尝试使用以下代码解决*/
    SetConsoleOutputCP(CP_UTF8);            // 设置控制台编码为UTF-8,以支持中文输出
    std::setlocale(LC_ALL, "zh_CN.UTF-8");  //设置locale为UTF-8,以支持中文输出

    /*运行程序*/
    SportMeetManager sportMeetManager;      // 运动会管理系统类
    sportMeetManager.showMenu();            // 运行运动会管理系统

    return 0;
}
