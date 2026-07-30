#include <iostream>
#include <string>
using namespace std;

int main() {
	//只算了26个字母 空格单独算
	int cnt[26] = {
		1,2,3, 1,2,3, 1,2,3,
		1,2,3, 1,2,3,
		1,2,3,4,
		1,2,3,
		1,2,3,4
	};

	string s;
	getline(cin, s);

	int ans = 0;
	for (char c : s) {
		if (c == ' ')   //单独算空格
			ans += 1;
		else
			ans += cnt[c - 'a'];
	}

	cout << ans;
//	system("pause");
	return 0;
}
