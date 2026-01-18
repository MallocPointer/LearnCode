#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define Xmax 100
#define Ymax 100


int main(void) {
	//先定义八个方向 坐标表示
	int dx[8] = { -1,-1,-1,0,0,1,1,1 };
	int dy[8] = { -1,0,1,-1,1,-1,0,1 };

	int X, Y;
	cin >> X >> Y;
	vector<char> boom;   //定义雷阵，后期使用偏移动态扫描

	//记录雷阵数据
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			char now;
			cin >> now;
			boom.push_back(now);
		}
	}

	//   *是地雷   ?不是地雷
	//开始扫描每一个格子
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {

			int pos = i * Y + j;   //二维转换一维下标

			if (boom[pos] == '*') {   //是雷还是雷不用动
				cout << '*';
			}
			else {
				int cnt = 0;

				//扫描 8 个方向 0到8已经做好了坐标表示
				for (int k = 0; k < 8; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					//判断是否越界
					if (nx >= 0 && nx < X && ny >= 0 && ny < Y) {
						int npos = nx * Y + ny;   //表示邻接位置的一维地址
						if (boom[npos] == '*') {
							cnt++;
						}
					}
				}

				cout << cnt;
			}
		}
		cout << endl;
	}



//	system("pause");
	return 0;
}