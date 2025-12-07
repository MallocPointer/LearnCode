//模板关键字 template
//可以有显式和隐式两种方法 函数<数据结构>(参数)

#include <iostream>
using namespace std;

//两个整型交换变量函数
void swapInt(int &a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

//交换两个浮点型函数
void swapDouble(double &a, double &b) {
	double temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 10;
	int b = 20;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	swapInt(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double c = 1.1;
	double d = 2.2;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
}


//函数模板
template<typename T>
void temp(T &a, T &b) {
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	T temp = a;
	a = b;
	b = temp;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

void test02() {
	int e = 5, f = 10;
	double g = 5.2, h = 4.5;

	cout << "e = " << e << endl;
	cout << "f = " << f << endl;
	temp(e, f);
	cout << "e = " << e << endl;
	cout << "f = " << f << endl;
}


int main(void) {
	int a = 3, b = 125;
	temp(a, b);   //隐式数据类型
	temp<int>(a, b);   //显式指定类型

	system("pause");
	return 0;
}