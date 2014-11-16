#include<stdio.h>
#include<string.h>
#include<malloc.h>
int findCommon(int array1[], int length1, int array2[], int length2)
{
	if(array1 == NULL || array2 == NULL)
		return -1;
	else
	{
		int i,j,flag;
		flag = 0;
		for(i = length1 - 1, j = length2 - 1; i >= 0, j >= 0; i--, j--)
		{
			if(array1[i] != array2[j])
			{
				break;
			}
		}
		if(i == length1 - 1)
		{
			return -1;
		}
		else
		{
			if(i == -1 && j == -1)
			{
				return array1[0];
			}
			else if(i == -1)
			{
				return array1[0];
			}
			else if(j == -1)
			{
				return array2[0];
			}
			else
			{
				return array1[i + 1];
			}
		}
	}
}
int main()
{
	int length1;
	int length2;
	while(scanf("%d %d",&length1, &length2) != EOF)
	{
		int i;
		int *array1,*array2;
		array1 = (int *)malloc(sizeof(int) * length1);
		array2 = (int *)malloc(sizeof(int) * length2);
		for(i = 0; i < length1; i++)
		{
			scanf("%d", &array1[i]);
		}
		for(i = 0; i < length2; i++)
		{
			scanf("%d", &array2[i]);
		}
		int ret;
		ret = findCommon(array1, length1, array2, length2);
		if(ret == -1)
		{
			printf("My God\n");
		}
		else
		{
			printf("%d\n",ret);
		}
		free(array1);
		free(array2);
	}
	return 0;
}
