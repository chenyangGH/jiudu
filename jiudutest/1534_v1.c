#include<stdio.h>
#define MAXSIZE 100001
typedef unsigned long long ull;
ull array1[MAXSIZE];
ull array2[MAXSIZE];
int length1;
int length2;
#define MAXNUM 1000000000
int cmp(const void* p, const void* q)
{
	return *((ull*)p) - *((ull*)q);
}
ull findIdx(ull a[], ull b[], int la, int lb, ull value)
{
	int i;
	ull idx = 0;
	for(i = 0; i < la; i++)
	{
		if(a[i] + b[0] > value)
			break;
		else if(a[i] + b[lb - 1] < value)
		{
			idx += lb;
		}
		else
		{
			int low = 0;
			int high = lb;
			while((high - low) > 1)
			{
				int mid = (high - low) / 2 + low;
				if(a[i] + b[mid] <= value)
				{
					low = mid;
				}
				else
				{
					high = mid;
				}
			}
			idx += (low + 1);
		}
	}
	return idx;
}
ull find(ull k)
{
	ull low = array1[0] + array2[0];
	ull high = array1[length1 - 1] + array2[length2 - 1];
	ull ans = 0;
	while(low <= high)
	{
		ull mid = low + (high - low) / 2;
		if(k <= findIdx(array1, array2, length1, length2, mid))
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return ans;
}
int main()
{
	ull k;
	while(scanf("%d %d %lld", &length1, &length2, &k) != EOF)
	{
		int i;
		for(i = 0; i < length1; i++)
		{
			scanf("%lld", &array1[i]);
		}
		for(i = 0; i < length2; i++)
		{
			scanf("%lld", &array2[i]);
		}
		qsort(array1, length1, sizeof(ull), cmp);
		qsort(array2, length2, sizeof(ull), cmp);
		printf("%lld\n",find(k));
	}
	return 0;
}
