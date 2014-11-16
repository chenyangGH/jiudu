/*
 * error
 * allCombination
 * chenyang
 * 2014-07-08
 */
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define SWAP(a, b, temp)      do{                           \
					(temp) = (a);       \
					(a)    = (b);       \
					(b)    = (temp);    \
				}while(0)
//从n个中选出m个的组合
void print(char str[], int length)
{
	int i = 0;
	for(i = 0; i < length; i++)
	{
		if(str[i] == 1)
		{
			printf("%c ", 'a' + i);
		}
	}
	printf("\n");
}
void combination(int n, int m)
{
	char* pIndexArray = (char*)malloc(sizeof(char) * n);
	char temp;
	int i;
	for(i = 0; i < m; i++)
	{
		int j;
		for(j = 0; j < n; j++)
		{
			pIndexArray[j] = 1;
		}
		for(j = n - 1 - i; j >= m - i; j--)
		{
			pIndexArray[j] = 0;
		}
		print(pIndexArray, n);
		if(j == -1 || j == n - 1)
		{
			break;
		}
		for(; j >= 0; j--)
		{
			SWAP(pIndexArray[j], pIndexArray[j + 1], temp);
			//print
			print(pIndexArray, n);
		}
		if(m == n - 1)
		{
			break;
		}
	}
	free(pIndexArray);
}

void allCombination(int n)
{
	int i;
	for(i = 1; i<= n; i++)
	{
		combination(n, i);
	}
}

int main()
{
	int n;
	while((scanf("%d", &n) != EOF) && (n >= 1))
	{
		allCombination(n);
	}
	return 0;
}
