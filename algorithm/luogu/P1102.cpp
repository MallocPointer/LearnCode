// https://www.luogu.com.cn/problem/P1102

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using llong = long long;

int main() {
	int N;
	llong C;
	cin >> N >> C;

	vector<llong> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	llong ans = 0;

	for (int i = 0; i < N; i++) {
		llong target = arr[i] + C;

		auto left = lower_bound(arr.begin(), arr.end(), target);
		auto right = upper_bound(arr.begin(), arr.end(), target);

		ans += (right - left);
	}

	cout << ans << endl;

//	system("pause");
	return 0;
}