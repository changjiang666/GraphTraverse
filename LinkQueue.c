#include "LinkQueue.h"
#include <stdio.h>
#include <stdlib.h>

void InitQueue(LinkQueue *Q)
{
	QueuePtr head = (QueuePtr)malloc(sizeof(QNode));
	if (!head)
		return;
	head->next = NULL;
	Q->front = Q->rear = head;

}


void InsertQueue(LinkQueue *Q, ElemType e)
{
	QueuePtr q = (QueuePtr)malloc(sizeof(QNode));
	if (!q)
		return;
	q->data = e;
	q->next = NULL;
	Q->rear->next = q;
	Q->rear = q;
}

void DeleteQueue(LinkQueue *Q, ElemType *e)
{
	if (Q->front == Q->rear)
		return;
	QueuePtr q = Q->front->next;
	Q->front->next = q->next;
	*e = q->data;
	if (q == Q->rear)
		Q->rear = Q->front;
	free(q);
}