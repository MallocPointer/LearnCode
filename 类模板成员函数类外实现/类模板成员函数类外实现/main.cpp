#include <iostream>
#include <string>
using namespace std;

//类模板成员函数类外实现
template <class T1, class T2>
class Person {
public:
	T1 Name;
	T2 Age;

	Person(T1 name, T2 age);
//		this->Age = age;
//		this->Name = name;

	void showPerson();
//		cout << "Name:  " << this->Age << endl
//			<< "Age:  " << this->Name << endl;
//	}

};

//构造函数的类外实现
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->Age = age;
	this->Name = name;
}

//成员函数的类外实现
template <class T1, class T2>
void Person<T1, T2>::showPerson() {
	cout << "Name:  " << this->Age << endl
		<< "Age:  " << this->Name << endl;
}

void test1() {
	Person<string, int> P("Tom", 18);
	P.showPerson();
}

int main(void) {
	test1();

	system("pause");
	return 0;
}