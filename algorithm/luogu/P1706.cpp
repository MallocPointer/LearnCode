// https://www.luogu.com.cn/problem/P1706

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int n;
vector<int> perm;
vector<int> used; // 标记某个数字是否已经用过

void fullPermutation(int now, int n) {
	if (now == n) {
		for (int i = 0; i < n; i++) {
			cout << setw(5) << perm[i];
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (used[i]) continue;   // 用过就跳过

		used[i] = 1;
		perm[now] = i;
		fullPermutation(now + 1, n);
		used[i] = 0;   // 回溯释放
	}
}

int main() {
	cin >> n;
	perm.assign(n, 0);
	used.assign(n + 1, 0);

	fullPermutation(0, n);

//	system("pause");
	return 0;
}
