#include <iostream>
#include <algorithm>
//#include  <vector>
#define N 50
using namespace std;


int main (void) {

    int tri[N][N];   // 存储
//  int sum = 0;
    int dp[N][N] = {0};
    int n;   // 共有n层
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tri[i][j];   // 设置以1为基
        }
    }

    for (int j = 1; j <= n; j++) {
        dp[n][j] = tri[n][j];
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            dp[i][j] = tri[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    cout << dp[1][1] << endl;

    return 0;
}
