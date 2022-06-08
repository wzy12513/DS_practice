#include<stdio.h>
#include<stdlib.h>

#define N 10    //������еĳ���

typedef int E;  //������е���������

typedef struct queue_s {
	E elements[N];
	int front;
	int rear;
}Queue;               //���ʵ�ֵ���ѭ������

Queue* Queue_create();//��ʼ������

void Queue_destroy(Queue* queue);//��ն���

void enqueue(Queue* queue,E val);//���

E dequeue(Queue* queue);//����

E peek(Queue* queue);//�鿴����Ԫ��

bool isEmpty(Queue* queue);//�����п�

bool isFull(Queue* queue);//��������