#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define swap(a,b) do{  \
			int temp = (a); \
			(a)      = (b); \
			(b)      = temp;\
			}while(0);
void adjust(int data[], int lastIndex, int curIndex)
{
	if(lastIndex < 1 || curIndex > lastIndex)
	{
		return;
	}
	int temp = data[curIndex - 1];
	while(curIndex * 2 <= lastIndex)
	{
		int index = curIndex * 2;
		if((index + 1 <= lastIndex) && data[index + 1 - 1] < data[index - 1])
		{
			index++;
		}
		if(temp <= data[index - 1])
		{
			break;
		}
		data[curIndex - 1] = data[index - 1];
		curIndex = index;
	}
	data[curIndex - 1] = temp;
}
int main()
{
	int length;
	while(scanf("%d", &length) != EOF)
	{
		int *pData = (int*)malloc(length * sizeof(int));
		int i;
		for(i = 0; i < length; i++)
		{
			scanf("%d", &pData[i]);
		}
		printf("before sort\n");
		for(i = 0; i < length; i++)
		{
			printf("%d ", pData[i]);
		}
		printf("\nafter sort\n");
		for(i = length / 2; i > 0; i--)
		{
			adjust(pData, length, i);
		}
		for(i = 0; i < length; i++)
		{
			printf("%d ",pData[0]);
			swap(pData[0], pData[length - i - 1]);
			adjust(pData, length - i - 1, 1);
		}
		printf("\n");
		free(pData);
	}
}
