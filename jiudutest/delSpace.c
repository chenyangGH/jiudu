#include<stdio.h>
#include<string.h>
//�����ڱ��㷨�Ļ����Ͻ��иĽ����Ƚ�front��λ����һ���ո������Ȼ����ִ�н������Ĺ��̣���Ϊ��һ���ո�֮��������ַ������ƶ�����֮ǰ�Ĳ����ƶ�
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
