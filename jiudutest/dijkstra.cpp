#include<stdio.h>
#include<vector>
using namespace std;
#define SIZE 10001
#define MAXDIST 1000000
int length;
int prio[SIZE];
int dist[SIZE];
int radius[SIZE];
bool visited[SIZE];
typedef struct _Edge Edge;
struct _Edge
{
	int next;
	int weight;
};
vector<Edge> edge[SIZE];
void findRadius(int start, int level)
{
		radius[start] = level;
		for(vector<Edge>::iterator it = edge[start].begin(); it != edge[start].end(); it++)
		{
				if(!visited[it->next])
				{
						visited[it->next] = true;
						findRadius(it->next, level + 1);
				}
		}
}
void shortest(int start)
{
	int current;
	int mindist = MAXDIST;
	for(int i = 0; i < SIZE; i++)
	{
		dist[i] = MAXDIST;
	}
	dist[start] = 0;
	for(vector<Edge>::iterator it = edge[start].begin(); it != edge[start].end(); it++)
	{
		dist[it->next] = it->weight;
		prio[it->next] = start;
		if(it->weight < mindist)
		{
			mindist = it->weight;
			current = it->next;
		}
	}
	while(true)
	{
		int nextCurrent;
		int mindist = MAXDIST;
		for(vector<Edge>::iterator it = edge[current].begin(); it != edge[current].end(); it++)
		{
			int temp = dist[current] + it->weight;
			if(temp < dist[it->next])
			{
				dist[it->next] = temp;
				prio[it->next] = current;
				if(temp < mindist)
				{
					mindist = temp;
					nextCurrent = it->next;
				}
			}
		}
		if(mindist == MAXDIST)
		{
			break;
		}
		current = nextCurrent;
	}
}
int shortestPathWithinK(int k)
{
		int i;
		int count = 0;
		for(i = length - 1; i > 0; i = prio[i]);
		{
				if(dist[i] <= k)
				{
						count++;
				}
		}
		return count;
}
int main()
{
		int s;
		int e;
		int w;
		while(scanf("%d %d %d", &s, &e, &w) != EOF)
		{
				Edge ed;
				ed.next = e;
				ed.weight = w;
				edge[s].push_back(ed);
				ed.next = s;
				edge[e].push_back(ed);
				if(s == -1)
				{
					break;
				}
		}
		shortest(0);
		int i;
		for(i = 0; i < 10; i++)
		{
			printf("%d\n", dist[i]);
		}
}
