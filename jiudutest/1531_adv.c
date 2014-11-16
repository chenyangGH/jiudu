#include<stdio.h>
#define MAXSIZE 5055
#define MAXVALUE 100
int hash[MAXSIZE];
int value[MAXVALUE];
int valueSum[MAXVALUE][MAXVALUE];
int length;
void initValueSum()
{
	int i;
	int j;
	for(i = 0; i < length - 1; i++)
	{
		valueSum[i][i] = value[i];
		for(j = i + 1; j < length; j++)
		{
			valueSum[i][j] = valueSum[i][j - 1] + value[j];
			hash[valueSum[i][j]] = 1;
		}
	}
}
void allValueSum()
{
	int i;
	int j;
	int k;
	int l;
	for(i = 0; i < length - 1; i++)
	{
		for(j = i + 1; j < length; j++)
		{
			int dif = value[i] - value[j];
			for(k = 0; k <= i; k++)
			{
				for(l = i; l < j; l++)
				{
					valueSum[k][l] -= dif;
					hash[valueSum[k][l]] = 1;
				}
			}
			for(k = i + 1; k <= j; k++)
			{
				for(l = j; l < length; l++)
				{
					valueSum[k][l] += dif;
					hash[valueSum[k][l]] = 1;
				}
			}
		}
	}
}

int search()
{
	int i;
	for(i = 1; i < MAXSIZE; i++)
	{
		if(hash[i] == 0)
		{
			break;
		}
	}
	return i;
}
