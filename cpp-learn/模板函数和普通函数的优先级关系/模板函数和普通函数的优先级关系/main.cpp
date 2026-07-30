//验证模板函数和普通函数的优先级关系

//结论：会优先调用普通函数 若强制调用模板，则需要写类似add<int>(a, b)

#include <iostream>
using namespace std;

template <typename T>
void add(T a, T b) {
	cout << "调用函数模板" << a + b << endl;
	return;
}

void add(int a, int b) {
	cout << "调用普通函数" << a + b << endl;
	return;
}

int main(void) {
	int a = 5, b = 3;
	add(a, b);
	add<int>(a, b);

	system("pause");
}
