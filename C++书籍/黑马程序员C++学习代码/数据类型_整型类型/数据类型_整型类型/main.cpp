#include <iostream>
#include <string>

using namespace std;

int main()
{
	// 整型(-32768~32767)
	// 1、短整型
	short a = 10;
	//short int a = 32768; // 32768超出了short int的范围,会报错
	// 2、整型(-2^31~2^31-1)
	int b = 10;
	// 3、长整型(-2^63~2^63-1)
	 long c = 10;
	// 4、长长整型(-2^63~2^63-1)
	 long long d = 10;


	 cout << "a = " << a << endl;
	 cout << "b = " << b << endl;
	 cout << "c = " << c << endl;
	 cout << "d = " << d << endl;

	 return 0;
}