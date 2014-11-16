#include<stdio.h>
int sum;
int tempSum;
#define WIDTH 8
#define HEIGHT 8
int area[WIDTH][HEIGHT];
void search(int xpos, int ypos)
{
	tempSum += area[xpos][ypos];
	if(xpos == WIDTH - 1 && ypos == HEIGHT - 1)
	{
		if(tempSum > sum)
		{
			sum = tempSum;
		}
	}
	else if(xpos == WIDTH - 1)
	{
		search(xpos, ypos + 1);
	}
	else if(ypos == HEIGHT - 1)
	{
		search(xpos + 1, ypos);
	}
	else
	{
		search(xpos + 1, ypos);
		search(xpos, ypos + 1);
	}
	tempSum -= area[xpos][ypos];
}
int main()
{
	int i = 0;
	int j = 0;
	int quit = 0;
	for(;;)
	{
		quit = 0;
		sum = 0;
		tempSum = 0;
		for(i = 0; i < WIDTH; i++)
		{
			for(j = 0; j < HEIGHT; j++)
			{
				if(scanf("%d", &area[i][j]) == EOF)
				{
					quit = 1;
					break;
				}
			}
			if(quit == 1)
			{
				break;
			}
		}
		if(quit == 1)
		{
			break;
		}
		search(0, 0);
		printf("%d\n",sum);
	}
}
