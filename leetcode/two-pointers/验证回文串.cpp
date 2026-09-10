// https://leetcode.cn/problems/valid-palindrome/?envType=problem-list-v2&envId=two-pointers


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int beg = 0;
		int end = s.size() - 1;

		bool flag = true;   // 默认是回文数
		while (beg <= end) {

			if (!isalnum((unsigned char)s[beg])) {   // 跳过非字母数字
				beg++;
				continue;
			}
			if (!isalnum((unsigned char)s[end])) {
				end--;
				continue;
			}
			if (tolower((unsigned char)s[beg]) != tolower((unsigned char)s[end])) {
				return false;
			}
			beg++;
			end--;
		}
		return flag;
	}
};


int main(void) {



	return 0;
}
