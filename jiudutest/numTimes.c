#include<stdio.h>
#include<string.h>
#include<malloc.h>
int findLowThanValue(int data[], int oriLow, int oriHigh, int value)
{
	int low = oriLow;
	int high = oriHigh;
	while(low <= high)
	{
		int mid;
		mid = low + (high - low) / 2;
		if(data[mid] == value)
		{
			if(mid == oriLow)
				return mid;
			if(data[mid - 1] < value)
				return mid;
			else
			{//data[mid - 1] == value
				high = mid - 1;
			}
		}
		else if(data[mid] < value)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}
int findHighThanValue(int data[], int oriLow, int oriHigh, int value)
{
	int low = oriLow;
	int high = oriHigh;
	while(low <= high)
	{
		int mid;
		mid = low + (high - low) / 2;
		if(data[mid] == value)
		{
			if(mid == oriHigh)
				return mid;
			if(data[mid + 1] > value)
				return mid;
			else
			{//data[mid + 1] == value
				low = mid + 1;
			}
		}
		else if(data[mid] < value)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
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
			low = findLowThanValue(pData, 0, length - 1, num);
			high = findHighThanValue(pData, 0, length - 1, num);
			int count = 0;
			if(low != -1 && high != -1)
			{
				count = high - low + 1;
			}
			printf("%d\n",count);
		}
		free(pData);
	}
	return 0;
}
