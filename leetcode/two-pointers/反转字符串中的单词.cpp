// https://leetcode.cn/problems/reverse-words-in-a-string/submissions/749724417/?envType=problem-list-v2&envId=two-pointers


#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        vector<string> ch;

        // flase意义为前序索引不为空
        bool flag = false;   // 判断是否为空格以及是否需要跳过
        int slow, fast;
        slow = fast = 0;
        for (int i = 0; i < size; i++, fast++) {
            if (s[fast] == ' ') {

                if (slow != fast) ch.push_back(s.substr(slow, fast - slow));
                //                fast++;
                slow = fast  + 1;

            }
        }

        // 当出现最后一个单词之后没有空格，那么就需要特判
        if (slow < size) ch.push_back(s.substr(slow));
        reverse(ch.begin(), ch.end());
        string res;
        for (int i = 0; i < ch.size(); i++) {
            if (i > 0) res += ' ';
            res += ch[i];
        }
        return res;
    }

};



int main() {
    Solution s;
    string str = "hello worrld";
    string res = s.reverseWords(str);cout << res << endl;
    return 0;
}