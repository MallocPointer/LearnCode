//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int A(int m, int n) {
	if (m == 0) {
		return n + 1;
	}
	else {
		if (n == 0) {
			return A(m - 1, 1);
		}
		else {
			return A(m - 1, A(m, n - 1));
		}
	}
}

int main(void) {
	int m, n;
	scanf("%d%d", &m, &n);

	int res = A(m, n);
	printf("%d", res);
//	system("pause");
	return 0;
}