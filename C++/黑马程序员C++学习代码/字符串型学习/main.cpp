#include <iostream>
#include <string> // 字符串类

using namespace std;

int main()
{
	// 1、C风格字符串
	// char 字符串名[] = "字符串内容";
	// 注意事项：字符串名后面的中括号不能省略，中括号中也不能写数字，否则会报错
	char str1[] = "Hello, World!";
	cout << str1 << endl;

	// 2、C++风格字符串
	// string 字符串名 = "字符串内容";
	// 注意：string 类型需要包含头文件 #include <string>
	string str2 = "Hello, C++!";
	cout << str2 << endl;

	return 0;
}