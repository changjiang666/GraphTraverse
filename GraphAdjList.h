#pragma once
#define MAXVEXS 10
#define FALSE 0
#define TRUE  1

typedef int Boolean;
typedef char VertexType;
typedef int EageType;
typedef struct EageNode
{
	int adjvex;
	EageType weight;
	struct EageNode *next;
}EageNode;

typedef struct VexNode
{
	VertexType data;
	EageNode *firsteage;
}VexNode, AdjList[MAXVEXS];

typedef struct
{
	AdjList adjList;
	int vexNum, eageNum;
}GraphAdjList;

Boolean visit[MAXVEXS];

void CreateGraphAdjList(GraphAdjList *G);
void DFS_(GraphAdjList *G, int i);
void DFS_Search(GraphAdjList *G);
void BFSTraverse(GraphAdjList *G);


