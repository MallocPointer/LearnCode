//函数模板的局限性
//函数模板在比较其他非常规数据类型时需要重写

#include <iostream>
using namespace std;

class Person {
public:
	int age;
	string name;

	bool operator==(const Person &other) const {
		if (this->age == other.age && this->name == other.name) {
			return true;
		}
		else return false;
	}

	Person() {

	}

	Person(int age, string name) {
		this->age = age;
		this->name = name;
	}
};

template <class T>
void compare(const T& a, const T& b) {
	if (a == b) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}

void test1() {
	Person p1(18, "XiaoMing");
	Person p2(18, "XiaoMing");
	Person p3(17, "XiaoHong");
	
	compare(p1, p2);
	compare(p2, p3);
}

void test2() {
	int a = 1;
	int b = 2;
	compare(a, b);
}


int main(void) {
	cout << "test1: ";
	test1();

	cout << "test2:  ";
	test2();
	system("pause");
	return 0;
}