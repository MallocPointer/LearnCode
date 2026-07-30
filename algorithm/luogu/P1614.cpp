#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int tem;
		cin >> tem;
		arr.push_back(tem);
	}

	//特殊情况 m == 0
	if (m == 0) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> fin;

	for (int i = 0; i <= n - m; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += arr[i + j];
		}
		fin.push_back(sum);
	}

	// 输出最小值
	cout << *min_element(fin.begin(), fin.end()) << endl;

//	system("pause");
	return 0;
}
