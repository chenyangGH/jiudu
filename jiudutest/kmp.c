#include<stdio.h>
#include<string.h>
#define MAXLENGTH 100001
char str1[MAXLENGTH];
char str2[MAXLENGTH];
int next[MAXLENGTH];
void getNext(char *str)
{
	int j, k;
	next[0] = -1;
	k = -1;
	j = 0;
	while(j < strlen(str))
	{
		if(k == -1 || str[k] == str[j])
		{
			k++;
			j++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}
int isSub(char * t, char * p)
{
	int lenT = strlen(t);
	int lenP = strlen(p);
	int i = 0;
	int j = 0;
	for(i = 0; i < lenT && j < lenP; /*i++*/)
	{
		if(t[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			if(next[j] >= 0)
			{
				j = next[j];
			}
			else
			{
				i++;
				j = 0;
			}
		}
	}
	if(j == lenP)
	{
		return 1;
	}
	return 0;
}
int main()
{
	while(scanf("%s %s",str1, str2) != EOF)
	{
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int res = 0;
		if(len1 > len2)
		{
			getNext(str2);
			res = isSub(str1, str2);
		}
		else
		{
			getNext(str1);
			res = isSub(str2, str1);
		}
		if(res == 1)
		{
			if(len1 > len2)
			{
				printf("str2 is the substr of str1\n");
			}
			else
			{
				printf("str1 is the substr of str2\n");
			}
		}
	}
	return 0;
}
