#include<stdio.h>
#define MAXLENGTH 50005
void reverse(char* buffer, int begin, int end)
{
	if(buffer == NULL || begin >= end)
	{
		return;
	}
	int i,j;
	for(i = begin, j = end; i < j; i++, j--)
	{
		char temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
	}
}
int main()
{
	char buffer[MAXLENGTH];
	while(gets(buffer) != NULL)
	{
		int begin = 0;
		int end   = 0;
		while(buffer[begin] != '\0')
		{
			while(buffer[begin] == ' ')
			{
				begin++;
			}
			end = begin;
			while(buffer[end] != '\0' && buffer[end] != ' ')
			{
				end++;
			}
			reverse(buffer, begin, end - 1);
			begin = end;
		}
		reverse(buffer, 0, begin - 1);
		puts(buffer);
	}
}
