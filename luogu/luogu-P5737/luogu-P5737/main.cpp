//https://www.luogu.com.cn/problem/P5737
//P5737 »ÚƒÍ’π æ

#include <iostream>
#include <vector>
using namespace std;

bool check(int num) {
	if ((num % 4 == 0 && num % 100 != 0) || num % 400 == 0)
		return true;
	return false;
}

int main(void) {
	int m, n;
	cin >> m >> n;
	vector<int> year;
	for (int i = m; i <= n; i++) {
		if (check(i))
			year.push_back(i);
	}

	cout << year.size() << endl;
	for (int i : year) {
		cout << i << " ";
	}

//	system("pause");
	return 0;
}