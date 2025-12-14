#include <iostream>
#include <string>
using namespace std;

//类模板
template <class NameType, class AgeType>
class Person {
public:
	Person(NameType name, AgeType age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	NameType m_Name;
	AgeType m_Age;

	//1. 类模板无法使用自动数据类型推导
	void showPerson() {
		cout << "name:" << this->m_Name <<endl << "age:" << this->m_Age << endl;
	}
};


//2. 类模板可以在参数列表中有默认参数
//注意：这里写了class ColorType = int 下面实例化对象的时候就能
template <class NameType, class ColorType = string>
class Car {
public:
	NameType name;
	ColorType color;
	Car(NameType name, ColorType color) {
		this->color = color;
		this->name = name;
	}
	void showCat() {
		cout << "CarName " << this->name << endl << "CarColor " << this->color << endl;
	}
};


int main(void) {

	Person<string, int> p("zhangsan", 18);
	p.showPerson();

	cout << endl;

	Car<string> c("FenTian", "red");
	c.showCat();

	system("pause");
	return 0;
}