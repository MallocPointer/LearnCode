#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<int> warehouse;
	stack<int> maxSt;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int command;
		cin >> command;

		if (command == 0) {
			int x;
			cin >> x;
			warehouse.push(x);
			if (maxSt.empty()) maxSt.push(x);
			else maxSt.push(max(maxSt.top(), x));
		}
		else if (command == 1) {
			if (!warehouse.empty()) {
				warehouse.pop();
				maxSt.pop();
			}
		}
		else { // command == 2
			cout << (maxSt.empty() ? 0 : maxSt.top()) << endl;
		}
	}

//	system("pause");
	return 0;
}
