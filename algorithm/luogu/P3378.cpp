#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// 小根堆
	priority_queue<int, vector<int>, greater<int>> q;

	while (n--) {
		int op;
		cin >> op;

		if (op == 1) {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (op == 2) {
			// 题目保证此时序列非空
			cout << q.top() << endl;
		}
		else if (op == 3) {
			// 删除最小值
			q.pop();
		}
	}

//	system("pause");
	return 0;
}
