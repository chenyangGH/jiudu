#include<stdio.h>
int binarySearch_v1(int array[], int low, int high, int value)
{
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(array[mid] == value)
		{
			return mid;
		}
		else if(array[mid] < value)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}
//恒等式： array[low] <= value && array[high] > value
//边界：|high - low| == 1
//输入：为保持恒等式，输入整个数组，输入的high值应该指向数组最后一个元素的后一个位置。否则，若需要查找的元素刚好是数组的最后一个元素的话，则会查找失败。因为初始的输入条件不满足恒等式。
int binarySearch_v2(int array[], int low, int high, int value)
{
	int mid;
	while((high - low) > 1)
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
