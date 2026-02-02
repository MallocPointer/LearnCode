//https://www.luogu.com.cn/problem/P2249

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

//  sort(arr.begin(), arr.end());
	for (int i = 0; i < m; i++) {
		int which;
		cin >> which;

		auto it = lower_bound(arr.begin(), arr.end(), which);
		int place;
		if (it != arr.end() && *it == which) place = (int)(it - arr.begin()) + 1; // 题目下标从 1 开始
		else place = -1;

		cout << place << " ";
	}

//	system("pause");
	return 0;
}
