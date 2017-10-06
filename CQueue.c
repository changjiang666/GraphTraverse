#include "CQueue.h"

void InitCQueue(CQueue *Q)
{
	Q->base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	if (!Q->base)
		return;
	Q->front = Q->rear = 0;
}

void InsertCQueue(CQueue *Q, ElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
}

void DeleteCQueue(CQueue *Q, ElemType *e)
{
	if (Q->rear == Q->front)
		return;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
}