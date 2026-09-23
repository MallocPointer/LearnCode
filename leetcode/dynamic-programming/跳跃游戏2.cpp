// https://leetcode.cn/problems/jump-game-ii/description/?envType=problem-list-v2&envId=dynamic-programming

// 既然写的是最大可跳跃的长度，那我直接无脑贪心就可以
// 贪心错了，得保持全局状态的最大，而不是当前操作轮次的最大

// 换dp，状态为到达此索引需要的最小跳数

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MAXP = 1001;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, MAXP);  // 存储到达当前地址需要的跳数
        for (int i = 0; i < n ;i++) {
            int far = min (n - 1, nums[i] + i);   //到达最远
            for (int j = i + 1; j < far; j++) dp[j] = min(dp[i] + 1, dp[j]);
        }

        return dp[n-1];

    }
};


int main(void) {
    Solution s;
    vector<int> nums{2, 3, 0, 1, 4};
    cout << s.jump(nums);


    return 0;
}