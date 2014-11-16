/*
 * allCombination and arrangement
 * chenyang
 * 2014-07-08
 */
/*
 * sample
 * 1 2 3 4
 * 1 2 4 3
 * 1 3 2 4
 * 1 3 4 2
 * 1 4 2 3
 * 1 4 3 2
 * 2 1 3 4
 * 2 1 4 3
 * 2 3 1 4
 * 2 3 4 1
 * 2 4 1 3
 * 2 4 3 1
 * 3 1 2 4
 * 3 1 4 2
 * 3 2 1 4
 * 3 2 4 1
 * 3 4 1 2
 * 3 4 2 1
 * 4 1 2 3
 * 4 1 3 2
 * 4 2 1 3
 * 4 2 3 1
 * 4 3 1 2
 * 4 3 2 1
 */
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define SWAP(a, b, temp) do{                      \
				(temp) = (a);     \
				(a)    = (b);     \
				(b)    = (temp);  \
				}while(0)
int partition(char* str, int low, int high)
{
	int i = low;
	int j = high + 1;
	int temp;
	for(;;)
	{
		do
		{
			i++;
		}while(i <= high && str[i] < str[low]);
		do
		{
			j--;
		}while(str[j] > str[low]);
		if(i > j)
		{
			break;
		}
		SWAP(str[i], str[j], temp);
	}
	SWAP(str[j], str[low], temp);
	return j;
}
void quick_sort(char* str, int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = partition(str, low, high);
		quick_sort(str, low, mid - 1);
		quick_sort(str, mid + 1, high);
	}
}
void reverse(char* str, int low, int high)
{
	char temp;
	while(low < high)
	{
		SWAP(str[low], str[high], temp);
		low++;
		high--;
	}
}
void arrange(char* str)
{
	//sort(str);
	int count = 0;
	if(str == NULL)
	{
		return;
	}
	char temp;
	int length = strlen(str);
	quick_sort(str, 0, length - 1);
	int i;
	for(;;)
	{
		count++;
		printf("%s\n", str);
		//注意<=与<的区别,重复字符的情况
		for(i = length - 2; i >= 0 && str[i] >= str[i + 1]; i--);
		if(i == -1)
		{
			break;
		}
		else if(i == length - 2)
		{
			SWAP(str[i], str[i + 1], temp);
		}
		else
		{
			int j = length - 1;
			//注意<=与<的区别,重复字符的情况
			while(str[j--] <= str[i]);
			j++;
			SWAP(str[i], str[j], temp);
			reverse(str, i + 1, length - 1);
		}
	}
	printf("arrange count is %d\n", count);
}
void print(char array[], int length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		if(array[i] == 1)
		{
			printf("%c ", 'a' + i);
		}
	}
	printf("\n");
}
void combination(int n, int m)
{
	char* pArray = (char*)malloc(sizeof(char) * n);
	int count = 0;
	int i = 0;
	for(i = 0; i < n - m; i++)
	{
		pArray[i] = 0;
	}
	for(i = n - m; i < n; i++)
	{
		pArray[i] = 1;
	}
	char temp;
	for(;;)
	{
		count++;
		print(pArray, n);
		//注意<=与<的区别,重复字符的情况
		for(i = n - 2; i >= 0 && pArray[i] >= pArray[i + 1]; i--);
		if(i == -1)
		{
			break;
		}
		else if(i == n - 2)
		{
			SWAP(pArray[i], pArray[i + 1], temp);
		}
		else
		{
			int j = n - 1;
			//注意<=与<的区别,重复字符的情况
			while(pArray[j--] <= pArray[i]);
			j++;
			SWAP(pArray[i], pArray[j], temp);
			reverse(pArray, i + 1, n - 1);
		}
	}
}
void allCombination(int n)
{
	int i = 1;
	for(i = 1; i <= n; i++)
	{
		combination(n, i);
	}
}
int main()
{
	/*
	char str[1000];
	while(scanf("%s", str) != EOF)
	{
		arrange(str);
	}
	*/
	int n;
	while((scanf("%d", &n) != EOF) && n >= 1)
	{
		allCombination(n);
	}
	return 0;
}
