// 如果希望deque是只读状态，所用的迭代器也需要相应切换为const_iterator
// deque和vector的构造方式几乎一样，可以灵活选择使用

#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int> &d) {
    for (deque<int>::const_iterator i = d.begin(); i != d.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

void test01() {
    deque<int> d;
    for (int i = 0; i < 10; i++) d.push_back(i);   // 填充从0到10
    cout << "d: ";
    printDeque(d);

    // 将d中的数据全部复制到d1中
    deque <int> d1(d.begin(), d.end());
    cout << "d1: ";
    printDeque(d1);

    // 赋值10个100
    deque<int>  d3(10, 100);
    cout << "d3: ";
    printDeque(d3);

    // 拷贝构造形式
    deque<int> d4(d1);
    cout << "d4: ";
    printDeque(d4);
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    printDeque(deque);
    test01();
    return 0;
}

