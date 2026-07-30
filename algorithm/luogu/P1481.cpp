#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//判断a是不是b的前缀
bool isPrefix(const string &a, const string &b) {   // 设定b是原有的前缀串
	if (a.size() > b.size()) return false;
	return b.compare(0, a.size(), a) == 0;   // 如果比对成功返回的是0 所以和0比较
}

int main(void) {
	int n;
	cin >> n;

	vector<string> word;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		word.push_back(str);
	}
	
	int ans = 1;
	vector<int> dp(n, 1);   // 建立vector大小为n 且初始化为1
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (isPrefix(word[j], word[i])) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;

//	system("pause");
	return 0;
}