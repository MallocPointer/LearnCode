// https://www.luogu.com.cn/problem/P1090

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;
using llong = long long;

int main(void) {
	priority_queue<llong, vector<llong>, greater<llong>> qp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		llong num;
		cin >> num;
		qp.push(num);
	}

	llong ans = 0;
	while(qp.size() != 1) {
		llong a = qp.top(); qp.pop();
		llong b = qp.top(); qp.pop();
		llong s = a + b;
		ans += s;
		qp.push(s);   // 合成堆回填
	}

	cout << ans << endl;
//	system("pause");
	return 0;
}