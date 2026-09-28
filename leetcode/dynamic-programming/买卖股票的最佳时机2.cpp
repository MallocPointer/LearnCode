// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=problem-list-v2&envId=dynamic-programming

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<bool> dp(n, false);
        int money = 0;
        for (int i = 1; i < n; i++) if (prices[i] > prices[i - 1]) dp[i] = true;   // 标记为涨价了
        for (int i = 0; i < n; i++) if (dp[i]) money += prices[i] - prices[i - 1];

        return money;
    }
};

int main (void) {
    Solution s;
    vector<int> prices = {7,6,4,3,1};
    cout << s.maxProfit(prices);

    return 0;
}