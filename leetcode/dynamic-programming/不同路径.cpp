// https://leetcode.cn/problems/unique-paths/description/?envType=problem-list-v2&envId=dynamic-programming

// 采取策略，每个位置的可达路径数目都是它的上方和左方的位置的路径数目的和
// 简单，今天 2026.9.26的第二道0ms了 这道题都没思考，直接3分钟就写完

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> nums(n * m, 0);
        for (int i = 0; i < n * m; i++)
            if (i < n || i % n == 0) nums[i] = 1;

        for (int i = 0; i < n * m; i++) {
            if (i < n || i % n == 0) continue;
            nums[i] = nums[i - n] + nums[i - 1];
        }
        return nums[n * m - 1];
    }
};

int main (void) {
    Solution s;
    int res = s.uniquePaths(3, 7);
    cout << res << endl;

    return 0;
}