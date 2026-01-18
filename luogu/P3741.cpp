#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countVK(const string &s) {
	int cnt = 0;
	for (int i = 0; i + 1 < (int)s.size(); i++) {
		if (s[i] == 'V' && s[i + 1] == 'K') {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	int n;
	string s;
	cin >> n >> s;

	int ans = countVK(s); // 不修改

	for (int i = 0; i < n; i++) {
		string t = s;
		// 尝试修改一个字符
		if (t[i] == 'V') t[i] = 'K';
		else t[i] = 'V';

		ans = max(ans, countVK(t));
	}

	cout << ans << endl;

	system("pause");
	return 0;
}
