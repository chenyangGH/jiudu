#include<stdio.h>
#include<string.h>
#include<malloc.h>
void numOfDice(int diceSum, int level, int n, int m, int *count)
{
	if(diceSum < 1)
	{
		return;
	}
	else if(level == n && diceSum <= m)
	{
		*count += 1;
	}
	else
	{
		int i;
		for(i = 1; i <= m; i++)
		{
			numOfDice(diceSum - i, level + 1, n, m, count);
		}
	}
}
int main()
{
	int n,m,diceSum;
	while(scanf("%d %d %d", &n, &m, &diceSum) != EOF)
	{
		int count = 0;
//void numOfDice(int diceSum, int level, int n, int m, int *count)
		numOfDice(diceSum, 1, n, m, &count);
		printf("%d\n",count);
	}
	return 0;
}
