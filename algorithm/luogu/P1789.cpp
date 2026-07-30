#include <iostream>
#include <cmath>
using namespace std;

class Torch {
private:
	int x, y;   // 火把坐标 0开始
public:
	Torch(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void light(bool **land, int n) {
		for (int dx = -2; dx <= 2; dx++) {
			for (int dy = -2; dy <= 2; dy++) {
				if (abs(dx) + abs(dy) <= 2) {
					int nx = x + dx;
					int ny = y + dy;
					if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
						land[nx][ny] = true;
					}
				}
			}
		}
	}
};

class Glowstone {
private:
	int x, y;   // 萤石坐标 0开始
public:
	Glowstone(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void light(bool **land, int n) {
		for (int dx = -2; dx <= 2; dx++) {
			for (int dy = -2; dy <= 2; dy++) {
				int nx = x + dx;
				int ny = y + dy;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					land[nx][ny] = true;
				}
			}
		}
	}
};

int main(void) {
	int n, m, k;
	cin >> n >> m >> k;

	bool **land = new bool*[n];
	for (int i = 0; i < n; i++) {
		land[i] = new bool[n];
		for (int j = 0; j < n; j++) land[i][j] = false;   //地图初始化
	}

	// 读入 m 个火把
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;   //换算为地图
		Torch t(x, y);
		t.light(land, n);
	}

	// 读入 k 个萤石
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		Glowstone g(x, y);
		g.light(land, n);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!land[i][j]) ans++;
		}
	}
	cout << ans << endl;

	for (int i = 0; i < n; i++) delete[] land[i];
	delete[] land;

//	 system("pause");
	return 0;
}
