#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	int yes = 0;
	int no = 0;
	int cnt = 0;   //专记录yes

	for (int i = 1; i <= n; i++) {
		if (i % k == 0) {
			yes += i;
			cnt++;
		}
		else no += i;
	}

	cout << fixed << setprecision(1)
		<< (double)yes / cnt << " "
		<< (double)no / (n - cnt) << endl;

	system("pause");
	return 0;
}