#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	double maxScore = 0.0;   //最大值初始化为最低

	for (int i = 0; i < n; i++) {
		vector<int> scores(m);
		int sum = 0;
		int mx = 0, mn = 10;

		for (int j = 0; j < m; j++) {
			cin >> scores[j];
			sum += scores[j];
			mx = max(mx, scores[j]);
			mn = min(mn, scores[j]);
		}

		double avg = (sum - mx - mn) * 1.0 / (m - 2);
		maxScore = max(maxScore, avg);
	}

	cout << fixed << setprecision(2) << maxScore << endl;

//	system("pause");
	return 0;
}
