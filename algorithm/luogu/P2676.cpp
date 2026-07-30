// https://www.luogu.com.cn/problem/P2676

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using llong = long long;

int main() {
	int n;
	llong B;
	cin >> n >> B;

	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];

	sort(h.begin(), h.end(), greater<int>());

	llong sum = 0;
	int cnt = 0;
	for (int x : h) {
		sum += x;
		cnt++;
		if (sum >= B) {
			cout << cnt << "\n";
			break;
		}
	}
	return 0;
}
