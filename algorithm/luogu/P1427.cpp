#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> arr;
	int num;

	// 记录数值
	while (cin >> num) {
		if (num == 0) break;
		arr.push_back(num);
	}

	for (int i = (int)arr.size() - 1; i >= 0; --i) {
		if (i != (int)arr.size() - 1) cout << ' ';
		cout << arr[i];
	}

	system("pause");
	return 0;
}