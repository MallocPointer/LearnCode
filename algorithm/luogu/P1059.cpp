//https://www.luogu.com.cn/training/946266#problems

#include <iostream>
#include <set>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	set<int> arr;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.insert(num);
	}

	cout << arr.size() << endl;

	for (auto it = arr.begin(); it != arr.end(); ++it) {
		cout << *it << " ";
	}

//	system("pause");
	return 0;
}