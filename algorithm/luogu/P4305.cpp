// https://www.luogu.com.cn/problem/P4305
// 普通的set会超时 需要使用关同步解tie

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int times;
	cin >> times;
	while (times--) {
		int n;
		cin >> n;

		vector<int> order;
		unordered_set<int> res;

		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			if (res.find(num) == res.end()) {
				order.push_back(num);
				res.insert(num);
			}
		}

		for (auto now : order) {
			cout << now << " ";
		}
		cout << "\n";
	}

//	system("pause");
	return 0;
}
