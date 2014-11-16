#include<stdio.h>
#include<string.h>
#include<malloc.h>
int longestUpSubStr(int *pStart, int length, int* subLength)
{
//	int* subLength = (int*)malloc(length * sizeof(int));
	int i;
	for(i = 0; i < length; i++)
	{
		int j;
		int currentMax = 1;
		for(j = i - 1; j > 0; j--)
		{
			if(pStart[i] > pStart[j])
			{
				if(subLength[j] + 1 > currentMax)
				{
					currentMax = subLength[j] + 1;
				}
			}
		}
		subLength[i] = currentMax;
	}

	int maxIdx = 0;
	for(i = 0; i < length; i++)
	{
		if(subLength[maxIdx] < subLength[i])
		{
			maxIdx = i;
		}
	}
	return maxIdx;
}
int subtractNum(int* pStart, int length)
{
	int *pTemp = (int*)malloc(length * sizeof(int));
	int *subLength = (int*)malloc(length * sizeof(int));
	int i;
	for(i = 0; i < length; i++)
	{
		pTemp[i] = pStart[length - 1 - i];
	}
	int fromLeftIdx = longestUpSubStr(pStart, length, subLength);
	int leftLongest = subLength[fromLeftIdx];
	int fromRightIdx = longestUpSubStr(pTemp, length - fromLeftIdx, subLength); 
	int rightLongest = subLength[fromRightIdx];
	if(fromLeftIdx + fromRightIdx == length - 1)
	{
		return length - (leftLongest + rightLongest - 1);
	}
	int maxLength = 0;
	for(i = length - 1 - fromRightIdx + 1; i < fromLeftIdx; i++)
	{
		fromLeftIdx = longestUpSubStr(pStart, i + 1, subLength);
		leftLongest = subLength[fromLeftIdx];
		fromRightIdx = longestUpSubStr(pTemp, length - i, subLength);
		rightLongest = subLength[fromRightIdx];
		int curLength = leftLongest + rightLongest;
		if(fromLeftIdx + fromRightIdx == length - 1)
		{
			curLength --;
		}
		if(curLength > maxLength)
		{
			maxLength = curLength;
		}
	}
	return length - maxLength;
}
int students[1000005];
int main()
{
	int n;
	while(EOF != scanf("%d", &n))
	{
		int i;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &students[i]);
		}
	}
	return 0;
}
