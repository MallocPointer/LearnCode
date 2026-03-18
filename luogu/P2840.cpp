#include <iostream>

using namespace std;

int main() {
	const int MOD = 1e9;

	int n, w;
	cin >> n >> w;

	int* value = new int[n];
	for (int i = 0; i < n; i++) cin >> value[i];

	int* dp = new int[w + 1];
	for (int i = 0; i <= w; i++) dp[i] = 0;

	dp[0] = 1;

	for (int i = 1; i <= w; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= value[j]) dp[i] = (dp[i] + dp[i - value[j]]) % MOD;
		}
	}

	cout << dp[w] << endl;

	delete[] value;
	delete[] dp;

	return 0;
}