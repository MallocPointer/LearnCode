//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	long long ans = 0;   //总罚时
	int cnt0 = 0;   //未通过提交次数

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (b == 0) {
			cnt0++;
		}
		else {
			ans += a + 20 * cnt0;
			cnt0 = 0;
		}
	}

	printf("%lld\n", ans);
//	system("pause");
	return 0;
}
