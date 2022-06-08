#include<stdio.h>
#include<stdlib.h>

typedef struct node_s {
	int val;
	struct node_s* next;
}Node;

void push(Node** top, int val);//入栈

int pop(Node** top, int val);//出栈

int peek(const Node* top);//查看栈顶元素

bool isEmpty(const Node* top);//栈判空