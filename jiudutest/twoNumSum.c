#include<stdio.h>
#include<string.h>
#include<malloc.h>
void findTwo(int data[], int sum, int low, int high, int* value1, int* value2)
{
	*value1 = -1;
	*value2 = -1;
	if(data == NULL)
		return;
	while(low < high)
	{
		if(data[low] + data[high] == sum)
		{
			*value1 = data[low];
			*value2 = data[high];
			return;
		}
		else if(data[low] + data[high] < sum)
		{
			low++;
		}
		else
		{
			high--;
		}
	}
}
int main()
{
	int length;
	int sum;
	while(scanf("%d %d", &length,&sum) != EOF)
	{
		int* pArray = (int*)malloc(length * sizeof(int));
		int i;
		for(i = 0; i < length; i++)
		{
			scanf("%d",&pArray[i]);
		}
		int value1;
		int value2;
		findTwo(pArray, sum, 0, length - 1, &value1, &value2);
		printf("%d %d\n",value1, value2);
	}
	return 0;
}
