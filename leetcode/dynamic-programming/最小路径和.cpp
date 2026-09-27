// https://leetcode.cn/problems/minimum-path-sum/description/?envType=problem-list-v2&envId=dynamic-programming

// 我去 dp轻而易举啊，这几天的dp这么顺利，第二道拿下

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int INF = INT_MAX;
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INF));
        dp[0][0] = grid[0][0];


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    dp[0][j] = dp[0][j - 1] + grid[0][j];
                    continue;
                }
                if (j == 0) {
                    dp[i][0] = dp[i - 1][0] + grid[i][0];
                    continue;
                }

                dp[i][j] = min (dp[i - 1][j] + grid[i][j], dp[i][j]);
                dp[i][j] = min (dp[i][j - 1] + grid[i][j], dp[i][j]);
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main (void) {
    Solution s;
//    vector<vector<int>> grid;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << s.minPathSum(grid);

    return 0;
}