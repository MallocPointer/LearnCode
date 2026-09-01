// https://leetcode.cn/problems/repeated-dna-sequences/submissions/746138461/?envType=problem-list-v2&envId=sliding-window

/*
 *               第一次修改
 *      ATTITION： 第一次修改以错误告终，但是下次看的时候依然需要注意，这次是timeout
 *所以我猜测或许是被卡常数了 毕竟我是O(n logn)  map是红黑树实现，或许该试试哈希了，unordered_map
 *由于 s.length返回的是无符号整数
 *报错为terminate called after throwing an instance of 'std::out_of_range'
 *what():  basic_string::substr: __pos (which is 2) > this->size() (which is 1)
 *所以，不要让length函数进行可能出现的越界操作，我的解决方法是移项 -n来规避
 *

 *               第二次修改
 *果然，仅换了 #include <unordered_map> O(n)就直接通过，但是执行时间太差了，属于后5%
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        int n = 10;
        for (int i = 0; i + n <= s.length(); i++) {   // 第一次错误点
            string str = s.substr(i, n);
            if (m.find(str) != m.end()) {
                m[str]++;
            }else m[str] = 1;
        }

//      int max = 0;
        vector<string> res;
        for (auto iter = m.begin(); iter != m.end(); iter++)
            if (iter->second >= 2) res.push_back(iter->first);



        return res;
    }
};

int main(void) {


    return 0;
}