#include<stdio.h>
#include<string.h>
#define MAXSIZE 1001
void reverse(char* buffer, int low, int high)
{
	if(buffer == NULL || low >= high)
	{
		return;
	}
	int i = low;
	int j = high;
	for(; i < j; i++, j--)
	{
		char temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
	}
}
int main()
{
	char buffer[MAXSIZE];
	int left;
	while(scanf("%s %d",buffer, &left) != EOF)
	{
		int length = strlen(buffer);
		left = left % length;
		reverse(buffer, 0, left - 1);
		reverse(buffer, left, length - 1);
		reverse(buffer, 0, length - 1);
		puts(buffer);
	}
	return 0;
}
