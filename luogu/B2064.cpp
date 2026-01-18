#include <iostream>
using namespace std;

//斐波那契
int fib(int a) {
	if (a == 1 || a == 2) return 1;
	int f1 = 1, f2 = 1, f3;
	for (int i = 3; i <= a; i++) {
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f2;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		cout << fib(a) << endl;
	}

//	system("pause");
	return 0;
}
