//https://www.luogu.com.cn/problem/P1303

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	vector<int> a, b;
	string s1, s2;
	cin >> s1 >> s2;

	// 倒序存储
	for (int i = s1.size() - 1; i >= 0; i--) {
		a.push_back(s1[i] - '0');
	}

	for (int i = s2.size() - 1; i >= 0; i--) {
		b.push_back(s2[i] - '0');
	}
	vector<int> res(a.size() + b.size(), 0);   //结果存贮

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			res[i + j] += a[i] * b[j];
		}
	}

	// 处理进位
	for (int i = 0; i < res.size(); i++) {
		if (res[i] >= 10) {
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
	}

	//去除前导0
	int pos = res.size() - 1;
	while (pos > 0 && res[pos] == 0)
		pos--;

	for (int i = pos; i >= 0; i--) {
		cout << res[i];
	}

	//	system("pause");
	return 0;
}