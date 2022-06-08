#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

LinkedList* create_list() {
	return (LinkedList*)calloc(1,sizeof(LinkedList));
}

void destroy_list(LinkedList* list) {
	Node* curr = list->head;
	while (curr != NULL) {
		Node* next = curr->next;
		free(curr);
		curr = next;
	}

	free(list);
}

void add_before_head(LinkedList* list, int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in add_before_head.\n");
		exit(1);
	}
	//初始化结点
	newNode->val = val;
	newNode->prev = NULL;
	newNode->next = list->head;
	if (list->head != NULL) {
		list->head->prev = newNode;
	}
	//修改list的属性
	list->head = newNode;
	if (list->rear == NULL) {
		list->rear = newNode;
	}
	list->size++;
}

void add_behind_rear(LinkedList* list, int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in add_before_head.\n");
		exit(1);
	}

	newNode->val = val;
	newNode->next = NULL;
	newNode->prev = list->rear;
	
	if (list->rear != NULL) {
		list->rear->next = newNode;
	}

	list->rear = newNode;

	if (list->head == NULL) {
		list->head = newNode;
	}

	list->size++;
}

void add_node(LinkedList* list, int index, int val) {
	if (index<0 || index > list->size) {
		printf("Error:index must in[0,%d]\n", list->size);
		return;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in add_before_head.\n");
		exit(1);
	}
	newNode->val = val;

	if (index == list->size) {
		newNode->next = NULL;
		newNode->prev = list->rear;

		if (list->rear != NULL) {
			list->rear->next = newNode;
		}
		
		list->rear = newNode;

		if (list->head == NULL) {
			list->head = newNode;
		}
	}
	else {
		Node* curr = list->head;
		for (int i = 0; i < index; i++) {
			curr = curr->next;
		}

		newNode->prev = curr->prev;
		newNode->next = curr;

		if (curr->prev != NULL) {
			curr->prev->next = newNode;
		}
		curr->prev = newNode;

		if (index == 0) {
			list->head = newNode;
		}
	}
	list->size++;
}

void delete_node(LinkedList* list, int val) {
	Node* curr = list->head;

	while (curr != NULL) {   //往下遍历
		if (curr->val == val) {
			break;
		}
		curr = curr->next;
	}

	if (curr == NULL) return;

	if (curr->prev == NULL) {
		list->head = curr->next;
	}
	else {
		curr->prev->next = curr->next;
		if (curr->next == NULL) {
			list->rear=curr->prev;
		}
		else {
			curr->next->prev = curr->prev;
		}
	}

	free(curr);

	list->size--;
}

int search_val(LinkedList* list, int index) {
	if (index < 0 || index >= list->size) {
		printf("Erroe : invalid argument.\n");
		exit(1);
	}

	Node* curr = list->head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}

	return curr->val;
}

int search_node(LinkedList* list, int val) {
	int index = 0;
	Node* curr = list->head;

	while (curr != NULL && curr->val != val) {
		index++;
		curr = curr->next;
	}

	if (curr == NULL) return -1;
	return index;
}