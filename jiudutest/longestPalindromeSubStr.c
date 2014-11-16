#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAXLENGTH 2000005
#define MIN(a, b) ((a) < (b) ? (a) : (b))
//实现在O(n)时间复杂度与O(1)的空间复杂度条件下在相邻的字符之间插入#
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
	//程序正确性的验证
	//1.证明原字符串不会被覆盖，即不会丢失字符串
	//2.证明每一个相邻的字符串之间都插入了#，即证明不存在遗漏
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
void LongPalSubStr_v1(char* str)
{
	if(str == NULL)
	{
		return;
	}
	int length = strlen(str);
	int** ppPal = (int**)malloc(length * sizeof(int*));
	int i = 0;
	for(; i < length; i++)
	{
		ppPal[i] = (int*)malloc(length * sizeof(int));
	}
	for(i = 0; i < length - 1; i++)
	{
		ppPal[i][i] = 1;
		if(str[i] == str[i + 1])
		{
			ppPal[i][i + 1] = 1;
		}
		else
		{
			ppPal[i][i + 1] = 0;
		}
	}
	ppPal[length - 1][length - 1] = 1;
	int step = 2;
	for(; step < length; step++)
	{
		for(i = 0; i < length - step; i++)
		{
			if(str[i] == str[i + step])
			{
				ppPal[i][i + step] = ppPal[i + 1][i + step - 1];
			}
			else
			{
				ppPal[i][i + step] = 0;
			}
		}
	}
	for(step = length - 1; step >= 1; step--)
	{
		for(i = 0; i < length - step; i++)
		{
			if(ppPal[i][i + step] == 1)
			{
				int j = 0;
				for(; j <= step; j++)
				{
					printf("%c", str[j + i]);
				}
				printf("\n");
				goto END;
			}
		}
	}
END:	
	for(i = 0; i < length; i++)
	{
		free(ppPal[i]);
	}
	free(ppPal);
}
void LongPalSubStr_v2(char* str)
{
	if(str == NULL)
	{
		return;
	}
	int maxIdx = 0;
	int maxRadus = 1;
	int i = 1;
	int length = strlen(str);
	for(; i < length - 1; i++)
	{
		int j = 1;
		for(; i - j >= 0 && i + j < length && str[i - j] == str[i + j]; j++);
		if(maxRadus < j)
		{
			maxRadus = j;
			maxIdx   = i;
		}
	}
	int j;
	for(j = maxIdx - maxRadus + 1; j < maxIdx + maxRadus; j++)
	{
		if(str[j] != '#')
		{
			printf("%c", str[j]);
		}
	}
	printf("\n");
}
int main()
{
	char str[MAXLENGTH];
	int pRadus[MAXLENGTH];
	/*
	while(gets(str) != NULL)
	{
		printf("longest Palindrome sudstring\n");
		LongPalSubStr_v1(str);
		init(str, MAXLENGTH);
		LongPalSubStr(str);
		LongPalSubStr_v2(str);
	}*/
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int i = 0;
		char ch = getchar();
		for(i = 0; i < n; i++)
		{
			gets(str);
			printf("%d\n", LongPalSubStr(str, pRadus));
		}
	}
	return 0;
}
