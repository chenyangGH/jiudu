#include<stdio.h>
#include<string.h>
void doWorm(char *str)
{
	int back = 0;
	int front = 1;
	if(strlen(str) <= 1)
	{
		return;
	}
	for(; str[front] != '\0'; front++)
	{
		if(str[back] != str[front])
		{
			str[++back] = str[front];
		}
	}
	str[++back] = '\0';
}
int main()
{
	char str[1000];
	while(gets(str) != NULL)
	{
		doWorm(str);
		puts(str);
	}
}
