/*   插入和删除
 *   push_bask(elem);   在容器尾部添加一个数据
 *   push_front(elem);   在容器头部插入一个数据
 *   pop_back();   删除容器的最后一个数据
 *   pop_front();   删除容器低一个数据
 *   */

#include <iostream>
#include <queue>

using namespace std;

void test01() {
    deque<int> d1;

//    for (deque<int>::iterator it = d1.begin(); it != d1.end(); ++it) d1.push_back(*it);
    for (int i = 0;i < 10;i++) d1.push_back(i);
    for (deque<int>::iterator it = d1.begin(); it != d1.end(); ++it) cout << *it << " ";
    cout << endl;

    // 添加尾部元素
    d1.push_back(999);
    for (deque<int>::iterator it = d1.begin(); it != d1.end(); ++it) cout << *it << " ";
    cout << endl;

    // 添加首部元素
    d1.push_front(999);
    for (deque<int>::iterator it = d1.begin(); it != d1.end(); ++it) cout << *it << " ";
    cout << endl;

    //删除首尾元素
    d1.pop_front();
    d1.pop_back();
    for (deque<int>::iterator it = d1.begin(); it != d1.end(); ++it) cout << *it << " ";
    cout << endl;

}

int main(void) {
    test01();

    return 0;
}