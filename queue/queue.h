#include<stdio.h>
#include<stdlib.h>

#define N 10    //定义队列的长度

typedef int E;  //定义队列的数据类型

typedef struct queue_s {
	E elements[N];
	int front;
	int rear;
}Queue;               //这边实现的是循环链队

Queue* Queue_create();//初始化队列

void Queue_destroy(Queue* queue);//清空队列

void enqueue(Queue* queue,E val);//入队

E dequeue(Queue* queue);//出队

E peek(Queue* queue);//查看队首元素

bool isEmpty(Queue* queue);//队列判空

bool isFull(Queue* queue);//队列判满