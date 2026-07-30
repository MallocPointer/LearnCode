#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> arr;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	vector<int> original;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			original.push_back(arr[0]);  // 0号索引前缀和就是自己
		}
		else {
			original.push_back(arr[i] - arr[i - 1]);
		}
		cout << original[i] << " ";
	}


//	system("pause");
	return 0;
}