// https://leetcode.cn/problems/maximum-subarray/submissions/751242486/?envType=problem-list-v2&envId=dynamic-programming

// 既然是求和最大的子串，那我是不是可以直接把状态定义为到此索引可达到的最大和
// 算了，我觉得先预处理一个前缀和出来吧 方便做差就是了
// 不对，似乎无法转移状态，仅差值是不对的

// AI说，这叫 Kadane算法
// 其状态定义量为dp[i]代表到达num[i]时的最大子串，所以可得，dp[i] = max(dp[i], dp[i - 1] + nums[i]);
// 由于我没有预先把数据填入vector,所以换一下转移方程，不过预处理的话，会多申请一个O(n)的数组

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];   // 0索引的数据仅可以和自己成为一个数组
        int ans = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


int main() {


    return 0;
}