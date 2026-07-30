//https://leetcode.cn/problems/two-sum/description/?envType=problem-list-v2&envId=hash-table
//哈希表练习

#include <stdio.h>
#include <stdlib.h>


/**
* Note: The returned array must be malloced, assume caller calls free().
*/

typedef struct Hash {
	int data;
	int index;
	struct Hash *next;
}Hash;

typedef struct HashTable {
	int size;
	Hash **table;
}HashTable;

//构建哈希表
HashTable* creatHashTable(int size) {
	HashTable *ht = (HashTable*)malloc(sizeof(HashTable));
	ht->table = (Hash**)malloc(sizeof(Hash*) * size);
	ht->size = size;

	//全部初始化
	for (int i = 0; i < size; i++) {
		ht->table[i] = NULL;
	}
	return ht;
}

void input(int key, Hash *node) {
	node->data = key;
}

//哈希函数
int hash(int key, int size) {
	if (key < 0) {
		key = -key;
	}
	return key % size;
}

//插入节点
void insert(int data, int index, HashTable *ht) {
	int hashIndex = hash(data, ht->size);
	Hash *newNode = (Hash*)malloc(sizeof(Hash));
	newNode->data = data;
	newNode->index = index;

	newNode->next = ht->table[hashIndex];
	ht->table[hashIndex] = newNode;
}

//查找是否存在数值
Hash* search(int key, HashTable *ht) {
	int index = hash(key, ht->size);
	Hash *current = ht->table[index];

	while (current != NULL) {
		if (current->data == key) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

	//散列长度常用规格
	int tableSize = numsSize * 2 + 1;

	HashTable *ht= creatHashTable(tableSize);

	for (int i = 0; i < numsSize; i++) {
		int need = target - nums[i];
		//		int index = hash(need, tableSize);
		Hash *found = search(need, ht);
		if (found != NULL) {
			int *res = (int*)malloc(sizeof(int) * 2);
			res[0] = found->index;
			res[1] = i;
			*returnSize = 2;
			return res;
		}
		insert(nums[i], i, ht);

	}
	*returnSize = 0;   // 表示没有找到结果
	return NULL;
}

int main(void) {
	return 0;
}