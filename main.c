#include "MGraph.h"
#include "GraphAdjList.h"

main(void)
{
	MGraph G;
	CreateMGraph(&G);

	DFSTraverse(&G);
	printf("\n");
	BFS(&G);

	/*GraphAdjList G;
	CreateGraphAdjList(&G);
	DFS_Search(&G);
	BFSTraverse(&G);*/
	return 0;
}