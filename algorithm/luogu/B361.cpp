#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> arr;

	// 输入数组元素
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	// 计算前缀和
	for (int i = 1; i < arr.size(); i++) {
		arr[i] = arr[i - 1] + arr[i];   // 前缀和
	}

	int number;  // 区间数量
	cin >> number;

	// 处理每个区间
	for (int i = 0; i < number; i++) {
		int begin, end;
		cin >> begin >> end;

		cout << arr[end - 1] - (begin > 1 ? arr[begin - 2] : 0) << endl;
	}

//	system("pause");
	return 0;
}
