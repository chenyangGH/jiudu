#include<stdio.h>
#include<string.h>
#define SUCCESS 1
#define FAILURE 0
#define SWAP(temp, a, b) do{(temp) = (a); (a) = (b); (b) = (temp);}while(0)
int clearSpace(char* str)
{
	if(str == NULL)
	{
		return FAILURE;
	}
	char* pre = str;
	char* back = str;
	int preSpace = 0;
	for(; *pre != '\0'; pre++)
	{
		if(*pre != ' ' || preSpace == 0)
		{
			*back = *pre;
			back++;
			if(*pre == ' ')
			{
				preSpace = 1;
			}
			else
			{
				preSpace = 0;
			}
		}
	}
	*back = '\0';
	return SUCCESS;
}
int reverseCh(char* start, char* end)
{
	if(start == NULL || end == NULL)
	{
		return FAILURE;
	}
	for(; start <= end; start++, end--)
	{
		char temp;
		SWAP(temp, *start, *end);
	}
	return SUCCESS;
}
int reverseWord(char* str)
{
	char* start = str;
	char* end = start;
	while(*end != '\0')
	{
		if(*end != ' ')
		{
			end++;
			continue;
		}
		reverseCh(start, end - 1);
		start = end + 1;
		end = start;
	}
	reverseCh(start, end - 1);
	return SUCCESS;
}
char input[100002];
int main()
{
	int length;
	while(scanf("%d", &length) != EOF)
	{
		char temp;
		temp = getchar();
		int i;
		for(i = 0; i < length; i++)
		{
			//scanf("%c", &input[i]);
			input[i] = getchar();
		}
		input[length] = '\0';
		if(clearSpace(input) == SUCCESS)
		{
			if(reverseWord(input) == SUCCESS)
			{
				puts(input);
			}
		}
	}
	return 0;
}
