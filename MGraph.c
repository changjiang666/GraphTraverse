#include "MGraph.h"
#include "LinkQueue.h"
#include <stdio.h>

void CreateMGraph(MGraph *G)
{
	int i, j, k, weight;
	printf("please input the number of vertex and eage:");
	scanf_s("%d,%d", &G->vexNum, &G->arcNum);
	getchar();

	printf("please input the vertex data:");
	for (i = 0; i < G->vexNum; ++i)
	{
		scanf_s("%c", &G->vexs[i]);
	}
	getchar();

	for (i = 0; i < G->vexNum; ++i)
		for (j = 0; j < G->vexNum; ++j)
			G->arc[i][j] = INF;

	for (k = 0; k < G->arcNum; ++k)
	{
		printf("please input the eage:");
		scanf_s("%d,%d,%d", &i, &j, &weight);
		G->arc[i][j] = G->arc[j][i] = weight;
	}
}

void DFS(MGraph *G, int i)
{
	int j;
	printf("%c", G->vexs[i]);
	visited[i] = TRUE;

	for (j = 0; j < G->vexNum; ++j)
	{
		if (G->arc[i][j] == 1 && !visited[j])
			DFS(G, j);
	}

	
}

void DFSTraverse(MGraph *G)
{
	int i;
	for (i = 0; i < G->vexNum; ++i)
		visited[i] = FALSE;

	for (i = 0; i < G->vexNum; ++i)
	{
		if (!visited[i]) 
			DFS(G, i);
	}
}


void BFS(MGraph *G)
{
	LinkQueue Q;
	InitQueue(&Q);

	int i, j;
	for (i = 0; i < G->vexNum; ++i)
		visited[i] = FALSE;

	for (i = 0; i < G->vexNum; ++i)
	{
		if (!visited[i])
		{
			printf("%c", G->vexs[i]);
			visited[i] = TRUE;
			InsertQueue(&Q, i);

			while (Q.rear != Q.front)
			{
				DeleteQueue(&Q, &i);
				for (j = 0; j < G->vexNum; ++j)
				{
					if (G->arc[i][j] != INF && !visited[j])
					{
						visited[j] = TRUE;
						printf("%c", G->vexs[j]);
						InsertQueue(&Q, j);
					}
						
				}
			}
		}
	}
	
}