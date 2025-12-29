//当类模板遇到继承时，子类在声明的时候，要指出父类中的类型
//如果不指定，编译器无法给子类分配内存
//如果想灵活指定出父类中T的数据类型，则子类也需要变成类模板

#include <iostream>
using namespace std;

template<class T>
class Base {
	T m;
};

//指明父类类型，否则无法分配内存
//class Son : public Base {     标记的这种写法是错误的 需要先明确父类中的T类型
class Son : public Base<string> {

};

void test1() {
	Son s1;
	cout << typeid(s1).name() << endl;
}

//不指定父类数据类型，子类必须依旧为模板
//如果想灵活的指定父类中的T类型，子类也需要变为类模板
template <class T1, class T2>
class Son2 : public Base<T1> {
public:
	
	Son2(){
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	T1 obj;

};

void test2() {
	Son2<int, char> son2;
}

int main(void) {

	test1();
	test2();
	system("pause");
	return 0;
}