#include <iostream>

using namespace std;

using llong = long long;

int main() {
	llong n;
	cin >> n;

	llong left = 0, right = 100000;
	llong ans = 0;

	while (left <= right) {
		llong mid = left + (right - left) / 2;
		llong cube = mid * mid * mid;

		if (cube <= n) {
			ans = mid;   // 记录当前合法值
			left = mid + 1;   // 尝试更大的
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans;
//	system("pause");
	return 0;
}