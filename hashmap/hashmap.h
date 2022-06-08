#include<stdio.h>
#include<stdlib.h>

#define N 10  //�����С

typedef char* K;//�ַ�ָ�뵱key

typedef int V;  //int�͵�ֵ

//�����������ͻ

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

V hash(K key);//��ϣ����

V HashMap_get(HashMap* map, K key);

V HashMap_put(HashMap* map, K key, V val);

V HashMap_remove(HashMap* map, K key);