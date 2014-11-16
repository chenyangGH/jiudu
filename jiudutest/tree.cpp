#include<stdio.h>
#include<stack>
#include<string.h>
#define SIZE 1000
using std::stack;
int left[SIZE];
int right[SIZE];
int createTree()
{
		int index;
		scanf("%d",&index);
		if(index == -1)
		{
				return -1;
		}
		left[index] = createTree();
		right[index] = createTree();
		return index;
}
void prior_s(int root)
{
		if(root == -1)
		{
				return;
		}
		stack<int> nodes;
		nodes.push(root);
		while(!nodes.empty())
		{
				int root = nodes.top();
				nodes.pop();
				printf("%d\n", root);
				if(right[root] != -1)
				{
						nodes.push(right[root]);
				}
				if(left[root] != -1)
				{
						nodes.push(left[root]);
				}
		}
}
void prior(int root)
{
		if(root == -1)
		{
				return;
		}
		printf("%d\n", root);
		prior(left[root]);
		prior(right[root]);
}

/*
void middle_s(int root)
{
		if(root == -1)
		{
				return;
		}
		stack<int> nodes;
		nodes.push(root);
		int lastOutput = root;
		while(!nodes.empty())
		{
				root = nodes.top();
				nodes.pop();
				if((left[root] == -1) && (right[root] == -1))
				{
						lastOutput = root;
						printf("%d\n", root);
				}
				else if(left[root] == lastOutput)
				{
						lastOutput = root;
						printf("%d\n", root);
				}
				else
				{
						if(right[root] != -1)
						{
								nodes.push(right[root]);
						}
						nodes.push(root);
						if(left[root] != -1)
						{
								nodes.push(left[root]);
						}
				}
		}
}
*/
void middle_s(int root)
{
		if(root == -1)
		{
				return;
		}
		stack<int> nodes;
		nodes.push(root);
		while(!nodes.empty())
		{
				int root = nodes.top();
				while(left[root] != -1)
				{
						root = left[root];
						nodes.push(root);
				}
				nodes.pop();
				printf("%d\n", root);
				root = nodes.top();
				while(!nodes.empty() && right[root] == -1)
				{
						printf("%d\n", root);
						root = nodes.top();
						nodes.pop();
				}
				if(right[root] != -1)
				{
						nodes.push(right[root]);
				}
		}
}
void middle(int root)
{
		if(root == -1)
		{
				return;
		}
		middle(left[root]);
		printf("%d\n", root);
		middle(right[root]);
}
void back_s(int root)
{
		if(root == -1)
		{
				return;
		}
		stack<int> nodes;
		nodes.push(root);
		int lastOutput = root;
		while(!nodes.empty())
		{
				root = nodes.top();
				if((left[root] == -1) && (right[root] == -1))
				{
						lastOutput = root;
						printf("%d\n", root);
						nodes.pop();
				}
				else if((left[root] == lastOutput) || (right[root] == lastOutput))
				{
						lastOutput = root;
						printf("%d\n", root);
						nodes.pop();
				}
				else
				{
						if(right[root] != -1)
						{
								nodes.push(right[root]);
						}
						if(left[root] != -1)
						{
								nodes.push(left[root]);
						}
				}
		}
}
void back(int root)
{
		if(root == -1)
		{
				return;
		}
		back(left[root]);
		back(right[root]);
		printf("%d\n",root);
}
int main()
{
		int i;
		memset(left, -1, sizeof(left));
		memset(right, -1, sizeof(right));
		int root = createTree();
		printf("prior---------------\n");
		prior_s(root);
		printf("middle---------------\n");
		middle_s(root);
		printf("back---------------\n");
		back_s(root);
		return 0;
}
