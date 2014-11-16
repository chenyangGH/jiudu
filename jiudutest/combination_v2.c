/*
 * f[n,m] = f[n - 1, m - 1] + f[n - 1, m]
 * correct
 * allCombination
 * chenyang
 * 2014-07-08
 */
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<malloc.h>
int length;
int count;
void print(int* pArray)
{
	int i = 0;
	for(i = 0; i < length; i++)
	{
		if(pArray[i] == 1)
		{
			printf("%c ",'a' + i);
		}
	}
	printf("\n");
}
void combination(int* pArray, int n, int m, int level)
{
	assert(n >= m);
	if(n == m)
	{
		int i;
		for(i = 0; i < m; i++)
		{
			pArray[level + i] = 1;
		}
		count++;
		print(pArray);
		for(i = 0; i < m; i++)
		{
			pArray[level + i] = 0;
		}
	}
	else if(m == 0)
	{
		count++;
		print(pArray);
	}
	else
	{
		pArray[level] = 1;
		combination(pArray, n - 1, m - 1, level + 1);
		pArray[level] = 0;
		combination(pArray, n - 1, m, level + 1);
	}
}
void allCombination(int n)
{
	length = n;
	int* pArray = (int*)malloc(sizeof(int) * length);
	int i;
	for(i = 0; i < length; i++)
	{
		pArray[i] = 0;
	}
	count = 0;
	for(i = 1; i <= n; i++)
	{
		combination(pArray, n, i, 0);
	}
	printf("combination count is %d\n",count);
	free(pArray);
}
int main()
{
	int n = 0;
	while((scanf("%d", &n) != EOF) && n >= 1)
	{
		allCombination(n);
	}
}
