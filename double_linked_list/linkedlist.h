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

void destroy_list(LinkedList* list);//删除链表

void add_before_head(LinkedList* list, int val);//头插法

void add_behind_rear(LinkedList* list, int val);//尾插法

void add_node(LinkedList* list, int index, int val);//在特定位置插入

void delete_node(LinkedList* list, int val);//删除结点

int search_val(LinkedList* list, int index);//根据索引查找结点值

int search_node(LinkedList* list, int val);//查找对应值的结点的索引