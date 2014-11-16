#include<stdio.h>
#include<stdlib.h>
#define MAXVALUE 510000
#define MAXSIZE 501
typedef struct _area Area;
struct _area
{
	int start;
	int len;
	int sum;
};
int length;
int areaCount; 
int books[MAXSIZE];
Area area[MAXSIZE];
int compare(const void *a, const void *b)
{
	return *((int*)a) - *((int*)b);
}
void init()
{
	qsort(books, length, sizeof(int), compare);
	int quotient = length / areaCount;
	int remainder = length % areaCount;
	int i = 0;
	for(i = 0; i < areaCount; i++)
	{
		area[i].len = quotient;
	}
	int j;
	for(i = 0, j = remainder; j > 0; j--, i++)
	{
		area[i].len++;
	}
	area[0].start = 0;
	area[0].sum = 0;
	for(j = 0; j < area[0].len; j++)
	{
		area[0].sum += books[area[0].start + j];
	}
	for(i = 1; i < areaCount; i++)
	{
		area[i].start = area[i - 1].start + area[i - 1].len;
		area[i].sum = 0;
		for(j = 0; j < area[i].len; j++)
		{
			area[i].sum += books[area[i].start + j];
		}
	}
}
int findMin(int range)
{
	int i;
	int minIdx = 0;
	for(i = 0; i < range; i++)
	{
		if(area[i].sum < area[minIdx].sum)
		{
			minIdx = i;
		}
	}
	return minIdx;
}
int findMax()
{
	int i;
	int maxIdx = 0;
	for(i = 0; i < areaCount; i++)
	{
		if(area[i].sum > area[maxIdx].sum)
		{
			maxIdx = i;
		}
	}
	return maxIdx;
}
int adjust()
{
	int lastMin = -1;
	int lastMax = MAXVALUE;
	for(;;)
	{
		int maxIdx = findMax();
		int minIdx = findMin(maxIdx);
		if(lastMax < area[maxIdx].sum)
		{
			break;
		}
		if(minIdx == maxIdx)
		{
			break;
		}
		lastMin = area[minIdx].sum;
		lastMax = area[maxIdx].sum;
		int i;
		area[minIdx].len++;
		area[minIdx].sum += books[area[minIdx + 1].start];
		area[maxIdx].len--;
		area[maxIdx].sum -= books[area[maxIdx].start];
		area[maxIdx].start++;
		for(i = minIdx + 1; i <= maxIdx - 1; i++)
		{
			area[i].sum -= books[area[i].start];
			area[i].sum += books[area[i].start + area[i].len];
			area[i].start++;
		}
	}
	if(lastMax == MAXVALUE)
	{
		lastMax = area[0].sum;
	}
	return lastMax;
}

int main()
{
	int testCount;
	while(EOF != scanf("%d", &testCount))
	{
		int testIdx;
		for(testIdx = 0; testIdx < testCount; testIdx++)
		{
			scanf("%d %d", &length, &areaCount);
			int i;
			for(i = 0; i < length; i++)
			{
				scanf("%d", &books[i]);
			}
			init();
			printf("%d\n", adjust());
		}
	}
}
