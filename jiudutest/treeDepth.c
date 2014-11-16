#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct node treeNode;
struct node
{
	int value;
	int left;
	int right;
};
int depth(treeNode* pNodeList, int index)
{
	if(index == -1 || pNodeList == NULL)
		return 0;
	else
	{
		int leftDepth = depth(pNodeList, pNodeList[index].left);
		int rightDepth = depth(pNodeList, pNodeList[index].right);
		return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
	}
}
int main()
{
	int length;
	while(scanf("%d", &length) != EOF)
	{
		treeNode* pNodeList = (treeNode*)malloc(sizeof(treeNode) * (1 + length));
		int i;
		for(i = 1; i < length + 1; i++)
		{
			int left,right;
			scanf("%d %d",&left, &right);
			pNodeList[i].left = left;
			pNodeList[i].right = right;
		}
		printf("%d\n",depth(pNodeList, 1));
	}
	return 0;
}
