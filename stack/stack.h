#include<stdio.h>
#include<stdlib.h>

typedef struct node_s {
	int val;
	struct node_s* next;
}Node;

void push(Node** top, int val);//��ջ

int pop(Node** top, int val);//��ջ

int peek(const Node* top);//�鿴ջ��Ԫ��

bool isEmpty(const Node* top);//ջ�п�