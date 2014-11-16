#include<stdio.h>
#define MAX_LENGTH 1505
#define MIN(a,b) (a) < (b) ? (a) : (b)
int uglyArray[MAX_LENGTH];
void generateUgly()
{
	int index_2 = 2;
	int index_3 = 1;
	int index_5 = 1;
	int index = 5;
	uglyArray[0] = 1;
	uglyArray[1] = 2;
	uglyArray[2] = 3;
	uglyArray[3] = 4;
	uglyArray[4] = 5;
	while(index < MAX_LENGTH)
	{
		int temp_2;
		int temp_3;
		int temp_5;
		int minvalue;
		temp_2 = uglyArray[index_2] * 2;
		temp_3 = uglyArray[index_3] * 3;
		temp_5 = uglyArray[index_5] * 5;
		minvalue = MIN(temp_2, MIN(temp_3, temp_5));
		uglyArray[index] = minvalue;
		if(minvalue == temp_2)
		{
			index_2 ++;
		}
		if(minvalue == temp_3)
		{
			index_3 ++;
		}
		if(minvalue == temp_5)
		{
			index_5 ++;
		}
		index ++;
	}
}

int main()
{
	int index;
	generateUgly();
	while(scanf("%d", &index) != EOF)
	{
		printf("%d\n",uglyArray[index - 1]);
	}
	return 0;
}
