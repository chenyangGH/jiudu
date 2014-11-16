#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define SWAP(a,b,temp)	do{  		       	 \
				(temp) = (a);    \
				(a)    = (b);    \
				(b)    = (temp); \
			}while(0)
int partition(char** psuffixArray, int low, int high)
{
	int i = low;
	int j = high + 1;
	char* tem = NULL;
	while(1)
	{
		do
		{
			i++;
		}while(i <= high && strcmp(psuffixArray[i], psuffixArray[low]) < 0);
		do
		{
			j--;
		}while(strcmp(psuffixArray[j], psuffixArray[low]) > 0);
		if(i > j)
		{
			break;
		}
		SWAP(psuffixArray[i], psuffixArray[j], tem);
	}
	SWAP(psuffixArray[j], psuffixArray[low], tem);
	return j;
	
}
void quick_sort(char** psuffixArray, int low, int high)
{
	if(low < high)
	{
		int mid = partition(psuffixArray, low, high);
		quick_sort(psuffixArray, low, mid - 1);
		quick_sort(psuffixArray, mid + 1, high);
	}
}

int maxComLengthOfTwo(char *pstr1, char *pstr2)
{
	int comLen = 0;
	int count = 0;
	for(; *pstr1 != '\0' && *pstr2 != '\0'; pstr1++, pstr2++)
	{
		if(*pstr1 == *pstr2)
		{
			//不会出现两个'#'相等的情况
			comLen ++;
		}
		else
		{
			break;
		}
	}
	for(; *pstr1 != '\0'; pstr1++)
	{
		if(*pstr1 == '#')
		{
			count++;
		}
	}
	for(; *pstr2 != '\0'; pstr2++)
	{
		if(*pstr2 == '#')
		{
			count++;
		}
	}
	if(count == 1)
	{
		return comLen;
	}
	else
	{
		return 0;
	}
}

int longComSubStr(char *pStr1, char *pStr2)
{
	int length1 = strlen(pStr1);
	int length2 = strlen(pStr2);
	if(length1 <= 0 || length2 <= 0)
	{
		return 0;
	}
	char* pStr = (char*)malloc(sizeof(char) * (length1 + length2 + 2));
	char** ppStr = (char**)malloc(sizeof(char*) * (length1 + length2));
	strcpy(pStr, pStr1);
	pStr[length1] = '#';
	strcpy((pStr + length1 + 1), pStr2);
	printf("%s\n", pStr);
	int i = 0;
	for(i = 0; i < length1; i++)
	{
		ppStr[i] = &pStr[i];
	}
	i++;
	for(; i < length1 + length2 + 1; i++)
	{
		ppStr[i - 1] = &pStr[i];
	}
	for(i = 0; i < length1 + length2; i++)
	{
		printf("%s\n", ppStr[i]);
	}
	printf("-------\n");
	quick_sort(ppStr, 0, length1 + length2 - 1);
	for(i = 0; i < length1 + length2; i++)
	{
		printf("%s\n", ppStr[i]);
	}
	int maxLength = 0;
	int curLength = 0;
	for(i = 0; i < length1 + length2 - 1; i++)
	{
		curLength = maxComLengthOfTwo(ppStr[i], ppStr[i + 1]);
		if(curLength > maxLength)
		{
			maxLength = curLength;
		}
	}
	free(pStr);
	free(ppStr);
	return maxLength;
}
int main()
{
	char str1[1000], str2[1000];
	while(gets(str1) != NULL && gets(str2) != NULL)
	{
		printf("%d\n", longComSubStr(str1, str2));
	}
}
