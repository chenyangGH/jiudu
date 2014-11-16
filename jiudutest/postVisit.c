#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAXLENGTH 100
typedef struct node treeNode;
struct node
{
	treeNode* left;
	treeNode* right;
	int value;
	int first;
};

treeNode* preCreate()
{
	int input;
	scanf("%d", &input);
	if(input == 0)
	{
		return NULL;
	}
	else
	{
		treeNode* pNode = (treeNode*)malloc(sizeof(treeNode));
		pNode->value = input;
		pNode->first = 1;
		pNode->left = preCreate();
		pNode->right = preCreate();
		return pNode;
	}
}
void postVisit(treeNode* pTreeNode)
{
	if(pTreeNode == NULL)
	{
		return;
	}
	else
	{
		postVisit(pTreeNode->left);
		postVisit(pTreeNode->right);
		printf("%d ", pTreeNode->value);
	}
}
void postVisit_v1(treeNode* pTreeNode)
{
	treeNode** ppTreeNodeList = (treeNode**)malloc(MAXLENGTH * sizeof(treeNode*));
	int top = 0;
	if(pTreeNode == NULL)
	{
		return;
	}
	treeNode* pNode = pTreeNode;
	ppTreeNodeList[top++] = pNode;
	while(top > 0)
	{
		pNode = ppTreeNodeList[top - 1];
		if(pNode->first == 0)
		{
			printf("%d ", pNode->value);
			top--;
		}
		else
		{
			pNode->first = 0;
			if(pNode->left == NULL && pNode->right == NULL)
			{
				printf("%d ", pNode->value);
				top--;
			}
			else
			{
				if(pNode->right != NULL)
				{
					ppTreeNodeList[top++] = pNode->right;
				}
				if(pNode->left != NULL)
				{
					ppTreeNodeList[top++] = pNode->left;
				}
			}
		}
	}
}
void postVisit_v2(treeNode* pTreeNode)
{
	treeNode** ppTreeNodeList = (treeNode**)malloc(MAXLENGTH * sizeof(treeNode*));
	treeNode* pPred = NULL;
	int top = 0;
	if(pTreeNode == NULL)
	{
		return;
	}
	treeNode* pNode = pTreeNode;
	ppTreeNodeList[top++] = pNode;
	while(top > 0)
	{
		pNode = ppTreeNodeList[top - 1];
		if(pNode->left == NULL && pNode->right == NULL || (pPred != NULL && (pNode->left == pPred || pNode->right == pPred)))
		{
			printf("%d ", pNode->value);
			top--;
			pPred = pNode;
		}
		else
		{
			if(pNode->right != NULL)
			{
				ppTreeNodeList[top++] = pNode->right;
			}
			if(pNode->left != NULL)
			{
				ppTreeNodeList[top++] = pNode->left;
			}
		}
	}
}
int main()
{
	treeNode* pTreeRoot = NULL;
	pTreeRoot = preCreate();
	
	postVisit(pTreeRoot);
	printf("\n");
	postVisit_v1(pTreeRoot);
	printf("\n");

	postVisit_v2(pTreeRoot);
	printf("\n");
	return 0;
}
