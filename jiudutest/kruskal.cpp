#include<stdio.h>
#define MAXNODE 1000001
int visited[MAXNODE];
int length;
typedef struct _Connect Connect;
struct _Connect
{
	int next;
	int weight;
}
typedef struct _Edge Edge;
struct _Edge
{
	int node;
	Connect con;
}
typedef struct _MiniSpanTree MiniSpanTree;
struct _MiniSpanTree
{
	int count;
	vector<Connect> tree[MAXNODE];
};
MiniSpanTree spanTree;
int cmp(const void *p1, const void *p2)
{
	return (((Edge*)p1)->con).weight - (((Edge*)p2)->con).weight;
}
int checkConnect(int v1, int v2)
{
	for(vector<Connect>::iterator it = spanTree.tree[v1].start; it != spanTree.tree[v1].end; it++)
	{
		if(it->next == v2)
		{
			return 1;
		}
	}
	return 0;
}
void findMiniSpanTree(Edge edges[], int count)
{
	qsort(edges, count, sizeof(Edge), cmp);
	int i;
	for(i = 0; i < count; i++)
	{
		if(checkConnect(edges[i].node, edges[i].con.next) == 1)
		{
			continue;
		}
		Connect tcon1;
		tcon1 = edges[i].con;
		spanTree.tree[edges[i].node].push_back(tcon1);
		tcon1.next = edges[i].node;
		spanTree.tree[edges[i].con.next].push_back(tcon1);
	}
}
int main()
{
	int vCount;
	int eCount;
	while(scanf("%d %d", &vCount, &eCount) != EOF)
	{
		int i;
		Edge* pedges = (Edge*)malloc(eCount * sizeof(Edge));
		for(i = 0; i < eCount; i++)
		{
			scanf("%d %d %d", &pedges[i].node, &(pedges[i].con.next), &(pedges[i].con.weight));
		}
		free(pedges);
	}
}
