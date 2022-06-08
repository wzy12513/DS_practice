#include<stdio.h>
#include<stdlib.h>

#define N 10  //数组大小

typedef char* K;//字符指针当key

typedef int V;  //int型当值

//拉链法解决冲突

typedef struct entry_s { 
	K key;
	V val;
	struct entry_s* next;
}Entry;

typedef struct hashmap_s {
	Entry* table[N];
}HashMap;

HashMap* HashMap_create();

void HashMap_destroy(HashMap* map);

V hash(K key);//哈希函数

V HashMap_get(HashMap* map, K key);

V HashMap_put(HashMap* map, K key, V val);

V HashMap_remove(HashMap* map, K key);