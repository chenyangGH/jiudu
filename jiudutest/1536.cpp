#include<iostream>
#include<stdio.h>
#include<vector>
#include<memory.h>
using namespace std;
vector<int> tree[1000001];
bool visited[1000001];
int curDepth;
int maxDepth;
int maxNode;
void depth(int node)
{
	for(vector<int>::iterator iter = tree[node].begin(); iter != tree[node].end(); iter++)
	{
		if(visited[*iter] == 0)
		{
			visited[*iter] = 1;
			curDepth++;
			if(curDepth > maxDepth)
			{
				maxDepth = curDepth;
				maxNode = node;
			}
			depth(*iter);
			curDepth--;
		}
	}
}
int shortestDep(int n)
{
	curDepth = 1;
	maxDepth = -1;
	maxNode = 0;
	visited[0] = 1;
	depth(0);
	int i;
	for(i = 0; i < n; i++)
	{
		visited[i] = 0;
	}
	int start = maxNode;
	curDepth = 1;
	maxDepth = -1;
	visited[start] = 1;
	depth(start);
	int radus = maxDepth;
	return (radus + 1) / 2;
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int i;
		for(i = 0; i < n; i++)
		{
			visited[i] = 0;
			tree[i].clear();
		}
		for(i = 0; i < n - 1; i++)
		{
			int node1;
			int node2;
			scanf("%d %d", &node1, &node2);
			tree[node1].push_back(node2);
			tree[node2].push_back(node1);
		}
		printf("%d\n", shortestDep(n));
	}
	return 0;
}
