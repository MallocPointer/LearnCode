#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int m, n;
	cin >> m >> n;
	vector<int> arr(n);
	bool flag = false;   // 用于判定是否无符合题目要求的样例
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		if (arr[i] % m == 0) continue;   // 是倍数直接跳过
//		vector<int> every;
		int temp = arr[i];
		int sum = 0;   // 初始化为0
		while (temp) {
			int now = temp % 10;
			temp /= 10;
			sum += now;
		}
		if (sum % m == 0) {
			flag = true;
			cout << arr[i] << endl;
		}
	}

	if (!flag) cout << "None" << endl;
//	system("pause");
	return 0;
}