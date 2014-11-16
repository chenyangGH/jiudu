#include<stdio.h>
#define MAXSIZE 5051
#define MAXVALUE 100
#define GETMAX(a,b) ((a) > (b) ? (a) : (b))
int value[MAXVALUE];
int res[MAXSIZE];
int length;
int findRes()
{
	int i;
	for(i = 0; i < MAXSIZE; i++)
	{
		res[i] = 0;
	}
	for(i = 0; i < length; i++)
	{
		int j;
		for(j = MAXSIZE - 1; j >= value[i]; j--)
		{
			res[j] = GETMAX(res[j], res[j - value[i]] + value[i]);
		}
	}
	for(i = 1; i < MAXSIZE; i++)
	{
		if(res[i] != i)
		{
			break;
		}
	}
	return i;
}
int main()
{
	while(scanf("%d", &length) != EOF)
	{
		int i;
		for(i = 0; i < length; i++)
		{
			scanf("%d", &value[i]);
		}
		printf("%d\n", findRes());
	}
	return 0;
}
