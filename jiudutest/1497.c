#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAXM 1001
#define MAXN 1001
#define MAXLENGTH (MAXM * MAXN)
#define MAXVALUE(a,b) ((a) > (b) ? (a) : (b))
#define SWAP(temp, a, b) do{(temp) = (a); (a) = (b); (b) = (temp);}while(0)
int borderOne[MAXLENGTH];
int borderTwo[MAXLENGTH];
//int border[MAXM][MAXN][MAXM];
int area[MAXM][MAXN];
int rowCount;
int colCount;
int length;

void init()
{
	int i = 0;
	for(i = 0; i < length; i++)
	{
		borderOne[i] = -1;
		borderTwo[i] = -1;
	}
}
int searchCurrentPos(int y, int x)
{
	int i;
	int maxArea = 0;
	int curLength = 0;
	int minLength = MAXN;
	int *border1 = borderOne;
	int *border2 = borderTwo;
	for(i = y; i < rowCount; i++)
	{
		int left = -1;
		int up = -1;
		if(x > 0)
		{
			int pos = (x - 1) * rowCount + i;
			left = border2[pos];
		}
		if(y > 0)
		{
			int pos = x * rowCount + i;
			up = border1[pos];
		}
		int bod = MAXVALUE(left, up);
		if(bod >= x)
		{
			curLength = bod - x + 1;
			int pos = x * rowCount + i;
			border2[pos] = bod;
		}
		else
		{
			//update
			int index;
			for(index = x ; index < colCount; index++)
			{
				if(area[i][index] == 0)
				{
					break;
				}
			}
			curLength = index - x;
			if(curLength == 0)
			{
				break;
			}
			int pos = x * rowCount + i;
			border2[pos] = index - 1;
		}
		if(curLength < minLength)
		{
			minLength = curLength;
		}
		int curArea = minLength * (i - y + 1);
		if(curArea > maxArea)
		{
			maxArea = curArea;
		}
		int* temp = NULL;
		SWAP(temp, border1, border2);
	}
	return maxArea;
}
int findLargestRectangle()
{
	int i;
	int j;
	int maxArea = 0;
	for(i = 0; i < rowCount; i++)
	{
		for(j = 0; j < colCount; j++)
		{
			int curArea = 0;
			if(area[i][j] == 1)
			{
				curArea = searchCurrentPos(i, j);
			}
			if(curArea > maxArea)
			{
				maxArea = curArea;
			}
		}
	}
	return maxArea;
}
int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n) != EOF)
	{
		rowCount = m;
		colCount = n;
		length = rowCount * colCount;
		init();
		int i,j;
		for(i = 0; i < rowCount; i++)
		{
			for(j = 0; j < colCount; j++)
			{
				scanf("%d", &area[i][j]);
			}
		}
		printf("%d\n", findLargestRectangle());
	}
	return 0;
}
