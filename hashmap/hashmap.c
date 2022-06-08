#include<stdio.h>
#include<stdlib.h>
#include"hashmap.h"

V hash(K key) {
	V h = 0, g;
	while (*key) {
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g) {
			h ^= g >> 24;
		}
		h &= ~g;
	}
	return h % N;
}

HashMap* HashMap_create() {
	return (HashMap*)calloc(1, sizeof(HashMap));
}

void HashMap_destroy(HashMap* map) {
	for (int i = 0; i < N; i++) {
		Entry* curr = map->table[i];

		while (curr != NULL) {
			Entry* next = curr->next;
			free(curr);
			curr=next;
		}
	}

	free(map);
}

V HashMap_get(HashMap* map, K key) {
	int index = hash(key);
	
	Entry* curr = map->table[index];
	while (curr != NULL) {
		if (curr->key == key) {
			return curr->val;
		}
		curr = curr->next;
	}

	return -1;
}

V HashMap_put(HashMap* map, K key, V val) {
	int index = hash(key);

	Entry* curr = map->table[index];
	while (curr != NULL) {
		if (curr->key == key) {
			V oldVal = curr->val;
			curr->val = val;
			return oldVal;
		}
		curr = curr->next;
	}

	Entry* entry = (Entry*)malloc(sizeof(entry));
	if (entry == NULL) {
		printf("malloc failed in HashMap_put.\n");
		exit(1);
	}
	
	entry->key = key;
	entry->val = val;

	entry->next = map->table[index];
	map->table[index] = entry;

	return -1;
}

V HashMap_remove(HashMap* map, K key) {
	int index = hash(key);

	Entry* prev = NULL;
	Entry* curr = map->table[index];
	while (curr != NULL) {
		if (curr->key == key) {
			if (prev == NULL) {
				map->table[index] = curr->next;
			}
			else {
				prev->next = curr->next;
			}
			V removeVal = curr->val;
			free(curr);
			return removeVal;
		}
		prev = curr;
		curr = curr->next;
	}

	return -1;
}