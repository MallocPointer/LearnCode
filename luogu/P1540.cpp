#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main() {
	int M, N;
	cin >> M >> N;

	queue<int> q;      // 表示内存
	set<int> mem;      // 当前在内存中的单词
	int ans = 0;       // 查词典次数

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		// 如果不在内存中 需要查词典
		if (mem.find(x) == mem.end()) {
			ans++;

			// 内存满了 移除最早进入的单词
			if ((int)q.size() == M) {
				int old = q.front();
				q.pop();
				mem.erase(old);
			}

			// 加入新单词
			q.push(x);
			mem.insert(x);
		}
		// 如果在内存中，什么也不做
	}

	cout << ans << endl;

//	system("pause");
	return 0;
}
