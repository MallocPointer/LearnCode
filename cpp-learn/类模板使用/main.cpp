#include <iostream>
#include "MyArray.h"
#include <string>

using namespace std;

void printIntArray(MyArray<int>& arr) {
    for (int i = 0; i < arr.getSize(); i++) cout << arr[i] << endl;
}


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
    for (int i = 0; i < 5; i++) arr1.Push_Back(i);   // 利用尾插法向数组中插入数
    cout << "arr1 的打印输出为: " << endl;
    printIntArray(arr1);
    cout << "arr1 的容量为: " << arr1.getCapacity() << endl;
    cout << "arr1 的大小为: " << arr1.getSize() << endl;
}

// 测试自定义数据类型
class Person
{
public:
  //  Person(){}
    


    string name;
    int age;
};

int main (void) {

//    test01();
//    cout << "Hello World" << endl;
    test02();
    return 0;
}