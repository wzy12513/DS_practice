#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int main() {
	Queue* q = Queue_create();

	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	enqueue(q, 6);

	int i=dequeue(q);

	return 0;
}