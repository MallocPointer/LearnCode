#include <iostream>
#include <algorithm>

using namespace std;

int main (void) {
    int n;
    cin >> n;
    int arr[n + 1];   // 设置为从1开始
    int dp[n + 1];
    for (int i =0; i <= n; i++) dp[i] = 1;
    for (int i = 1; i <= n; i++) cin >> arr[i];

//  dp[n + 1] = 1;   // 自己成为一个最长子序列
    for (int i = n - 1; i >= 1; i--) {
        int maxCnt = 0;   // 假设没有更大的数字 所以设置为0
         for (int j = i + 1; j <= n; j++) {
             if (arr[i] < arr[j]) {
                 maxCnt = max(maxCnt, dp[j]);
             }
         }
        dp[i] = maxCnt + 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    return 0;
}