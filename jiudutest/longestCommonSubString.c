#include<stdio.h>
#include<string.h>
#include<malloc.h>
int longComSubStr(char str1[], char str2[], int length1, int length2)
{
	if(str1 == NULL || str2 == NULL || length1 <= 0 || length2 <= 0)
	{
		printf("Input Error!\n");
		return -1;
	}
	int maxLength = 0;
	int endIdx1;
	int endIdx2;
	int **pComLength = (int**)malloc(sizeof(int*) * length1);
	int i;
	for(i = 0; i < length1; i++)
	{
		pComLength[i] = (int*)malloc(sizeof(int) * length2);
	}
	int j;
	for(i = 0; i < length1; i++)
	{
		for(j = 0; j < length2; j++)
		{
			pComLength[i][j] = 0;
		}
	}
	for(i = 0; i < length1; i++)
	{
		for(j = 0; j < length2; j++)
		{
			if(str1[i] == str2[j])
			{
				if(i == 0 || j == 0)
				{
					pComLength[i][j] = 1;
				}
				else
				{
					pComLength[i][j] = pComLength[i - 1][j - 1] + 1;
				}
				if(pComLength[i][j] > maxLength)
				{
					maxLength = pComLength[i][j];
					endIdx1 = i;
					endIdx2 = j;
				}
			}
		}
	}
	printf("common string length is %d, last index of string1 and string2 is %d and %d\n",maxLength, endIdx1, endIdx2);
	for(i = 0; i < length1; i++)
	{
		free(pComLength[i]);
	}
	free(pComLength);
}

int main()
{
	char str1[1000], str2[1000];
	while(gets(str1) != NULL && gets(str2) != NULL)
	{
		longComSubStr(str1, str2, strlen(str1), strlen(str2));
	}
	return 0;
}
