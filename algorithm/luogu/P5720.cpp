#include <iostream>
using namespace std;

int main(void) {
	int a;
	cin >> a;
	int cnt = 1;
	while (a != 1) {
		a /= 2;
		cnt++;
	}
	cout << cnt << endl;
//	system("pause");
	return 0;
}