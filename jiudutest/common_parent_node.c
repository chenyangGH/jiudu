#include<stdio.h>
#define MAX_LENGTH 10000
typedef struct node treenode;
struct node
{
	int value;
	treenode* left;
	treenode* right;
};
/*
treenode* createTree(int data[], int* index, int length)
{
	treenode *pTree = NULL;
	if(*index == length)
		return NULL;
	else
	{
		if(data[*index] == 0)
		{
			(*index) += 1;
			return NULL;
		}
		else
		{
			pTree = (treenode*)malloc(sizeof(treenode));
			pTree->value = data[*index];
			(*index) += 1;
			pTree->left = createTree(data,index, length);
			pTree->right = createTree(data,index, length);
		}
		return pTree;
	}
}
*/
treenode* createTree()
{
	treenode *pTree = NULL;
	int input = 0;
	scanf("%d", &input);
	if(0 == input)
	{
		return NULL;
	}
	else
	{
		pTree = (treenode*)malloc(sizeof(treenode));
		pTree->value = input;
		pTree->left = createTree();
		pTree->right = createTree();
	}
	return pTree;
}

int findPath(treenode* pTreeNode, treenode** pPath, int* top, int value)
{
	if(pTreeNode == NULL)
		return 0;
	else
	{
		pPath[*top] = pTreeNode;
		if(value == pTreeNode->value)
		{
			return 1;
		}
		*top += 1;
		if(1 == findPath(pTreeNode->left, pPath, top, value))
		{
			return 1;
		}
		if(1 == findPath(pTreeNode->right, pPath, top, value))
		{
			return 1;
		}
		*top -= 1;
		return 0;
	}
}
treenode* getLastCommon(treenode** pPath1, treenode** pPath2, int length)
{
	int index = 0;
	if(pPath1 == NULL || pPath2 == NULL)
	{
		return NULL;
	}
	for(index == 0; index < length; index++)
	{
		if(pPath1[index] != pPath2[index])
		{
			break;
		}
		if(pPath1[index] == NULL && pPath2[index] == NULL)
		{
			break;
		}
	}
	if(index == 0)
		return NULL;
	else
		return pPath1[index - 1];
}
int main()
{
	int testTimes = 0;
	int time = 0;
	int index = 0;
	int length = 0;
	char ch;
	int data[MAX_LENGTH];
	int value1 = 0;
	int value2 = 0;
	treenode* pTreeRoot = NULL;
	treenode* pPath1[MAX_LENGTH];
	treenode* pPath2[MAX_LENGTH];
	treenode*  pParent;
	int top1;
	int top2;
	scanf("%d", &testTimes);
	while(time++ < testTimes)
	{
		index = 0;
		length = 0;
		top1 = 0;
		top2 = 0;
		pParent = NULL;
		pTreeRoot = createTree();
		scanf("%d %d",&value1, &value2);
		int i;
		for(i = 0; i < MAX_LENGTH; i++)
		{
			pPath1[i] = NULL;
			pPath2[i] = NULL;
		}
		if(0 == findPath(pTreeRoot, pPath1, &top1, value1))
		{
			printf("My God\n");
			continue;
		}
		if(0 == findPath(pTreeRoot, pPath2, &top2, value2))
		{
			printf("My God\n");
			continue;
		}
		pParent = getLastCommon(pPath1, pPath2, MAX_LENGTH);
		if(pParent == NULL)
		{
			printf("My God\n");
			continue;
		}
		else
		{
			printf("%d\n", pParent->value);
		}
	}
	return 0;
}
