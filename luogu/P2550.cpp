#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	// 标记中奖号码
	bool win[34] = { false };
	for (int i = 0; i < 7; i++) {
		int x;
		cin >> x;
		win[x] = true;
	}

	// prize[i] 表示命中 i 个号码的彩票张数
	int prize[8] = { 0 };

	// 处理每一张彩票
	for (int i = 0; i < n; i++) {
		int match = 0;   // 看有几个相同的
		for (int j = 0; j < 7; j++) {
			int x;
			cin >> x;
			if (win[x]) {   //查找中奖号码对应号码是否标记为中奖
				match++;
			}
		}
		prize[match]++;
	}


	for (int i = 7; i >= 1; i--) {
		cout << prize[i];
		if (i != 1) cout << " ";
	}

	system("pause");
	return 0;
}
