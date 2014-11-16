#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define TESTBIT(num,n) ((1 << (n)) & (num))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
void findTwoNum(int data[], int length, int* value1, int* value2)
{
	int temp = 0;
	*value1 = 0;
	*value2 = 0;
	int i;
	for(i = 0; i < length; i++)
	{
		temp ^= data[i];
	}
	for(i = 0; i < 32; i++)
	{
		if(TESTBIT(temp,i))
			break;
	}
	int j;
	for(j = 0; j < length; j++)
	{
		if(TESTBIT(data[j],i))
		{
			*value1 ^= data[j];
		}
		else
		{
			*value2 ^= data[j];
		}
	}
}
int main()
{
	int length;
	while(scanf("%d", &length) != EOF)
	{
		int* pArray = (int*)malloc(sizeof(int) * length);
		int i;
		for(i = 0; i < length; i++)
		{
			scanf("%d", &pArray[i]);
		}
		int value1;
		int value2;
		findTwoNum(pArray, length, &value1, &value2);
		printf("%d %d\n",MIN(value1, value2), MAX(value1, value2));
		free(pArray);
	}
	return 0;
}
