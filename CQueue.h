#pragma once 
#define MAXSIZE 100

typedef int ElemType;
typedef struct
{
	ElemType *base;
	int front, rear;	
}CQueue;

void InitCQueue(CQueue *Q);
void InsertCQueue(CQueue *Q, ElemType e);
void DeleteCQueue(CQueue *Q, ElemType *e);