#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using llong = long long;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<llong> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	unordered_set<llong> special;
	special.reserve(m * 2);   // 防过多碰撞
	for (int i = 0; i < m; i++) {
		llong now;
		cin >> now;
		special.insert(now);
	}

	int flag = true;
	for (int i = 0; i < n; i++) {
		if (special.find(arr[i]) != special.end()) {
			cout << arr[i] << " ";
		}
	}

//	system("pause");
	return 0;
}