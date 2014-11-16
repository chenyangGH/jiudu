#include<stdio.h>
//a[low] < value && a[high] >= value
//注意输入数据满足恒等式
#define MAXSIZE 100001
int length;
int array[MAXSIZE];
int len[MAXSIZE];
int minValue[MAXSIZE + 1];
int bSearch(int a[], int low, int high, int value)
{
	while((high - low) > 1)
	{
		int mid = low + (high - low) / 2;
		if(a[mid] >= value)
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}
}

int longestUpSubSeq()
{
	int i;
	int high = 1;
	minValue[0] = -1;
	minValue[1] = array[0];
	for(i = 0; i < length; i++)
	{
		int pos;
		if(array[i] > minValue[high])
		{
			high++;
			pos = high;
		}
		else
		{
			pos = bSearch(minValue, 0, high, array[i]);
		}
		minValue[pos] = array[i];
		len[i] = pos;
	}
	return high;
}
int main()
{
	while(scanf("%d", &length) != EOF)
	{
		int i;
		for(i = 0; i < length; i++)
		{
			scanf("%d", &array[i]);
		}
		if(length <= 0)
		{
			printf("%d\n",0);
		}
		else
		{
			printf("%d\n", longestUpSubSeq());
		}
	}
	return 0;
}
