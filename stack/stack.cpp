#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void push(Node** top, int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in push.\n");
		exit(1);
	}

	newNode->val = val;
	newNode->next = *top;

	*top = newNode;
}

int pop(Node** top, int val) {
	if (isEmpty(*top)) {
		printf("Error: stack is empty.\n");
		exit(1);
	}
	Node* oldTop = *top;
	int popVal = oldTop->val;
	*top = (*top)->next;
	free(oldTop);
	return popVal;
}

int peek(const Node* top) {
	if (isEmpty(top)) {
		printf("Error: stack is empty.\n");
		exit(1);
	}

	return top->val;
}

bool isEmpty(const Node* top) {
	return top == NULL;
}