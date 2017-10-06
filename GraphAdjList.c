#include "GraphAdjList.h"
#include "LinkQueue.h"
#include <stdio.h>
#include <stdlib.h>

void CreateGraphAdjList(GraphAdjList *G)
{
	int i, j, k;
	EageNode *e;
	printf("输入顶点数和边数：");
	scanf_s("%d,%d", &G->vexNum, &G->eageNum);
	getchar();


	printf("输入顶点信息:");
	for (i = 0; i < G->vexNum; ++i)
	{
		scanf_s("%c", &G->adjList[i].data);
		G->adjList[i].firsteage = NULL;
	}
	getchar();


	for (k = 0; k < G->eageNum; ++k)
	{
		printf("输入边（Vi,Vj）的顶点序列：");
		scanf_s("%d,%d", &i, &j);
		e = (EageNode *)malloc(sizeof(EageNode));
		e->adjvex = j;
		e->next = G->adjList[i].firsteage;
		G->adjList[i].firsteage = e;

		e = (EageNode *)malloc(sizeof(EageNode));
		e->adjvex = i;
		e->next = G->adjList[j].firsteage;
		G->adjList[j].firsteage = e;
	}
}

void DFS_(GraphAdjList *G, int i)
{
	int j;
	EageNode *e;
	visit[i] = TRUE;
	printf("%c", G->adjList[i].data);


	e = G->adjList[i].firsteage;
	while (e)
	{
		j = e->adjvex;
		if (!visit[j])
			DFS_(G, j);
		e = e->next;	
	}
}

void DFS_Search(GraphAdjList *G)
{
	int i;
	for (i = 0; i < G->vexNum; ++i)
		visit[i] = FALSE;

	for (i = 0; i < G->vexNum; ++i)
		if (!visit[i])
			DFS_(G, i);
}

void BFSTraverse(GraphAdjList *G)
{
	LinkQueue Q;
	InitQueue(&Q);

	EageNode *e;
	int i;
	for (i = 0; i < G->vexNum; ++i)
		visit[i] = FALSE;

	for (i = 0; i < G->vexNum; ++i)
	{
		if (!visit[i])
		{
			printf("%c", G->adjList[i].data);
			visit[i] = TRUE;
			InsertQueue(&Q, i);

			while (Q.rear != Q.front)
			{
				DeleteQueue(&Q, &i);
				e = G->adjList[i].firsteage;

				while (e)
				{
					if (!visit[e->adjvex])
					{
						visit[e->adjvex] = TRUE;
						printf("%c", G->adjList[e->adjvex].data);
						InsertQueue(&Q, e->adjvex);
					}
					e = e->next;
				}
			}
		}
	}
}