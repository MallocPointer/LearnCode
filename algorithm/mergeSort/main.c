#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge(int *arr,int *temp, int left, int mid, int right) {
	int Lstart = left;
	int Rstart = mid + 1;
	int k = left;   //临时数组写入位置

	while (Lstart <= mid && Rstart <= right) {
		if (arr[Lstart] <= arr[Rstart]) temp[k++] = arr[Lstart++];
		else temp[k++] = arr[Rstart++];
	}

	//如果左区间还有数
	while (Lstart <= mid) {
		temp[k++] = arr[Lstart++];
	}

	//如果右区间还有数
	while (Rstart <= right) {
		temp[k++] = arr[Rstart++];
	}

	//把temp拷贝到原数组
	for (int i = left; i <=  right; i++) {
		arr[i] = temp[i];
	}
}

void mergeSort(int *arr, int *temp, int left, int right) {
	if (left >= right) return;
	int mid = (left + right) / 2;

	mergeSort(arr, temp, left, mid);
	mergeSort(arr, temp, mid + 1, right);
	merge(arr, temp, left, mid, right);   // 合并
}

int main(void) {
	int n;
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int) * n);
	int *temp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = temp[i] = 0;   //全部初始化
		scanf("%d", &arr[i]);
	}

	mergeSort(arr, temp, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	getchar();
	getchar();
}