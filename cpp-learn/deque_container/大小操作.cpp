/*  函数原型
 *  deque.empty();   判断容器是否为空
 *  deque.size();   返回容器中的元素个数
 *  deque.resize(num);  重新指定容器的长度为num, 若容器变长，则以默认值填充新位置  如果容器变短，则末尾超出长如度的元素被删除
 *  deque.resize(num, elem);   重新指定容器的长度为num, 若容器变长，则以 elem 充新位置   如果容器变短，则末尾超出长如度的元素被删除
 *  */

#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int> &d) {
    for (deque<int>::const_iterator it = d.begin(); it < d.end(); it++) cout << *it << " " << endl;
}

void test01() {
    deque<int> d1;

    // deque.empty用法
    if (d1.empty()) cout << "d1 is empty" << endl; else cout << "d1 is not empty" << endl;
    for (int i = 0; i < 10; i++) d1.push_back(i);
    if (d1.empty()) cout << "d1 is empty" << endl; else cout << "d1 is not empty" << endl;

    // deque.size()
    cout << d1.size() << endl;

    // deque.resize();
    d1.resize(13);   // 默认填充的是0
    for (deque<int>::iterator it = d1.begin(); it < d1.end(); it++) cout << *it << " ";
    cout << endl;

    d1.resize(7);   // 仅保留大小为7 超过的地方直接丢弃
    for (deque<int>::iterator it = d1.begin(); it < d1.end(); it++) cout << *it << " ";
    cout << endl;

    d1.resize(10, 999);
    for (deque<int>::iterator it = d1.begin(); it < d1.end(); it++) cout << *it << " ";
    cout << endl;


}

int main (void) {
    test01();
    return 0;
}