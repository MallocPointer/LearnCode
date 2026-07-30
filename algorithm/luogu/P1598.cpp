#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int cnt[26] = { 0 };
	string s;

	// 读入 4 行
	for (int i = 0; i < 4; i++) {
		getline(cin, s);
		for (char c : s) {
			if (c >= 'A' && c <= 'Z') {
				cnt[c - 'A']++;
			}
		}
	}

	// 找最大高度
	int max_high = 0;
	for (int i = 0; i < 26; i++) {
		max_high = max(max_high, cnt[i]);
	}

	// 从上到下打印柱状图
	for (int h = max_high; h >= 1; h--) {
		int last = -1;
		// 找本行最后一个需要输出的位置，避免行尾空格
		for (int i = 25; i >= 0; i--) {
			if (cnt[i] >= h) {
				last = i;
				break;
			}
		}

		for (int i = 0; i <= last; i++) {
			if (cnt[i] >= h) {
				cout << "*";
			}
			else {
				cout << " ";
			}
			if (i != last) cout << " ";
		}
		cout << "\n";
	}

	// 输出字母行
	for (int i = 0; i < 26; i++) {
		cout << char('A' + i);
		if (i != 25) cout << " ";
	}

//	system("pause");
	return 0;
}
