#include <iostream>
using namespace std;

// 这是一个展示转义字符使用方法的例子
int main() {

	// 转义字符

	// 换行符 \n
	cout << "Hello, World!\n";

	// 反斜杠 \\ 
	cout << "This is a backslash: \\ " << endl;

	// 水平制表符 \t
	// 水平制表符用来对齐文本或数据
	// 一个水平制表符通常等于四个空格
	cout << "Name\tAge\tGender" << endl;
	cout << "Tom\t20\tMale" << endl;
	cout << "Jerry\t22\tFemale" << endl;

	// \ddd 八进制转义字符
	// \ddd 八进制转义字符表示一个八进制数
	// 八进制数的范围是 0-7
	cout << "This is an octal number: \101" << endl;

	// \xhh 十六进制转义字符
	// \xhh 十六进制转义字符表示一个十六进制数
	// 十六进制数的范围是 0-9, A-F, a-f
	cout << "This is a hexadecimal number: \x41" << endl;

	return 0;
}