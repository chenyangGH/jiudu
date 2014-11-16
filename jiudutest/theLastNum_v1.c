#include<stdio.h>
int theLastNum(int length, int m)
{
	int res = 0;
	int i;
	for(i = 2; i <= length; i++)
	{
		res = (res + m) % i;
	}
	return res + 1;
}
int main()
{
	int length,m;
	while(scanf("%d %d", &length, &m) != EOF && length != 0)
	{
		printf("%d\n",theLastNum(length, m));
	}
}
