#include<stdio.h>
#include<string.h>
#include<malloc.h>
int findLowThanValue(int data[], int low, int high, int value)
{
	int mid;
	while(high - low > 1)
	{
		mid = low + (high - low) / 2;
		if(data[mid] <= value)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}
	return low;
}

int findHighThanValue(int data[], int low, int high, int value)
{
	int mid;
	while(high - low > 1)
	{
		mid = low + (high - low) / 2;
		if(data[mid] >= value)
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}
	return high;
}

int main()
{
	int length = 0;
	while(EOF != scanf("%d", &length))
	{
		int* pData = (int*)malloc(sizeof(int) * length);
		int i = 0;
		for(i = 0; i < length; i++)
		{
			scanf("%d", &pData[i]);
		}
		int searchTimes = 0;
		scanf("%d", &searchTimes);
		for(i = 0; i < searchTimes; i++)
		{
			int num = 0;
			scanf("%d", &num);
			int low = 0;
			int high = 0;
			int count = 0;
			if(pData[0] <= num && pData[length - 1] >= num)
			{
				high = findLowThanValue(pData, 0, length, num);
				low = findHighThanValue(pData, -1, length - 1, num);
				if(pData[low] == num && pData[high] == num)
				{
					count = high - low + 1;
				}
				else
				{
					count = 0;
				}
			}
			printf("%d\n",count);
		}
		free(pData);
	}
	return 0;
}
