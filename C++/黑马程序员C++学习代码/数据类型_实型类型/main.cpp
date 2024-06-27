#include <iostream>

using namespace std;

int main()
{
	/*数据类型——实型练习*/

	//1、单精度浮点型——float
	float f = 3.14f;//f表示单精度浮点型，不加f默认为double

	//2、双精度浮点型——double
	double d = 3.14;

	//3、长双精度浮点型——long double
	long double ld = 3.14;

	//4、科学计数法
	float f1 = 3e2;//代表3*10^2
	float f2 = 3e-2;//代表3*10^-2
	double d1 = 3e8;//代表3*10^8

	//输出
	cout<< "单精度浮点型f："<< f << endl;
	cout<< "双精度浮点型d："<< d << endl;
	cout<< "长双精度浮点型ld："<< ld << endl;
	cout<< "科学计数法f1："<< f1 << endl;//输出300
	cout<< "科学计数法f2："<< f2 << endl;//输出0.03
	cout<< "科学计数法d1："<< d1 << endl;//因为C++ 的输出默认使用科学计数法来显示大数字，所以输出3e+08
	cout<< "科学计数法d1："<< fixed << d1 << endl;//使用fixed来取消科学计数法，输出300000000


	//查看数据类型占用内存空间
	cout << "float占用内存空间：" << sizeof(float) << "字节" << endl;
	cout << "double占用内存空间：" << sizeof(double) << "字节" << endl;
	// Notes：长双精度浮点型是双精度浮点型的扩展，精度更高，占用内存更大，通常占用不小于8个字节
	cout << "long double占用内存空间：" << sizeof(long double) << "字节" << endl;

	return 0;
}