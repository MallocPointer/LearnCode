/*  使用的函数原型
 *  deque& operator=(const deaque *deq);    重载等号赋值操作
 *  assign(begin, end);   将[debin, end)区间中的数据拷贝估值给本身
 *  assign(n, elem);   将n个elem拷贝赋值给本身
 *  */

#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int> &d) {
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it) cout << *it << " ";
    cout << endl;
}

void test01() {
    deque<int> d1;
    for (int i = 0; i < 10; i++) d1.push_back(i);
    cout << "d1: ";
    printDeque(d1);

    // operator= 赋值
    deque<int> d2;
    d2 = d1;
    cout << "d2: ";
    printDeque(d2);

    // assign 迭代器赋值
    deque<int> d3;
    d3.assign(d2.begin(), d2.end());
    cout << "d3: ";
    printDeque(d3);

    // assign 区间赋值
    deque<int> d4;
    d4.assign(5,  10);
    cout << "d4: ";
    printDeque(d4);
}


int main (void) {

    test01();


    return 0;
}