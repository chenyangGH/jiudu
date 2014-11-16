#include<stdio.h>
#include<string.h>
#include<malloc.h>
int IsJunko(int array[], int length)
{
	int i = 0;
	int temp;
	for(i = 0; i < length - 1; i++)
	{
		int j = i + 1;
		if(array[j] < array[i])
		{
			int k = j;
			temp = array[j];
			for(k = j - 1; k >= 0 && array[k] > temp; k--)
			{
				array[k + 1] = array[k];
			}
			array[k + 1] = temp;
		}
	}

	int sup = 0;
	int gap = 0;
	for(i = 0; i < length; i++)
	{
		if(array[i] == 0)
		{
			sup += 1;
		}
		else
		{
			if(i > 0 && array[i - 1] != 0)
			{
				int dif = array[i] - array[i - 1];
				if(dif == 0)
				{
					return 0;
				}
				gap += (dif - 1);
			}
		}
	}
	if(sup >= gap)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
		{
			break;
		}
		int* pnum = (int*)malloc(sizeof(int) * n);
		int i;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &pnum[i]);
		}
		if(1 == IsJunko(pnum, n))
		{
			printf("So Lucky!\n");
		}
		else
		{
			printf("Oh My God!\n");
		}
		free(pnum);
	}
	return 0;
}
