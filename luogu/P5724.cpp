#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> num;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		num.push_back(data);
	}

	sort(num.begin(), num.end());

	cout << num[n - 1] - num[0] << endl;
	
//	system("pause");
	return 0;
}