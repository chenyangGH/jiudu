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
//���ʽ�� array[low] <= value && array[high] > value
//�߽磺|high - low| == 1
//���룺Ϊ���ֺ��ʽ�������������飬�����highֵӦ��ָ���������һ��Ԫ�صĺ�һ��λ�á���������Ҫ���ҵ�Ԫ�ظպ�����������һ��Ԫ�صĻ���������ʧ�ܡ���Ϊ��ʼ������������������ʽ��
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
