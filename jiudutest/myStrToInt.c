#include<stdio.h>
#include<ctype.h>
int strToInt(char* str)
{
	int neg = 0;
	int res = 0;
	int hasNum = 0;
	int hasSpace = 0;
	while(isspace(*str))
	{
		str++;
	}
	if(str == NULL)
	{
		return -1;
	}
	if(*str == '+')
	{
		neg = 0;
		str++;
	}
	else if(*str == '-')
	{
		neg = 1;
		str++;
	}
	else
	{
	}
	while(*str != '\0')
	{
		if(*str <= '9' && *str >= '0')
		{
			if(hasSpace == 1)
			{
				return -1;
			}
			hasNum = 1;
			res = res * 10 + (*str - '0');
		}
		else
		{
			if(isspace(*str))
			{
				hasSpace = 1;
			}
			else
			{
				return -1;
			}
		}
		str++;
	}
	if(hasNum == 0)
	{
		return -1;
	}
	if(neg == 1)
	{
		res = 0 - res;
	}
	return res;
}
int main()
{
	char str[1000];
	while(gets(str) != NULL)
	{
		int res = 0;
		res = strToInt(str);
		if(res == -1)
		{
			printf("My God\n");
		}
		else
		{
			printf("%d\n", res);
		}
	}
	return 0;
}
