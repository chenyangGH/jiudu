#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int palSubSeqLength(char str[], int length)
{
	int** pArray = (int**)malloc(sizeof(int*) * length);
	int i = 0;
	for(i = 0; i < length; i++)
	{
		pArray[i] = (int*)malloc(sizeof(int) * length);
	}
	for(i = 0; i < length; i++)
	{
		pArray[i][i] = 1;
	}
	int subLength = 2;
	for(i = 0; i < length - 1; i++)
	{
		if(str[i] == str[i + subLength - 1])
		{
			pArray[i][i + subLength - 1] = 2;
		}
		else
		{
			pArray[i][i + subLength - 1] = 1;
		}
	}
	for(subLength = 3; subLength <= length; subLength++)
	{
		int start;
		for(start = 0; start + subLength - 1 < length; start++)
		{
			int end = start + subLength - 1;
			if(str[start] == str[end])
			{
				pArray[start][end] = MAX(pArray[start + 1][end - 1] + 2, MAX(pArray[start][end - 1], pArray[start + 1][end]));
			}
			else
			{
				pArray[start][end] = MAX(pArray[start + 1][end - 1], MAX(pArray[start][end - 1], pArray[start + 1][end]));
			}
		}
	}
	return pArray[0][length - 1];
}
int main()
{
	char str[1000];
	while(gets(str) != NULL)
	{
		printf("%d\n", palSubSeqLength(str, strlen(str)));
	}
	return 0;
}
