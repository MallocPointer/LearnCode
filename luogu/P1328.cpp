#include <iostream>
using namespace std;

int main() {
	int n, na, nb;
	cin >> n >> na >> nb;

	int a[210], b[210];   // 设置 N 是 0 到 200
	for (int i = 0; i < na; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < nb; j++) {
		cin >> b[j];
	}

	// 1 表示行手势赢列手势，0 表示不赢
	int win[5][5] = {
		{ 0, 0, 1, 1, 0 }, 
		{ 1, 0, 0, 1, 0 }, 
		{ 0, 1, 0, 0, 1 }, 
		{ 0, 0, 1, 0, 1 }, 
		{ 1, 1, 0, 0, 0 }
	};

	int scoreA = 0, scoreB = 0;

	for (int i = 0; i < n; i++) {
		int handA = a[i % na];
		int handB = b[i % nb];

		// A 赢的一种情况
		if (win[handA][handB] == 1) scoreA++;
		// B 赢的一种情况
		if (win[handB][handA] == 1) scoreB++;
	}

	cout << scoreA << " " << scoreB << endl;

	system("pause");
	return 0;
}
