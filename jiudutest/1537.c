#include<stdio.h>
#define SIZE 1001
int stock[SIZE];
int f[SIZE];
int length;
int timeLimit;
int times[SIZE];
int maxRevenue()
{
	int i;
	f[length - 1] = 0;
	times[length - 1] = 0;
	for(i = length - 2; i >= 0; i--)
	{
		int max = f[i + 1];
		int j;
		times[i] = times[i + 1];
		for(j = i + 1; j < length; j++)
		{
			if((stock[j] - stock[i] + f[j + 1]) > max && times[j + 1] < timeLimit)
			{
				max = stock[j] - stock[i] + f[j + 1];
				times[i] = times[j + 1] + 1;
			}
		}
		f[i] = max;
	}
	return f[0];
}
int main()
{
	while(scanf("%d %d", &length, &timeLimit) != EOF)
	{
		int i;
		for(i = 0; i < length; i++)
		{
			scanf("%d", &stock[i]);
		}
		printf("%d\n", maxRevenue());
	}
	return 0;
}
