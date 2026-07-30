#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n + 1);  // 1-based
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	while (m--) {
		int k;
		cin >> k;
		cout << a[k] << endl;
	}

	for (int i = 0; i < m; i++) {
		int now;
		cin >> now;
		cout << a[now] << endl;
	}

	//	system("pause");
	return 0;
}
