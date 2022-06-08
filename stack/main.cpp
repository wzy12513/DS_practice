#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main() {

	Node* top = NULL;

	push(&top, 1);
	push(&top, 2);
	push(&top, 3);
	push(&top, 4);
	push(&top, 5);

	int i = peek(top);

	pop(&top, 5);

	int j = peek(top);

	return 0;
}