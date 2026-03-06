#include <iostream>
#include <vector>

using namespace std;

struct Box {
	int myNum;
	long long now;
	long long ate;
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long x;
	cin >> n >> x;

	vector<Box> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].now;   // 初始化
	}

	long long total_ate = 0;

	for (int i = 0; i < n - 1; i++) {   // 遍历每一对相邻的盒子
		if (arr[i].now + arr[i + 1].now > x) {
			// 计算这两个盒子超出了多少个糖果
			long long excess = arr[i].now + arr[i + 1].now - x;
			total_ate += excess; // 把超出的数量加入到总计中

			if (arr[i + 1].now >= excess) {
				// 如果右边盒子的糖果够吃，就全在右边吃
				arr[i + 1].now -= excess;
			}
			else {
		
				arr[i].now -= (excess - arr[i + 1].now);
				arr[i + 1].now = 0;
			}
		}
	}

	// 输出最终结果
	cout << total_ate << "\n";

//	system("pause");
	return 0;
}