// https://leetcode.cn/problems/unique-paths-ii/description/?envType=problem-list-v2&envId=dynamic-programming

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();   // 行
        int m = obstacleGrid[0].size();   // 列
        if (obstacleGrid[n - 1][m - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<int> Gmap(n * m, 0);   // 值为0可通过，1为障碍
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (obstacleGrid[i][j] == 1) Gmap[i * m + j] = 1;

        vector<int> dp(n * m, 0);
        // 这样不对的，因为这样会损坏最上和最左的障碍情况
        // for (int i = 0; i < n * m; i++)
        //     if (i < m || i % m == 0) Gmap[i] = 1, dp[i] = 1;

        dp[0] = (Gmap[0] == 0) ? 1 : 0;
        for (int i = 1; i < m; i++) dp[i] = (Gmap[i] == 0) ? dp[i - 1] : 0;
        for (int i = m; i < n * m; i += m) dp[i] = (Gmap[i] == 0) ? dp[i - m] : 0;

        for (int i = m + 1; i < n * m; i++) {
            if (i % m == 0) continue;
            int sum = 0;
            if (Gmap[i] == 1) {
                dp[i] = 0;
                continue;
            }
            if (Gmap[i - m] != 1) sum += dp[i - m];
            if (Gmap[i - 1] != 1) sum += dp[i - 1];
            dp[i] = sum;
        }
        return dp[n * m - 1];
    }
};


int main(void) {

    Solution s;

    // 测试用例1
    vector<vector<int>> obstacleGrid1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << "Test 1: "
         << s.uniquePathsWithObstacles(obstacleGrid1)
         << endl;


    // 测试用例2
    vector<vector<int>> obstacleGrid2 = {
        {0, 1},
        {0, 0}
    };

    cout << "Test 2: "
         << s.uniquePathsWithObstacles(obstacleGrid2)
         << endl;


    // 测试用例3：起点就是障碍
    vector<vector<int>> obstacleGrid3 = {
        {1, 0},
        {0, 0}
    };

    cout << "Test 3: "
         << s.uniquePathsWithObstacles(obstacleGrid3)
         << endl;


    // 测试用例4：终点是障碍
    vector<vector<int>> obstacleGrid4 = {
        {0, 0},
        {0, 1}
    };

    cout << "Test 4: "
         << s.uniquePathsWithObstacles(obstacleGrid4)
         << endl;


    // 测试用例5：没有障碍
    vector<vector<int>> obstacleGrid5 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    cout << "Test 5: "
         << s.uniquePathsWithObstacles(obstacleGrid5)
         << endl;


    return 0;
}