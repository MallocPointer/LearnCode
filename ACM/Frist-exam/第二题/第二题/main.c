//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int fir[4];
	int sec[4];

	//获取队伍分数
	for (int i = 0; i < 4; i++) {
		scanf("%d", &fir[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &sec[i]);
	}

	int num = 0;   //题目需要的组数初始化为0

	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 4; j++) {
			if (fir[i] < fir[j] && sec[i] > sec[j]) {
				num++;
			}

			if (fir[i] > fir[j] && sec[i] < sec[j]) {
				num++;
			}
		}
	}

	printf("%d", num);
//	system("pause");
	return 0;
}