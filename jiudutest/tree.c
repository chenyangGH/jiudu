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
void preVisit(treeNode* pNode)
{
	if(pNode == NULL)
	{
		return;
	}
	else
	{
		printf("%d ", pNode->value);
		preVisit(pNode->left);
		preVisit(pNode->right);
	}
}
void preVisit_v1(treeNode* ptreeRoot)
{
	treeNode** pptreeNode = (treeNode**)malloc(sizeof(treeNode*) * MAXLENGTH);
	if(ptreeRoot == NULL)
	{
		return;
	}
	int top = 0;
	treeNode* pNode = ptreeRoot;

	while(!(top <= 0 && pNode == NULL))
	{
		//assert(top > 0 || pNode != NULL)
		while(pNode != NULL)
		{
			//输出自己
			printf("%d ", pNode->value);
			pptreeNode[top++] = pNode;
			//输出左孩子
			pNode = pNode->left;
		}
		pNode = pptreeNode[--top];
		//输出右孩子
		pNode = pNode->right;
	}
}
void midVisit(treeNode* pTreeNode)
{
	if(pTreeNode == NULL)
	{
		return;
	}
	else
	{
		midVisit(pTreeNode->left);
		printf("%d ", pTreeNode->value);
		midVisit(pTreeNode->right);
	}
}
void midVisit_v1(treeNode* pTreeNode)
{
	treeNode** pptreeNode = (treeNode**)malloc(sizeof(treeNode*) * MAXLENGTH);
	if(pTreeNode == NULL)
	{
		return;
	}
	int top = 0;
	treeNode* pNode = pTreeNode;

	while(top > 0 || pNode != NULL)
	{
		while(pNode != NULL)
		{
			pptreeNode[top++] = pNode;
			pNode = pNode->left;
		}
		pNode = pptreeNode[--top];
		printf("%d ", pNode->value);
		pNode = pNode->right;
	}
}
void postVisit(treeNode* pTreeRoot)
{
	if(pTreeRoot == NULL)
	{
		return;
	}
	else
	{
		postVisit(pTreeRoot->left);
		postVisit(pTreeRoot->right);
		printf("%d ", pTreeRoot->value);
	}
}
void postVisit_v1(treeNode* pTreeNode)
{
	treeNode** pptreeNode = (treeNode**)malloc(sizeof(treeNode*) * MAXLENGTH);
	if(pTreeNode == NULL)
	{
		return;
	}
	int top = 0;
	treeNode* pCurNode = pTreeNode;
	treeNode* pPreNode = NULL;
	pptreeNode[top++] = pTreeNode;
	while(top > 0)
	{
		pCurNode = pptreeNode[top - 1];
		if((pCurNode->left == NULL && pCurNode->right == NULL) || pPreNode != NULL && (pPreNode == pCurNode->left || pPreNode == pCurNode->right))
		{
			printf("%d ", pCurNode->value);
			top--;
			pPreNode = pCurNode;
		}
		else
		{
			if(pCurNode->right != NULL)
			{
				pptreeNode[top++] = pCurNode->right;
			}
			if(pCurNode->left != NULL)
			{
				pptreeNode[top++] = pCurNode->left;
			}
		}
	}
}
void postVisit_v2(treeNode* pTreeNode)
{
	treeNode** pptreeNode = (treeNode**)malloc(sizeof(treeNode*) * MAXLENGTH);
	if(pTreeNode == NULL)
	{
		return;
	}
	int top = 0;
	treeNode* pNode = pTreeNode;
	pptreeNode[top++] = pNode;
	while(top > 0)
	{
		pNode = pptreeNode[top - 1];
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
					pptreeNode[top++] = pNode->right;
				}
				if(pNode->left != NULL)
				{
					pptreeNode[top++] = pNode->left;
				}
			}
		}
	}
}


int main()
{
	treeNode* pTreeRoot = NULL;
	pTreeRoot = preCreate();
	preVisit(pTreeRoot);
	printf("\n");
	preVisit_v1(pTreeRoot);
	printf("\n");
	midVisit(pTreeRoot);
	printf("\n");
	midVisit_v1(pTreeRoot);
	printf("\n");
	
	postVisit(pTreeRoot);
	printf("\n");
	postVisit_v1(pTreeRoot);
	printf("\n");

	postVisit_v2(pTreeRoot);
	printf("\n");
	return 0;
}
