#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x) {
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * 1LL * i <= x; i += 2) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	int a, b;
	cin >> a >> b;

	// 特判小的
	if (a <= 5 && 5 <= b) cout << 5 << '\n';
	if (a <= 7 && 7 <= b) cout << 7 << '\n';
	if (a <= 11 && 11 <= b) cout << 11 << '\n';

	// 3 位回文
	for (int d1 = 1; d1 <= 9; d1 += 2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			int x = d1 * 100 + d2 * 10 + d1;
			if (x >= a && x <= b && isPrime(x))
				cout << x << '\n';
		}
	}

	// 5 位回文
	for (int d1 = 1; d1 <= 9; d1 += 2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				int x = d1 * 10000 + d2 * 1000 + d3 * 100
					+ d2 * 10 + d1;
				if (x >= a && x <= b && isPrime(x))
					cout << x << '\n';
			}
		}
	}

	// 7 位回文
	for (int d1 = 1; d1 <= 9; d1 += 2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				for (int d4 = 0; d4 <= 9; d4++) {
					int x = d1 * 1000000 + d2 * 100000 + d3 * 10000
						+ d4 * 1000 + d3 * 100 + d2 * 10 + d1;
					if (x >= a && x <= b && isPrime(x))
						cout << x << '\n';
				}
			}
		}
	}


	return 0;
}
