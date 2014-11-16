#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
#define TRUE 1
#define FALSE 0

int checkRowCol(int* pStart, int length, int step)
{
	int j;
	int i;
	for(i = 0, j = 0; j < length; j++, i += step)
	{
		if(pStart[i] != 1)
		{
			return FALSE;
		}
	}
	return TRUE;
}
int findMaxSizeStartPosXY(int startX, int startY, int area[], int width, int height)
{
	int size = 1;
	int i;
	int j;
	int xDirection = 1;
	int yDirection = 1;
	for(i = startX + 1, j = startY + 1; (xDirection == 1 && i < width) || (yDirection == 1 && j < height);)
	{
		int rowCount = 0;
		int colCount = 0;
		if(TRUE == checkRowCol(area + j * width + startX, i - startX, 1))
		{
			rowCount = (i - startX);
		}
		else
		{
			yDirection = 0;
		}
		if(TRUE == checkRowCol(area + startY * width + i, j - startY, width))
		{
			colCount = (j - startY);
		}
		else
		{
			xDirection = 0;
		}
		if(xDirection == 1 && yDirection == 1)
		{
			i++;
			j++;
		}
		else if(xDirection == 1)
		{
			i++;
		}
		else if(yDirection == 1)
		{
			j++;
		}
		else
		{
		}
	}
	return size;
}
int findMaxSize(int area[], int width, int height)
{
	int i;
	int j;
	int maxSize = 0;
	int* pChecked = (int *)malloc(width * height * sizeof(int));
	memset(pChecked, 0, width * height * sizeof(int));
	for(i = 0; i < width; i++)
	{
		for(j = 0; j < height; j++)
		{
			int pos = j * width + i;
			if(pChecked[pos] == 0 && area[pos] == 1)
			{
				int currentSize = findMaxSizeStartPosXY(i, j, area, width, height);
				assert(currentSize >= 1);
				if(currentSize > maxSize)
				{
					maxSize = currentSize;
				}
				pChecked[pos] = 1;
			}
		}
	}
	free(pChecked);
	return maxSize;
}
int main()
{
	int width;
	int height;
	while(scanf("%d %d", &width, &height) != EOF)
	{
		int* area = (int *)malloc(width * height * sizeof(int));
		int i;
		int j;
		for(i = 0; i < width; i++)
		{
			for(j = 0; j < height; j++)
			{
				int pos = j * width + i;
				scanf("%d", &area[pos]);
			}
		}
		//int findMaxSize(int area[], int width, int height)
		printf("%d\n", findMaxSize(area, width, height));
		free(area);
	}
	return 0;
}
