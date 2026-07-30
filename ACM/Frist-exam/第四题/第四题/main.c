//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 检查 s 从索引 i 开始，是否匹配 illegal 的索引 j
int match(char *s, char *illegal, int i, int j) {
	if (illegal[j] == '\0') return 1; // 匹配完成
	if (s[i] == '\0') return 0;       // 字符串结束仍未匹配完
	if (s[i] == illegal[j])
		return match(s, illegal, i + 1, j + 1);
	else
		return 0;
}

// 检查 s 中是否包含 illegal
int contains(char *s, char *illegal, int start) {
	if (s[start] == '\0') return 0; // 遍历完所有起点
	if (match(s, illegal, start, 0)) return 1; // 当前起点匹配成功
	return contains(s, illegal, start + 1);    // 尝试下一个起点
}

int main(void) {
	int n;
	scanf("%d", &n);

	char illegal[102];
	scanf("%s", illegal);

	for (int i = 0; i < n; i++) {
		char name[102];
		scanf("%s", name);

		if (contains(name, illegal, 0)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

//	system("pause");
	return 0;
}
