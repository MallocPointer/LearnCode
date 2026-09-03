// https://leetcode.cn/problems/minimum-size-subarray-sum/submissions/746373756/?envType=problem-list-v2&envId=sliding-window

/* 第一次看起来是对的，但是我使用了线性扫描 timeout了，可惜，准备换成二分扫描，或许可以过
 *
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
///const int INF = 65535;

class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {
        const int INF = 1e9;
        int n = nums.size();
//      vector<int> pre(n);
        vector<int> pre(n + 1, 0);   // 把per[0]作为分界值好了
//      pre[0] = nums[0];
//      for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); ++it) pre[];
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }

        int minNum = INF;
        for (int i = 0; i < pre.size(); ++i) {
            auto it = lower_bound(pre.begin() + i + 1, pre.end(), pre[i] + target);
            if (it != pre.end()) {
                int j = it - pre.begin();    // j 为前缀和数组中的下标
                minNum = min(minNum, j - i);   // 修改：子数组长度为 j - i
            }
        }
        return minNum == INF ? 0 : minNum;   // 无解的时候等于INF,返回0
    }
};

int main(void) {



    return 0;
}
