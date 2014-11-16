#include<stdio.h>
#include<string.h>
#include<malloc.h>
int subArrayMax(int data[], int length)
{
	int historyMax = 0;
	int currentMax = 0;
	if(data == NULL)
	{
		return 0;
	}
	else
	{
		int i;
		for(i = 0; i < length; i++)
		{
			if(currentMax < 0)
			{
				currentMax = data[i];
			}
			else
			{
				currentMax += data[i];
			}
			if(currentMax > historyMax)
			{
				historyMax = currentMax;
			}
		}
	}
}
