#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


int main(void) {
	int n;
	cin >> n;

	vector<int> mark;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		mark.push_back(num);
		
	}
	sort(mark.begin(), mark.end());

	int sum = 0;
	for (int i = 1; i < n - 1; i++) {   // 去掉最小和最大
		sum += mark[i];
	}

	double res = sum * 1.0 / (mark.size() - 2);
	cout << fixed << setprecision(2) << res << endl;

//	system("pause");
	return 0;
}