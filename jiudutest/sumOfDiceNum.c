#include<stdio.h>
#include<string.h>
#include<malloc.h>
void sumOfDiceNum(int diceSum[], int diceCount, int numCount)
{
	int n = diceCount;
	int m = numCount;
	int i;
	for(i = 0; i <= m * n; i++)
	{
		diceSum[i] = 0;
	}
	for(i = 1; i <= m; i++)
	{
		diceSum[i] = 1;
	}
	for(i = 2; i <= n; i++)
	{
		int j;
		for(j = i * m; j >= i; j--)
		{
			int k;
			diceSum[j] = 0;
			for(k = 1; (k <= m) && (j - k >= i - 1); k++)
			{
				diceSum[j] += diceSum[j - k];
			}
		}
	}
}
void top3(int diceSum[], int pdice[], int diceCount, int numCount)
{
	int start = diceCount;
	int end   = diceCount * numCount;
	int i;
	for(i = start; i < start + 3; i++)
	{
		int j;
		int maxIndex = i;
		for(j = i; j <= end; j++)
		{
			if(diceSum[j] > diceSum[maxIndex])
			{
				maxIndex = j;
			}
		}
		int temp = diceSum[i];
		diceSum[i] = diceSum[maxIndex];
		diceSum[maxIndex] = temp;
		pdice[i - start] = maxIndex;
	}
}
double power(int n, int m)
{
	if(m == 0)
	{
		return 1;
	}
	else if(m == 1)
	{
		return n;
	}
	else
	{
		double res = power(n, m / 2);
		res *= res;
		if((m & 1) == 1)
		{
			res *= n;
		}
		return res;
	}
}
int main()
{
	int n,m;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		if(n == 0)
		{
			break;
		}
		int *pdiceSum = (int *)malloc(sizeof(int) * (n * m + 1));
		int *pdice = (int*)malloc(sizeof(int) * 3);
		sumOfDiceNum(pdiceSum, n, m);
		int j;
		for(j = 0; j <= n * m; j++)
		{
			printf("%d:%d\n",j,pdiceSum[j]);
		}
		
		top3(pdiceSum, pdice, n, m);
		int i;
		double res = power(m, n);
		for(i = n; i < n + 3; i++)
		{
			printf("%d %.2f\n", pdice[i - n], ((double)pdiceSum[i]) / res);
		}
		printf("power is %lf\n", res);
	}
	return 0;
}
