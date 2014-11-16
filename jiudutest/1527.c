#include<stdio.h>
#define MAXLENGTH 100005
int start;
int end;
int length;
int array[MAXLENGTH];
int smallestSubSum_Cir()
{
	int minSum = 0;
	int curSum = 0;
	int minStart = 0;
	int minEnd = 0;
	int curStart = 0;
	int curEnd = 0;
	int i;
	for(i = 0; i < length || (i % length) != curStart; i++)
	{
		int pos = i % length;
		if(curSum >= 0)
		{
			curSum = 0;
			curStart = pos;
			curEnd = pos;
		}
		curSum += array[pos];
		curEnd = pos;
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
int largestSubSum_Cir()
{
	int maxSum = 0;
	int curSum = 0;
	int maxStart = 0;
	int maxEnd = 0;
	int curStart = 0;
	int curEnd = 0;
	int i;
	for(i = 0; i < length || (i % length) != curStart; i++)
	{
		int pos = i % length;
		if(curSum <= 0)
		{
			curSum = 0;
			curStart = pos;
			curEnd = pos;
		}
		curSum += array[pos];
		curEnd = pos;
		if(curSum > maxSum)
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
		if(curSum <= 0)
		{
			curSum = 0;
			curStart = i;
			curEnd = i;
		}
		curSum += array[i];
		curEnd = i;
		if(curSum > maxSum)
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
int largestSubSumCircle_Cir()
{
	int i;
	int maxSum = 0;
	int sum = 0;
	int seqSum = largestSubSum_Cir();
	printf("start:%d  end:%d  sum:%d \n", start, end, seqSum);
	if(start == 0 && end == length - 1)
	{
		maxSum -= smallestSubSum_Cir();
	}
	return (seqSum + maxSum);
}
int largestSubSumCircle()
{
	int i;
	int maxSum = 0;
	int sum = 0;
	int seqSum = largestSubSum();
	//printf("start:%d  end:%d  sum:%d \n", start, end, seqSum);
	for(i = end + 1; (i % length) != start; i++)
	{
		sum += array[i % length];
		if(sum > maxSum)
		{
			maxSum = sum;
		}
	}
	if(start == 0 && end == length - 1)
	{
		maxSum -= smallestSubSum();
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
		for(i = start - 1; i >= 0; i--)
		{
			sum += array[i];
			if(sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}
	else
	{}
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
		printf("%d\n", largestSubSumCircle_Cir());
	}
	return 0;
}
