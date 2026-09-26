// https://leetcode.cn/problems/jump-game/submissions/751542400/?envType=problem-list-v2&envId=dynamic-programming

/* main全是AI给我写的测试样例喵(
 * 而且AI的第五个样例还写错了
 *
 * 那我直接状态定义为到某个索引时候的最短跳数吧 先都初始化为1e5 + 10非法数据就可以
 * 一把通过，但是，时间复杂度以及排在所有通过里面几乎已经排名在最后了
 *
 * 所以说，我是不是只要判定是否可达即可？ 不用算跳数了，算跳和https://leetcode.cn/problems/jump-game-ii?envType=problem-list-v2&envId=dynamic-programming这个题很像
 * 我们做的似乎冗余了，不需要那么精细
 *
 * 好吧，那我O(n)进行判定当前可达最远边界为状态就可以，命名为class Solution2
 * leetcode什么破编译器配置，还得我最后写一个 return ture; 否则过不了编译，神了（但我代码确实没错
 * OK! 拿下0ms耗时，且100%击败率 直接 git push了
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    const int INF = 1e5 + 10;
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INF);   // 非法数据初始化
        dp[0] = 0;   // 自己就直接在

        if (n == 1) return true;
        if (nums[0] == 0) return false;
        int ans = INF;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0 || dp[i] == INF) continue;
            for (int j = 1; j <= nums[i] && i + j < n; j++)
                dp[i + j] = min(dp[i] + 1, dp[i + j]);
        }

        if (dp[n - 1] == INF) return false;
        return true;
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int far = 0;   // 初始可达点为0索引
        for (int i = 0; i < n; i++) {
            if (i > far) return false;   // 说明不存在
            far = max(far, i + nums[i]);
            if (far >= n - 1) return true;
        }
        return true;
    }
};

int main() {
    Solution2 sol;
    vector<vector<int>> tests = {
        {2, 3, 1, 1, 4},              // 示例1：可达，期望 true
        {3, 2, 1, 0, 4},              // 示例2：卡死在0，期望 false
        {0},                          // 单个元素，已在终点，期望 true
        {2, 0, 0},                    // 一步跳过第一个0直达终点，期望 true
        {2, 0, 1, 0},                 // 第二个0无法跳过，期望 false
        {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0},  // 长数组含0，期望 true
        {1, 0, 0, 0},                 // 每步只能走1，卡在第二个0，期望 false
        {2, 0, 2, 0, 0}               // 跳2步到下标2再跳2步到终点，期望 true
    };
    vector<bool> expected = {true, false, true, true, false, true, false, true};
    bool allPass = true;
    for (int i = 0; i < (int)tests.size(); i++) {
        bool got = sol.canJump(tests[i]);          // 调用你的解
        bool ok = (got == expected[i]);            // 与期望比对
        if (!ok) allPass = false;
        cout << "用例" << i + 1 << ": nums = [";
        for (int k = 0; k < (int)tests[i].size(); k++)
            cout << tests[i][k] << (k + 1 < (int)tests[i].size() ? "," : "");
        cout << "]  输出: " << (got ? "true" : "false")
             << "  期望: " << (expected[i] ? "true" : "false")
             << (ok ? "  ✓通过" : "  ✗未通过") << endl;
    }
    cout << (allPass ? "全部通过" : "存在未通过用例") << endl;
    return 0;
}