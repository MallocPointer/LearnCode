#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	vector<int> num(n + 1);

	for (int i = 0; i <= n; i++) {
		cin >> num[i];
	}

	for (int i = n; i >= 0; i--) {
		if (num[n - i] == 0)
			continue;

		// 如果不是最高次项（i != n）且系数为正数，手动输出 '+'
		if (i != n && num[n - i] > 0) {
			cout << "+";
		}

		// 负数手动输出 '-'
		if (num[n - i] < 0) {
			cout << "-";
		}

		if ((num[n - i] != 1 && num[n - i] != -1) || i == 0) {
			if (num[n - i] > 0) {
				cout << num[n - i];
			}
			else {
				cout << -num[n - i];
			}
		}

		// 处理未知数 x 及其指数
		if (i > 1) {
			cout << "x^" << i;
		}
		else if (i == 1) {
			cout << "x";
		}
	}

//	system("pause");
	return 0;
}