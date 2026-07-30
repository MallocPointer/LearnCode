//类模板的成员函数只有在调用之后才会创建
//并不是一开始就创建，而是在模板调用时再生成

#include <iostream>
using namespace std;

class Person1 {
public:
	void showPerson1() {
		cout << "Person1" << endl;
	}
};

class Person2 {
public:
	void showPerson2() {
		cout << "Person2" << endl;
	}
};

template <class T>
class MyClass {
public:
	T obj;
	
	void fun1() {
		obj.showPerson1();
	}

	void fun2() {
		obj.showPerson2();
	}
};

void test01() {
	MyClass<Person1> m;
	m.fun1();
}
/*
void test02() {
	MyClass<Person2> m;
	m.fun2();
	m.fun1();
}
*/

int main(void) {

	test01();
//	test02();
	system("pause");
	return 0;
}