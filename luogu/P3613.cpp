#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void) {
	int n, q;
	cin >> n >> q;
	
	map<int, map<int, int>> arr;   // 数据依次为存包柜序号 每个格子的序号 存放的数据

	for (int a = 0; a < q; a++) {
		int flag;
		cin >> flag;
		
		if (flag == 1) {
			int i, j, k;
			cin >> i >> j >> k;
			arr[i][j] = k;
		}
		else if (flag == 2) {
			int i, j;
			cin >> i >> j;
			cout << arr[i][j] << endl;
		}
	}


	system("pause");
	return 0;
}