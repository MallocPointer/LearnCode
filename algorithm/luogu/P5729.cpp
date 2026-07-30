#include <iostream>
using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;

	int q;
	cin >> q;

	bool evap[21][21][21] = {};   // 局部数组，显式初始化为false

	for (int t = 0; t < q; t++) {
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				for (int k = z1; k <= z2; k++) {
					evap[i][j][k] = true;
				}
			}
		}
	}

	int evaporated = 0;
	for (int i = 1; i <= a; ++i) {
		for (int j = 1; j <= b; ++j) {
			for (int k = 1; k <= c; ++k) {
				if (evap[i][j][k]) {
					evaporated++;
				}
			}
		}
	}

	int total = a * b * c;
	cout << total - evaporated << endl;

//	system("pause");
	return 0;
}
