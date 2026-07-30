#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(void) {
	map<string, int> st;   // 存放城市以及州代码
	vector<pair<string, string>> comp;   // 存储输入的城市及州
	int n;
	cin >> n;

	// 输入处理
	for (int i = 0; i < n; i++) {
		string city, state;
		cin >> city >> state;
		comp.push_back(make_pair(city, state));   // 存储城市和州
	}

	int cnt = 0;   // 记录特殊配对数量

	for (int i = 0; i < n; i++) {
		string city = comp[i].first;
		string state = comp[i].second;
		string prefix = city.substr(0, 2);  // 城市名前两个字母 用于后期比较

		// 排除来自同一州的情况
		if (prefix != state) {
			// 查找是否存在配对
			cnt += st[state + prefix];

			// 记录当前的正向配对字符串
			st[prefix + state]++;
		}
	}

	cout << cnt << endl;  // 输出结果

//	system("pause");
	return 0;
}
