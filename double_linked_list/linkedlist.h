#include<stdio.h>
#include<stdlib.h>

typedef struct node_s {
	int val;
	struct node_s* prev;
	struct node_s* next;
}Node;

typedef struct LinkedList_s {
	Node* head;
	Node* rear;
    int size;
}LinkedList;

LinkedList* create_list();

void destroy_list(LinkedList* list);//ɾ������

void add_before_head(LinkedList* list, int val);//ͷ�巨

void add_behind_rear(LinkedList* list, int val);//β�巨

void add_node(LinkedList* list, int index, int val);//���ض�λ�ò���

void delete_node(LinkedList* list, int val);//ɾ�����

int search_val(LinkedList* list, int index);//�����������ҽ��ֵ

int search_node(LinkedList* list, int val);//���Ҷ�Ӧֵ�Ľ�������