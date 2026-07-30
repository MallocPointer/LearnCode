#include <iostream>
using namespace std;

int a[1100][1100];  // 最大 2^10 = 1024

void solve(int x, int y, int len) {
	if (len == 1) return;

	int half = len / 2;

	// 左上角子矩阵：全部赦免
	for (int i = x; i < x + half; i++) {
		for (int j = y; j < y + half; j++) {
			a[i][j] = 0;   //0表示赦免
		}
	}

	// 递归处理另外三个子矩阵
	solve(x, y + half, half);         // 右上
	solve(x + half, y, half);         // 左下
	solve(x + half, y + half, half);  // 右下
}

int main() {
	int n;
	cin >> n;

	int size = 1 << n;

	// 初始化为  1 默认不赦免
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] = 1;
		}
	}

	solve(0, 0, size);

	// 输出结果
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << a[i][j];
			if (j != size - 1) cout << " ";
		}
		cout << endl;
	}

//	system("pause");
	return 0;
}
