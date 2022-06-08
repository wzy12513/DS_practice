#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node_s {
	int val;
	struct node_s *next;
}Node;

Node* add_to_list(Node *list,int val);     //�÷���ֵʵ��ͷ��

void Add_to_list(Node** list, int val);    //�ö���ʵ��ͷ��

int main() {
	Node* list = NULL;

    list=add_to_list(list, 1);
	list=add_to_list(list, 2);
	list=add_to_list(list, 3);
	list=add_to_list(list, 4);
	list=add_to_list(list, 5);
	
	Add_to_list(&list, 6);
	Add_to_list(&list, 7);
	Add_to_list(&list, 8);
	Add_to_list(&list, 9);
	Add_to_list(&list, 10);

	return 0;
}

Node* add_to_list(Node* list, int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error : malloc failed in add_to_list.\n");
		exit(1);
	}

	newNode->val = val;    //ͷ�巨
	newNode->next = list;

	return newNode;
}

void Add_to_list(Node** list, int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error : malloc failed in add_to_list.\n");
		exit(1);
	}

	newNode->val = val;    //ͷ�巨
	newNode->next = *list;
	*list = newNode;
}