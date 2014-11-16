#include<stdio.h>
#include<string.h>
#define MAXLENGTH 2000005
#define MIN(a, b) ((a) < (b) ? (a) : (b))
void init(char* str, int size)
{
	int length = strlen(str);
	if(size < 1 || length < 1)
	{
		return;
	}
	if(length * 2 + 2 > size)
	{
		printf("buffer overflow, can not do init\n");
		return;
	}
	int newIndex = length * 2 - 1;
	int oldIndex = length - 1;
	str[newIndex + 2] = '\0';
	for(;oldIndex >= 0; newIndex -= 2, oldIndex--)
	{
		str[newIndex] = str[oldIndex];
		str[newIndex + 1] = '#';
	}
	str[0] = '#';
}
int LongPalSubStr(char* str, int* pRadus)
{
	if(*str == '\0' || str == NULL)
	{
		return 0;
	}
	init(str, MAXLENGTH);
	int length = strlen(str);
	int i = 0;
	for(i = 0; i < length; i++)
	{
		pRadus[i] = 0;
	}
	int mx = 1;
	int id = 0;
	pRadus[0] = 1;
	for(i = 1; i < length; i++)
	{
		if(i >= mx)
		{
			pRadus[i] = 1;
		}
		else
		{
			pRadus[i] = MIN(pRadus[id * 2 - i], mx - i);
		}
		for(; i - pRadus[i] >= 0 && i + pRadus[i] < length && str[i - pRadus[i]] == str[i + pRadus[i]]; pRadus[i]++);

		if(i + pRadus[i] > mx)
		{
			mx = i + pRadus[i];
			id = i;
		}
	}
	int maxRadusIdx = 0;
	for(i = 0; i < length; i++)
	{
		if(pRadus[maxRadusIdx] < pRadus[i])
		{
			maxRadusIdx = i;
		}
	}
	return pRadus[maxRadusIdx] - 1;
}
char str[MAXLENGTH];
int Radus[MAXLENGTH];
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int i = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%s", str);
			printf("%d\n", LongPalSubStr(str, Radus));
		}
	}
	return 0;
}
