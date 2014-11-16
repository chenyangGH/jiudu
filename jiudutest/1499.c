#include<stdio.h>
#include<stdlib.h>
#define MAXCOUNT 10001
#define MAXVALUE(a,b) ((a) > (b) ? (a) : (b))
typedef struct _project project;
struct _project
{
	int start;
	int end;
	int income;
};
int maxIncome[MAXCOUNT];
project projectArr[MAXCOUNT]; 
int projectCount;
int compare(const void *a, const void *b)
{
	return ((project*)a)->end - ((project*)b)->end;
}
int calMaxIncome()
{
	qsort(projectArr, projectCount, sizeof(project), compare);
	int i;
	maxIncome[0] = projectArr[0].income;
	for(i = 1; i < projectCount; i++)
	{
		int j;
		for(j = i - 1; j >= 0; j--)
		{
			if(projectArr[j].end <= projectArr[i].start)
			{
				break;
			}
		}
		int maxCandidate = projectArr[i].income;
		if(j != -1)
		{
			maxCandidate += maxIncome[j];
		}
		maxIncome[i] = MAXVALUE(maxCandidate, maxIncome[i - 1]);
	}
	return maxIncome[projectCount - 1];
}

int main()
{
	int count;
	while(scanf("%d", &count) != EOF)
	{
		projectCount = count;
		int i;
		for(i = 0; i < count; i++)
		{
			scanf("%d %d %d", &projectArr[i].start, &projectArr[i].end, &projectArr[i].income);
			maxIncome[i] = 0;
		}
		printf("%d\n", calMaxIncome());
	}
	return 0;
}
