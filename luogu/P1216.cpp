#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
const int INF = 1000;
int weight[INF][INF];
int dp[INF][INF];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> weight[i][j];

	dp[0][0] = weight[0][0];
	for (int i = 1; i < n; i++) {   // 从第二行开始，也就是第一索引
		dp[i][0] = dp[i - 1][0] + weight[i][0];   // 每个最左边的都得从上一行的最左边下来
		dp[i][i] = dp[i - 1][i - 1] + weight[i][i];
		for (int j = 1; j < i; j++) 
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + weight[i][j];
	}

	int maxnum = dp[n - 1][0];
	for (int i = 0; i < n; i++) {
		maxnum = max(maxnum, dp[n - 1][i]);
	}
	cout << maxnum << endl;
//	system("pause");
	return 0;
}