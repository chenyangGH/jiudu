#include<stdio.h>
#define N 4
int d[N];
int visit[N];
int ve[N][N];

void dfs(int depth, int vetex)
{
	int i;
	int j;
	int printed = 0;
	//i从0到N-1是所有的排列，i从vetex到N-1是所有的组合
	for(i = vetex; i < N; i++)
	{
		if(ve[vetex][i] != 0)
		{
			if(visit[i] == 0)
			{
				visit[i] = 1;
				d[depth] = i;
				dfs(depth + 1, i);
				visit[i] = 0;
				d[depth] = -1;
			}
			else
			{
				if(printed == 1)
				{
					continue;
				}
				printed = 1;
				for(j = 0; j < N; j++)
				{
					printf("%d ",d[j]);
				}
				printf("\n");
			}
		}
	}
}
int main()
{
	int i = 0;
	int j = 0;
	for(i = 0; i < N; i++)
	{
		d[i] = -1;
		visit[i] = 0;
		for(j = 0; j < N; j++)
		{
			ve[i][j] = 1;
		}
	}
	dfs(0,0);
	return 0;
}
