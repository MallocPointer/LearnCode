#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;
using llong = long long;

struct Stu {
	int num;
	int time;
};

bool comp(const Stu &s1, const Stu &s2) {
	if (s1.time < s2.time)
		return true;
	return false;
}

int main(void) {
	int n;
	cin >> n;
	vector<Stu> time(n);
	for (int i = 0; i < n; i++) {
		time[i].num = i + 1;
		cin >> time[i].time;   //初始化时间
	}

	sort(time.begin(), time.end(), comp);

	for (int i = 0; i < n; i++) {
		cout << time[i].num << (i == n - 1 ? "" : " ");
	}
	cout << endl;

	llong wait = 0;
	for (int i = 0; i < n; i++) wait += (llong)time[i].time * (n - 1 - i);
	cout << fixed << setprecision(2) << (double)wait / n << endl;

//	system("pause");
	return 0;
}