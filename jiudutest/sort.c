#include<stdio.h>
#define SWAP(a,b,c)     do{                   \
				(c) = (a);    \
				(a) = (b);    \
				(b) = (c);    \
			}while(0)
void insertSort(int data[], int length)
{
	int i;
	int j;
	int temp;
	printf("do insertion sort\n");
	for(i = 0; i < length - 1; i++)
	{
		if(data[i] > data[i + 1])
		{
			temp = data[i + 1];
			for(j = i; j >= 0 && data[j] > temp; j--)
			{
				data[j + 1] = data[j];
			}
			data[j + 1] = temp;
		}
	}
}
void merge(int data[], int low, int high, int tempData[])
{
	int mid = low + (high - low) / 2;
	int i = 0;
	int j;
	int k;
	for(i = low; i <= high; i++)
	{
		tempData[i] = data[i];
	}
	for(k = low, i = low, j = mid + 1; i <= mid && j <= high;)
	{
		if(tempData[i] < tempData[j])
		{
			data[k++] = tempData[i++];
		}
		else
		{
			data[k++] = tempData[j++];
		}
	}
	while(i <= mid)
	{
		data[k++] = tempData[i++];
	}
	while(j <= high)
	{
		data[k++] = tempData[j++];
	}
}
void mergeSort(int data[], int low, int high, int tempData[])
{
	int mid;
	if(low < high)
	{
		mid = low + (high - low) / 2;
		mergeSort(data, low, mid, tempData);
		mergeSort(data, mid + 1, high, tempData);
		merge(data, low, high, tempData);
	}
}

void shellSort(int data[], int length)
{
	int step;
	int i;
	int j;
	int temp;
	printf("do shellSort\n");
	for(step = length >> 1; step >= 1; step >>= 1)
	{
		for(i = 0; i < length - step; i++)
		{
			if(data[i] > data[i + step])
			{
				temp = data[i + step];
				for(j = i; j >= 0 && data[j] > temp; j -= step)
				{
					data[j + step] = data[j];
				}
				data[j + step] = temp;
			}
		}
	}
}

void bubbleSort(int data[], int length)
{
	int i;
	int j;
	int temp;
	printf("do bubbleSort\n");
	for(i = 0; i < length - 1; i++)
	{
		for(j = 0; j < length - 1 - i; j++)
		{
			if(data[j] > data[j + 1])
			{
				SWAP(data[j], data[j + 1], temp);
			}
		}
	}
}
void selectSort(int data[], int length)
{
	int i;
	int j;
	printf("do selectSort\n");
	for(i = 0; i < length - 1; i++)
	{
		int minIndex = i;
		for(j = i; j < length; j++)
		{
			if(data[j] < data[minIndex])
			{
				minIndex = j;
			}
		}
		int temp;
		SWAP(data[i], data[minIndex], temp);
	}
}
void adjust(int data[], int curIndex, int lastIndex)
{
	int temp = data[curIndex - 1];
	while(curIndex << 1 <= lastIndex)
	{
		int index = curIndex << 1;
		if(index + 1 <= lastIndex && data[index - 1] > data[index + 1 - 1])
		{
			index++;
		}
		if(data[index - 1] < temp)
		{
			data[curIndex - 1] = data[index - 1];
		}
		else
		{
			break;
		}
		curIndex = index;
	}
	data[curIndex - 1] = temp;
}
void heapSort(int data[], int length)
{
	int i = 0;
	int temp;
	for(i = length >> 1; i >= 1; i--)
	{
		adjust(data, i, length);
	}
	for(i = length - 1; i >= 1; i--)
	{
		SWAP(data[0], data[i], temp);
		adjust(data, 1, i);
	}
}
int main()
{
	int data[1000];
	int tempData[1000];
	int length;
	while(scanf("%d", &length) != EOF && length >= 1)
	{
		int i = 0;
		for(i = 0; i < length; i++)
		{
			scanf("%d",&data[i]);
		}
		//insertSort(data, length);
		//mergeSort(data, 0, length - 1, tempData);
		//shellSort(data, length);
		//bubbleSort(data, length);
		//selectSort(data, length);
		heapSort(data, length);
		for(i = 0; i < length; i++)
		{
			printf("%d ", data[i]);
		}
	}
	return 0;
}
