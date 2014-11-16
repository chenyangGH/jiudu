#include<stdio.h>
#include<string.h>
#include<assert.h>
#define MAXVALUE 100
#define MAXSIZE 5055
int value[MAXVALUE];
int length;
int hash[MAXSIZE];
int sum;
void combination(int n, int m, int level)
{
	assert(n >= m);
	if(m == n)
	{
		int i;
		for(i = 0; i < n; i++)
		{
			sum += value[level + i];
		}
		hash[sum] = 1;
		for(i = 0; i < n; i++)
		{
			sum -= value[level + i];
		}
	}
	else if(m == 0)
	{
		hash[sum] = 1;
	}
	else
	{
		sum += value[level];
		combination(n - 1, m - 1, level + 1);
		sum -= value[level];
		combination(n - 1, m, level + 1);
	}
}
void allCombination()
{
	int i = 0;
	for(i = 1; i <= length; i++)
	{
		sum = 0;
		combination(length, i, 0);
	}
}
int search()
{
	int i;
	for(i = 1; i < MAXSIZE; i++)
	{
		if(hash[i] == 0)
		{
			break;
		}
	}
	return i;
}
int main()
{
	while(scanf("%d", &length) != EOF)
	{
		int i;
		for(i = 0; i < length; i++)
		{
			scanf("%d", &value[i]);
		}
		memset(hash, 0, MAXSIZE * sizeof(int));
		allCombination();
		printf("%d\n", search());
	}
	return 0;
}
