#include <iostream>
using namespace std;

int main()
{
	// sizeof关键字学习

	// 已知: 
	//  short类型占2个字节, int类型占4个字节, 
	// long类型占4个字节, long long类型占8个字节

	// sizeof关键字用于获取数据类型或变量的大小
	cout << "sizeof(short) = " << sizeof(short) << endl;
	cout << "sizeof(int) = " << sizeof(int) << endl;
	cout << "sizeof(long) = " << sizeof(long) << endl;
	cout << "sizeof(long long) = " << sizeof(long long) << endl;

	// 整型变量大小比较
	// short < int <= long <= long long

	return 0;
}