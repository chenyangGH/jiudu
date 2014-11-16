#include<stdio.h>
int add(int op1, int op2)
{
	if(op2 == 0)
	{
		return op1;
	}
	return add((op1 ^ op2), (op1 & op2) << 1);
}
int main()
{
	int op1, op2;
	while(scanf("%d %d", &op1, &op2) != EOF)
	{
		printf("%d\n", add(op1, op2));
	}
}
