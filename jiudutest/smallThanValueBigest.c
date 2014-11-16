#include<stdio.h>
int smallThanValueBigest(int array[], int low, int high, int value)
{
	int mid;
	while(high - low > 1)
	{
		mid = low + (high - low) / 2;
		if(array[mid] <= value)
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
int binarySearch(int array[], int low, int high, int value)
{
	int mid;
	while(high - low > 1)
	{
		mid = low + (high - low) / 2;
		if(array[mid] <= value)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}
	if(array[low] == value)
	{
		return low;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int array[1000];
	int n;
	int value;
	while((scanf("%d %d", &n, &value) != EOF) && n != 0)
	{
		int i;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &array[i]);
		}
		int res = smallThanValueBigest(array, 0, n, value);
		printf("the biggest number small than %d is %d in array\n", value, array[res]);
	}
}
