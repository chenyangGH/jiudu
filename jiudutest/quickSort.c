#include<stdio.h>
#define SWAP(a, b, temp) do{		\
				(temp) = (a);	\
				(a)    = (b);	\
				(b)    = (temp);\
			}while(0)
int partition(int data[], int low, int high)
{
	int i = low;
	int j = low + 1;
	int temp;
	for(; j <= high; j++)
	{
		if(data[j] < data[low])
		{
			i++;
			SWAP(data[i], data[j], temp);
		}
	}
	SWAP(data[low], data[i], temp);
	return i;
}
int partition_v1(int data[], int low, int high)
{
	int i = low;
	int j = high + 1;
	int temp;
	while(1)
	{
		do
		{
			i++;
		}while(i <= high && data[i] < data[low]);
		do
		{
			j--;
		}while(data[j] > data[low]);
		if(i > j)
		{
			break;
		}
		SWAP(data[i], data[j], temp);
	}
	SWAP(data[low], data[j], temp);
	return j;
}
void quickSort(int data[], int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = partition_v1(data, low, high);
		quickSort(data, low, mid - 1);
		quickSort(data, mid + 1, high);
	}
}
int main()
{
	int data[1000];
	int i;
	for(i = 0; scanf("%d",&data[i]) != EOF && i < 1000; i++)
	{
		if(data[i] == -1)
			break;
	}
	quickSort(data, 0, i - 1);
	int j;
	for(j = 0; j < i; j++)
	{
		printf("%d ", data[j]);
	}
	printf("\n");
	return 0;
}
