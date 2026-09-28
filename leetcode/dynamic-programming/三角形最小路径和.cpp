// https://leetcode.cn/problems/triangle/description/?envType=problem-list-v2&envId=dynamic-programming

// 依旧测试用例都是让AI写的

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    const int INF = INT_MAX / 2;
    int minimumTotal(vector<vector<int>>& triangle) {
        // 要求自上到下的最小路径和，也就是自顶到下每个数字的最小路径和的min
        int deep = triangle.size();
        int n = triangle[deep - 1].size();
        vector<vector<int>> dp(deep, vector<int>(n, INF));
        dp[0][0] = triangle[0][0];
        for (int i  = 1; i < deep; i++) {
            for (int j = 0; j <= i;  j++) {
                if (j < i) dp[i][j] = min (dp[i][j], dp[i - 1][j] + triangle[i][j]);
                if (j > 0) dp[i][j] = min (dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
            }
        }
        int minRes = INF;
        for (int i = 0; i < n; i++) minRes = min (minRes, dp[deep - 1][i]);
        return minRes;
    }
};

int main(void) {
    Solution s;

    // 示例 1
    vector<vector<int>> t1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "示例1: " << s.minimumTotal(t1) << " (期望 11)" << endl;

    // 示例 2
    vector<vector<int>> t2 = {{-10}};
    cout << "示例2: " << s.minimumTotal(t2) << " (期望 -10)" << endl;

    // 全负数，验证 min 取值
    vector<vector<int>> t3 = {{-1}, {-2, -3}, {-4, -5, -6}};
    cout << "全负数: " << s.minimumTotal(t3) << " (期望 -10)" << endl;

    // 五行随机例，路径 1+2+1+5+1=10
    vector<vector<int>> t4 = {{1}, {4, 2}, {3, 9, 1}, {8, 4, 7, 5}, {2, 6, 3, 1, 9}};
    cout << "随机例: " << s.minimumTotal(t4) << " (期望 10)" << endl;

    return 0;
}