#include<stdio.h>
#include<assert.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ODD(a) ((a) & 1)
int midOfTwoArray(int arr1[], int arr2[], int length)
{
	if(arr1 == NULL || arr2 == NULL || length <= 0)
	{
		return -1;
	}
	int low1 = 0;
	int low2 = 0;
	int mid1;
	int mid2;
	int high1 = length - 1;
	int high2 = length - 1;
	while(low1 < high1 - 1 && low2 < high2 - 1)
	{
		mid1 = low1 + (high1 - low1) / 2;
		mid2 = low2 + (high2 - low2) / 2;
		if(arr1[mid1] == arr2[mid2])
		{
			return arr1[mid1];
		}
		else if(arr1[mid1] < arr2[mid2])
		{
			if(ODD(high2 - low2))
			{
				low1 = mid1 + 1;
			}
			else
			{
				low1 = mid1;
			}
			high2 = mid2;
		}
		else
		{
			if(ODD(high1 - low1))
			{
				low2 = mid2 + 1;
			}
			else
			{
				low2 = mid2;
			}
			high1 = mid1;
		}
	}
	if(arr1[low1] > arr2[high2])
	{
		return arr2[high2];
	}
	else if(arr2[low2] > arr1[high1])
	{
		return arr1[high1];
	}
	else
	{
		return MAX(arr1[low1], arr2[low2]);
	}
}
int midOfTwoArray_v1(int arr1[], int arr2[], int length)
{
	if(arr1 == NULL || arr2 == NULL || length <= 0)
	{
		return -1;
	}
	int low1 = 0;
	int low2 = 0;
	int mid1;
	int mid2;
	int high1 = length - 1;
	int high2 = length - 1;
	while(low1 < high1 || low2 < high2)
	{
		mid1 = low1 + (high1 - low1) / 2;
		mid2 = low2 + (high2 - low2) / 2;
		if(arr1[mid1] == arr2[mid2])
		{
			return arr1[mid1];
		}
		else if(arr1[mid1] < arr2[mid2])
		{
			low1 = mid1 + 1;
			high2 = mid2;
		}
		else
		{
			low2 = mid2 + 1;
			high1 = mid1;
		}
	}
	return MIN(arr1[MIN(low1, high1)], arr2[MIN(low2, high2)]);
}
int midOfTwoArray_v2(int arr1[], int arr2[], int length)
{
	if(arr1 == NULL || arr2 == NULL || length <= 0)
	{
		return -1;
	}
	int low1 = 0;
	int low2 = 0;
	int mid1;
	int mid2;
	int high1 = length - 1;
	int high2 = length - 1;
	while(low1 < high1 && low2 < high2)
	{
		mid1 = low1 + (high1 - low1) / 2;
		mid2 = low2 + (high2 - low2) / 2;
		if(arr1[mid1] <= arr2[mid2])
		{
			high2 = mid2;
			low1 = high1 - (high2 - low2);
		}
		else
		{
			high1 = mid1;
			low2 = high2 - (high1 - low1);
		}
	}
	return MIN(arr1[low1], arr2[low2]);
}

int midOfTwoArray_v3(int arr1[], int arr2[], int length)
{
	int mid;
	while(length > 1)
	{
		mid = (length - 1) >> 1;
		if(arr1[mid] <= arr2[mid])
		{
			arr1 += length >> 1;
		}
		else
		{
			arr2 += length >> 1;
		}
		length = mid + 1;
	}
	return MIN(arr1[0], arr2[0]);
}

int main()
{
	int arr1[1000];
	int arr2[1000];
	int length;
	while(scanf("%d", &length) != EOF)
	{
		int i = 0;
		for(; i < length; i++)
		{
			scanf("%d", &arr1[i]);
		}
		for(i = 0; i < length; i++)
		{
			scanf("%d", &arr2[i]);
		}
		printf("%d\n", midOfTwoArray_v3(arr1, arr2, length));
	}
	return 0;
}
