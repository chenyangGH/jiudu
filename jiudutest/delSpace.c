#include<stdio.h>
#include<string.h>
//可以在本算法的基础上进行改进，先将front定位到第一个空格符处，然后再执行接下来的过程，因为第一个空格之后的所有字符都会移动，而之前的不用移动
void delSpace_new(char str[])
{
	int front = 0;
	for(; str[front] != '\0'; front++)
	{
		if(str[front] == ' ')
		{
			break;
		}
	}
	int back = front - 1;
	for(; str[front] != '\0'; front++)
	{
		if(str[front] != ' ')
		{
			str[++back] = str[front];
		}
	}
	str[++back] = '\0';
}
void delSpace(char str[])
{
	int back = -1;
	int front = 0;
	for(; str[front] != '\0'; front++)
	{
		if(str[front] != ' ')
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
		delSpace_new(str);
		puts(str);
	}
}
