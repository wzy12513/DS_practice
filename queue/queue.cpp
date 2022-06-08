#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

Queue* Queue_create() {
	return (Queue*)calloc(1, sizeof(Queue));
}

void Queue_destroy(Queue* queue) {
	free(queue);
}

void enqueue(Queue* queue, E val) {
	if (isFull(queue)) {
		printf("Queue is full.\n");
		exit(1);
	}

	queue->elements[queue->rear] = val;
	queue->rear = (queue->rear + 1) % N;
}

E dequeue(Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is empty.\n");
		exit(1);
	}

	E retVal = queue->elements[queue->front];
	queue->front = (queue->front + 1) % N;
	return retVal;
}

E peek(Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is empty.\n");
		exit(1);
	}

	return queue->elements[queue->front];
}

bool isEmpty(Queue* queue) {
	return queue->front == queue->rear;
}

bool isFull(Queue* queue) {
	return (queue->rear + 1) % N == queue->front;
}