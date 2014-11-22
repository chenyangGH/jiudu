/*题目描述：
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 * 要求不能创建任何新的结点，只能调整树中结点指针的指向。
 * 输入：
 * 输入可能包含多个测试样例。
 * 对于每个测试案例，输入的第一行为一个数n(0<n<1000)，代表测试样例的个数。
 * 接下来的n行，每行为一个二叉搜索树的先序遍历序列，其中左右子树若为空则用0代替。
 * 输出：
 * 对应每个测试案例，
 * 输出将二叉搜索树转换成排序的双向链表后，从链表头至链表尾的遍历结果。
 * 样例输入：
 * 1
 * 2 1 0 0 3 0 0
 * 样例输出：
 * 1 2 3
 * */
/*resolution:
 * this problem can be solved by Midorder binary tree
 * after transform,left pointer become prev pointer,right pointer become
 * next pointer.
 *      a                            a
 *     / \                          / \
 *     b c                          b c
 * left(a) == b,right(a) == c;==>   prev(a) == b,next(a) == c
 * */
#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct node treenode;
struct node
{
		int value;
		treenode* left;
		treenode* right;
};
void create(treenode** proot)
{
		int i = 0;
		if(scanf("%d",&i) == EOF)
		{
				return;
		}
		if(i == 0)
		{
				*proot = NULL;
		}
		else
		{
				*proot = (treenode*)malloc(sizeof(treenode));
				(*proot)->value = i;
				create(&((*proot)->left));
				create(&((*proot)->right));
		}
}
void treetolink(treenode* ptreeroot, treenode** ppre, treenode** plisthead)
{
		if(ptreeroot == NULL)
				return;
		treetolink(ptreeroot->left, ppre, plisthead);
		if(*plisthead == NULL)
		{
				*plisthead = ptreeroot;
		}
		if(*ppre != NULL)
		{
				(*ppre)->right = ptreeroot;
				ptreeroot->left = *ppre;
		}
		*ppre = ptreeroot;
		treetolink(ptreeroot->right, ppre, plisthead);
}
int main()
{
		int count = 0;
		int i = 0;
		int j = 0;
		treenode* proot = NULL;
		treenode* plist = NULL;
		treenode* ppre = NULL;
		treenode* ptemp = NULL;
		while(scanf("%d",&count) != EOF)
		{
				for(i = 0; i < count; i++)
				{
						plist = NULL;
						ppre  = NULL;
						plist = NULL;
						create(&proot);
						treetolink(proot, &ppre, &plist);
						ptemp = plist;
						while(ptemp != NULL)
						{
								printf("%d", ptemp->value);
								printf(" ");
								ptemp = ptemp->right;
						}
						if(plist == NULL)
						{
								continue;
						}
						printf("\n");
						ptemp = plist;
						while(plist->right != NULL)
						{
								ptemp = plist->right;
								plist->right = ptemp->right;
								free(ptemp);
						}
						free(plist);
				}
		}
		return 0;
}
