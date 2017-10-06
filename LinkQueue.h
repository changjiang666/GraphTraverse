#pragma once 

typedef int ElemType;
typedef struct QNode
{ 
	ElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front, rear;
}LinkQueue;

void InitQueue(LinkQueue *Q);
void InsertQueue(LinkQueue *Q, ElemType e);
void DeleteQueue(LinkQueue *Q, ElemType *e);