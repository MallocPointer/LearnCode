//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);

		int fail = 0;
		for (int j = 0; j < num; j++) {
			int x;
			scanf("%d", &x);
			if (x == 0) {
				fail++;
			}
		}


		double rate = (double)fail / num * 100;


		printf("%02d\n", (int)rate);
	}

	return 0;
}
