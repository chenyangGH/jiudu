#include<stdio.h>
#define MAXLENGTH 100005
int start;
int end;
int length;
int array[MAXLENGTH];
int smallestSubSum()
{
	int minSum = 0;
	int curSum = 0;
	int minStart = 0;
	int minEnd = 0;
	int curStart = 0;
	int curEnd = 0;
	int i;
	for(i = 0; i < length; i++)
	{
		if(curSum >= 0)
		{
			curSum = 0;
			curStart = i;
			curEnd = i;
		}
		curSum += array[i];
		curEnd = i;
		if(curSum < minSum)
		{
			minSum = curSum;
			minStart = curStart;
			minEnd = curEnd;
		}
	}
	//start = minStart;
	//end = minEnd;
	return minSum;
}
int largestSubSum()
{
	int maxSum = 0;
	int curSum = 0;
	int maxStart = 0;
	int maxEnd = 0;
	int curStart = 0;
	int curEnd = 0;
	int i;
	for(i = 0; i < length; i++)
	{
		if(curSum < 0)
		{
			curSum = 0;
			curStart = i;
			curEnd = i;
		}
		curSum += array[i];
		curEnd = i;
		if(curSum >= maxSum)
		{
			maxSum = curSum;
			maxStart = curStart;
			maxEnd = curEnd;
		}
	}
	start = maxStart;
	end = maxEnd;
	return maxSum;
}
int largestSubSumCircle()
{
	int i;
	int maxSum = 0;
	int sum = 0;
	int seqSum = largestSubSum();
	//printf("start:%d  end:%d  sum:%d \n", start, end, seqSum);
	/*for(i = end + 1; (i % length) != start; i++)
	{
		sum += array[i % length];
		if(sum > maxSum)
		{
			maxSum = sum;
		}
	}*/
	if(start == 0 && end == length - 1)
	{
		maxSum = smallestSubSum();
		return (seqSum - maxSum);
	}
	else if(start == 0)
	{
		sum = 0;
		for(i = length - 1; i != end; i--)
		{
			sum += array[i];
			if(sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}
	else if(end == length - 1)
	{
		sum = 0;
		for(i = 0; i != start; i++)
		{
			sum += array[i];
			if(sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}
	else
	{
		int endToLeftSum = 0;
		int startToRightSum = 0;
		int sum = 0;
		for(i = 0; sum >= 0; i++)
		{
			sum += array[i];
			if(sum > startToRightSum)
			{
				startToRightSum = sum;
			}
		}
		sum = 0;
		for(i = length - 1; sum >= 0; i--)
		{
			sum += array[i];
			if(sum > endToLeftSum)
			{
				endToLeftSum = sum;
			}
		}
		if(endToLeftSum + startToRightSum > seqSum)
		{
			return (endToLeftSum + startToRightSum);
		}
		else
		{
			return seqSum;
		}
	}
	return (seqSum + maxSum);
}
int main()
{
	while(scanf("%d", &length) != EOF)
	{
		int i;
		start = 0;
		end = 0;
		for(i = 0; i < length; i++)
		{
			scanf("%d", &array[i]);
		}
		printf("%d\n", largestSubSumCircle());
	}
	return 0;
}
