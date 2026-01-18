#include <iostream>
#include <string>
using namespace std;

string comp(int num) {
	if (num < 10) return "0" + to_string(num);
	return to_string(num);
}

int main(void) {
	int n;
	cin >> n;

	int k = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			cout <<comp(k);
			k++;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}