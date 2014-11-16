#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct treeNode trieTreeNode;
struct treeNode
{
	int count;
	trieTreeNode* next[26];
};

trieTreeNode* createTree()
{
	trieTreeNode* pNode = (trieTreeNode*)malloc(sizeof(trieTreeNode));
	pNode->count = 0;
	int i = 0;
	for(i = 0; i < 26; i++)
	{
		(pNode->next)[i] = NULL;
	}
	return pNode;
}

void addWord(char* pWord, trieTreeNode* pNode)
{
	if(*pWord == '\0')
	{
		return;
	}
	int index = *pWord - 'a';
	if((pNode->next)[index] == NULL)
	{
		(pNode->next)[index] = createTree();
	}
	((pNode->next)[index])->count += 1;
	addWord(pWord + 1, (pNode->next)[index]);
}
void numOfWordStartFromInput(trieTreeNode* pNode, char* pWord, int* num)
{
	if(*pWord == '\0')
	{
		return;
	}
	int index = *pWord - 'a';
	if(pNode->next[index] == NULL)
	{
		*num = 0;
	}
	else
	{
		*num = (pNode->next[index])->count;
		numOfWordStartFromInput(pNode->next[index], pWord + 1, num);
	}
}
int main()
{
	int n, m;
	char input[30];
	while(scanf("%d", &n) != EOF)
	{
		int count = 0;
		trieTreeNode* pRoot = createTree();
		int i;
		char ch;
		ch = getchar();
		for(i = 0; i < n; i++)
		{
			gets(input);
			addWord(input, pRoot);
		}
		scanf("%d", &m);
		ch = getchar();
		for(i = 0; i < m; i++)
		{
			gets(input);
			numOfWordStartFromInput(pRoot, input, &count);
			printf("%d\n", count);
		}
	}
	return 0;
}
