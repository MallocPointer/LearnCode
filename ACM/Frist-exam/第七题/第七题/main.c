//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num;    // 编号
	int state;  // 是否通过
} questionState;

int main() {
	int record, questionNum;
	scanf("%d %d", &record, &questionNum);

	questionState *array = (questionState*)malloc(sizeof(questionState) * (questionNum + 1));
	for (int i = 1; i <= questionNum; i++) {
		array[i].num = i;
		array[i].state = 0;  // 初始化为未通过
	}

	for (int i = 0; i < record; i++) {
		int pid, state;
		scanf("%d %d", &pid, &state);
		if (array[pid].state == 0 && state == 1) {
			array[pid].state = 1;  // 只有第一次通过才算
		}
	}

	int finallyPass = 0;
	for (int i = 1; i <= questionNum; i++) {
		if (array[i].state == 1) finallyPass++;
	}

	printf("%d\n", finallyPass);
	free(array);
//	system("pause");
	return 0;
}
