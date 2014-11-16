#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct Node listNode;
struct Node
{
	int pre;
	int next;
};
int lastNum(listNode list[], int length, int m)
{
	if(list == NULL || m <= 0)
	{
		return -1;
	}
	int curIndex = 0;
	int nextIndex = 0;
	int j;
	while(!(list[nextIndex].pre == nextIndex && list[nextIndex].next == nextIndex))
	{
		for(j = 0; j < m; j++)
		{
			curIndex = nextIndex;
			nextIndex = list[curIndex].next;
		}
		list[list[curIndex].pre].next = nextIndex; 
		list[nextIndex].pre = list[curIndex].pre;
	}
	return nextIndex;
}
int main()
{
	int length;
	int m;
	while(scanf("%d %d",&length, &m) != EOF && length != 0)
	{
		listNode* plist = (listNode*)malloc(sizeof(listNode) * length);
		plist[0].pre = length - 1;
		plist[0].next = 1;
		plist[length - 1].pre = (length - 2 + length) % length;
		plist[length - 1].next = 0;
		int i;
		for(i = 1; i < length - 1; i++)
		{
			plist[i].pre = i - 1;
			plist[i].next = i + 1;
		}
		printf("%d\n", lastNum(plist, length, m) + 1);
		free(plist);
	}
	return 0;
}
