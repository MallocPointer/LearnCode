#include <iostream>
#include <string>
using namespace std;

//类模板对象做函数模板
template <class T1, class T2>
class Person {
public:
	T1 Name;
	T2 Age;

	Person(T1 Name, T2 Age) {
		this->Name = Name;
		this->Age = Age;
	}

	void showPerson() {
		cout << "Name: " << this->Name << endl
			<< "Age: " << this->Age << endl;
	}

};

//指定传入类型
void printPerson1(Person<string, int> &p) {   //类模板对象做函数参数
	p.showPerson();

}

void test1() {
	Person<string, int> p("xiaoming", 18);
	printPerson1(p);
}

//参数模板化
template <class T1, class T2>
void printPerson2(Person<T1, T2> &p) {
	p.showPerson();
	cout << "T1的数据类型为 " << typeid(T1).name() << endl;
	cout << "T2的数据类型为 " << typeid(T2).name() << endl;
}

void test2() {
	Person<string, int> p("xiaohong", 17);
	printPerson2(p);
}

//整个类模板化
template <class T>
void printfPerson3(T p) {
	p.showPerson();
}

void test3() {
	Person<string, int> p("xiaoliang", 16);
	printfPerson3(p);
}

int main(void) {
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}