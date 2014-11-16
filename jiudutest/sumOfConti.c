#include<stdio.h>
void findRange(int sum, int* low, int* high)
{
	if(sum <= 2)
	{
		*low = 0;
		*high = 0;
		return;
	}
	int lowIndex = *low;
	int highIndex = *high;
	int i = 0;
	int currentSum = 0;
	for(i = lowIndex; i <= highIndex; i++)
	{
		currentSum += i;
	}
	while(lowIndex < highIndex)
	{
		if(currentSum == sum)
		{
			break;
		}
		else if(currentSum < sum)
		{
			highIndex++;
			currentSum += highIndex;
		}
		else
		{
			currentSum -= lowIndex;
			lowIndex++;
		}
	}
	*low = lowIndex;
	*high = highIndex;
}
int main()
{
	int sum;
	scanf("%d", &sum);
	while(sum >= 0)
	{
		int low = 1;
		int high = 2;
		findRange(sum, &low, &high);
		if(low == high)
		{
			printf("Pity!\n");
		}
		else
		{
			int i;
			for(i = low; i <= high; i++)
			{
				if(i != low)
				{
					printf(" ");
				}
				printf("%d", i);
			}
			printf("\n");
			while(low < high)
			{
				low++;
				if(low == high)
					break;
				findRange(sum, &low, &high);
				if(low < high)
				{
					int i;
					for(i = low; i <= high; i++)
					{
						if(i != low)
						{
							printf(" ");
						}
						printf("%d", i);
					}
					printf("\n");
				}
			}
		}
		printf("#\n");
		scanf("%d", &sum);
	}
	return 0;
}
