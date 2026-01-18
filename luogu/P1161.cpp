#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	const int MAXL = 2000000;
	vector<bool> lamp(MAXL + 1, false);   //开始都是关的

	for (int i = 0; i < n; i++) {
		string a_str;   //使用string是为了防止double乘法时候十分位进位导致int向下取整后加一
		int t;
		cin >> a_str >> t;

		// 把 a 转成放大 1e6 的整数 A
		long long A = 0;
		for (char c : a_str) {
			if (c != '.') {
				A = A * 10 + (c - '0');
			}
		}
		// 此时 A = a * 1e6 题目说固定6位小数

		for (int k = 1; k <= t; k++) {
			int x = (int)((long long)k * A / 1000000LL);
			if (x >= 1 && x <= MAXL) {
				lamp[x] = !lamp[x];
			}
		}
	}

	for (int i = 1; i <= MAXL; i++) {
		if (lamp[i]) {
			cout << i << '\n';
			break;
		}
	}

	system("pause");
	return 0;
}
