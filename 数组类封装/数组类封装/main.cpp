#include <iostream>
#include "MyArray.hpp"
using namespace std;

void test1() {
	MyArray<int> arr1(5);

	MyArray<int> arr2(2);
	arr2 = arr1;

	MyArray<int> arr3(100);
}


int main(void) {
	test1();
	system("pause");
	return 0;
}