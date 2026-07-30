#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> dir(n);
	vector<string> name(n);

	for (int i = 0; i < n; i++) {
		cin >> dir[i] >> name[i];
	}

	int cur = 0;  // 当前所在位置（编号）

	while (m--) {
		int cmd, step;
		cin >> cmd >> step;

		bool moveNext = (dir[cur] ^ cmd);  //是否顺时针
		step %= n;                         //防止无意义大步数

		//直接计算最终位置而不是一步一步模拟走
		if (moveNext) {
			cur = (cur + step) % n;
		}
		else {
			cur = (cur - step + n) % n;
		}
	}

	cout << name[cur] << endl;

//	system("pause");
	return 0;
}
