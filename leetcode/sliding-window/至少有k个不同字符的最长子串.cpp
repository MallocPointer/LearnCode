// https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/submissions/746641766/?envType=problem-list-v2&envId=sliding-window

/*第一次交又错了，好像是我判断顺序不太对 修改一下
 *
 *第二次过了，而且耗时0ms 拿下今天的第一道题
 * 原来 if (cnt[d] == k) okCnt--; 写在 cnt[d]-- 之后
 * 移到减之前：只有“减之前刚好 == k”，减完才变成不达标
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int ans = 0;   // 记录答案

        // 改成从1开始
        for (int i = 1; i <= 26; i++) {   // 采取字母种类的滑动窗口
            int liveType = 0;   // 初始化已经存在的个数为0
            vector<int> cnt(26, 0);   // 每个字母在窗口内存在的数目记录
            int left  = 0;   // 定义滑动窗口的左端点
            int okCnt = 0;   // 符合条件的字母个数


            for (int j = 0; j < n; j++) {
                char c = s[j];
                int now = c - 'a';
                cnt[now]++;
                if (cnt[now] == 1) liveType++;
                if (cnt[now] == k) okCnt++;

                while (liveType > i) {
                    int d = s[left] - 'a';

                    if (cnt[d] == k) okCnt--;
                    cnt[d]--;
                    if (cnt[d] == 0) liveType--;

                    left++;
                }

                if (liveType == i && okCnt == i) ans = max(ans, j - left + 1);
            }


        }
        return ans;
    }
};

int main() {

    return 0;
}