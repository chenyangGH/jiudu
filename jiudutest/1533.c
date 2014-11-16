#include<stdio.h>
#define MAXLENGTH 100001
int array[MAXLENGTH];
int len[MAXLENGTH];
int length;
int longestUpSubSeq()
{
	int i;
	for(i = 0; i < length; i++)
	{
		len[i] = 1;
	}
	for(i = 0; i < length; i++)
	{
		int j;
		for(j = 0; j < i; j++)
		{
			int tempLen = 0;
			if(array[i] > array[j])
			{
				tempLen = len[j] + 1;
			}
			if(tempLen > len[i])
			{
				len[i] = tempLen;
			}
		}
	}
	int maxIdx = 0;
	for(i = 0; i < length; i++)
	{
		if(len[i] > len[maxIdx])
		{
			maxIdx = i;
		}
	}
	return len[maxIdx];
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
		printf("%d\n", longestUpSubSeq());
	}
	return 0;
}
