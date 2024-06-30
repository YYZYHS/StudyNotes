#include <iostream>		// C++标准输入输出库,在C++中常用cin和cout进行输入输出
#include <cstdio>		// C标准输入输出库,在C语言中常用scanf和printf进行输入输出
using namespace std;

// 清空输入缓冲区的跨平台方法
void clearInputBuffer() {
	// 清空输入缓冲区,避免输入缓冲区中的字符对后续的输入操作产生影响
	int c,count=0;
	while ((c = getchar()) != '\n' && c != EOF) // 当输入缓冲区中还有字符时
	{
		count++;
	}
	cout << "清空了" << count << "个字符" << endl;
}

int main()
{
	// 本代码用于演示字符型数据类型的使用

	// 1.字符型变量的创建方式
	char ch = 'A';
	cout << ch << endl;

	// 2.字符型变量所占内存大小
	cout << "sizeof(char) = " << sizeof(char) << endl; 

	// 3.字符型变量常见错误
	// char ch1 = "A"; // 错误，双引号表示字符串，单引号表示字符,创建字符型变量时只能用单引号
	// char ch2 = 'AB'; // 错误，单引号内只能有一个字符


	// 4.常见字符型变量对应的ASCII码值
	char ch3 = 'A';
	cout << ch3 << "=" << (int)ch3 << endl; // 65
	char ch4 = 'a';
	cout << ch4 << "=" << (int)ch4 << endl; // 97
	char ch5 = '0';
	cout << ch5 << "=" << (int)ch5 << endl; // 48

	// 5.字符型变量的输入:C++中的字符型变量可以通过cin进行输入
	char ch6;
	cout << "请输入一个字符：" << endl;
	cin >> ch6;
	cout << "您输入的字符是：" << ch6 << "它的ASCII码值是：" << (int)ch6 << endl;
	
	clearInputBuffer(); // 清空输入缓冲区

	// 6.字符型变量的输入:C语言中的字符型变量可以通过scanf进行输入
	 char ch7;
	 printf("请输入一个字符：\n");
	 fflush(stdin); // 清空输入缓冲区
	 //scanf("%c", &ch7); // scanf函数已经被淘汰，该语句在高版本的VS中可能会出现问题,建议使用scanf_s
	 scanf_s("%c", &ch7,1);
	 printf("您输入的字符是：%c 它的ASCII码值是：%d\n", ch7, ch7);

	return 0;
}