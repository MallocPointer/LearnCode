#include <iostream>
#include "MyArray.h"

using namespace std;


// 用于测试构造析构等
void test01() {
    MyArray<int> arr1(5);
    MyArray<int> arr2(arr1);

    //测试operotor=
    MyArray<int> arr3(100);
    arr3 = arr2;
}

void test02() {
    MyArray<int> arr1(5);
    for (int i = 0; i < 5; i++) {
        arr1.Push_Back(i);
    }
}

int main (void) {

    test01();
//    cout << "Hello World" << endl;
    return 0;
}