#include<stdio.h>
#include<string.h>
#define MAXLENGTH 10001
char str[MAXLENGTH];
int hash[30];
int findMaxLength()
{
	int length = strlen(str);
	int i;
	int maxLength = 0;
	int curLength = 0;
	for(i = 0; i < 30; i++)
	{
		hash[i] = -1;
	}
	for(i = 0; i < length; i++)
	{
		int pos = str[i] - 'a';
		if(hash[pos] == -1)
		{

			hash[pos] = i;
			curLength++;
			if(curLength > maxLength)
			{
				maxLength = curLength;
			}
		}
		else
		{
			int j;
			i = hash[pos];
			for(j = 0; j < 30; j++)
			{
				hash[j] = -1;
			}
			curLength = 0;
		}
	}
	return maxLength;
}
int main()
{
	while(scanf("%s",str) != EOF)
	{
		printf("%d\n", findMaxLength());
	}
	return 0;
}
