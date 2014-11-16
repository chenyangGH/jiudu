#include<stdio.h>
#define SIZE 100001
int length1;
int length2;
int array1[SIZE];
int array2[SIZE];
typedef struct mypos Mypos;
struct mypos
{
	int x;
	int y;
};
Mypos bSearch(int a[], int la, int ha, int b[], int lb, int hb, int value)
{
	while((ha - la > 1) || (hb - lb > 1))
	{
		int mida = la + (ha - la) / 2;
		int midb = lb + (hb - lb) / 2;
		if(a[mida] + b[midb] <= value)
		{
			la = mida;
			lb = midb;
		}
		else
		{
			ha = mida;
			hb = midb;
		}
	}
	Mypos myp;
	if((ha - la == 1) && (hb - lb == 1))
	{
		if(value >= a[ha] + b[lb] && value >= a[la] + b[hb])
		{
			if((a[ha] + b[lb]) > (a[la] + b[hb]))
			{
				myp.x = ha;
				myp.y = lb;
			}
			else
			{
				myp.x = la;
				myp.y = hb;
			}
		}
		else if(value >= a[ha] + b[lb])
		{
			myp.x = ha;
			myp.y = lb;
		}
		else if(value >= a[la] + b[hb])
		{
			myp.x = la;
			myp.y = hb;
		}
		else
		{
			myp.x = la;
			myp.y = lb;
		}
	}
	else
	{
		myp.x = la;
		myp.y = lb;
	}
	return myp;
}
int posOfSumArray(int idx1, int idx2)
{
	int pp = idx1 * idx2;
	Mypos pp1 = bSearch(array1, 0, idx1 + 1, array2, idx2, length2, array1[idx1] + array2[idx2]);
	printf("pp1.x is %d, pp1.y is %d\n", pp1.x, pp1.y);
	Mypos pp2 = bSearch(array1, idx1, length1, array2, 0, idx2 + 1, array1[idx1] + array2[idx2]);
	printf("pp2.x is %d, pp2.y is %d\n", pp2.x, pp2.y);
	pp += (pp1.x + 1) * (pp1.y - idx2 + 1);
	pp += (pp2.y + 1) * (pp2.x - idx1 + 1);
	return pp;
}
int findKthNum(int k)
{
	int la = 0;
	int lb = 0;
	int ha = length1;
	int hb = length2;
	while((ha - la > 1) || (hb - lb > 1))
	{
		int ma = la + (ha - la) / 2;
		int mb = lb + (hb - lb) / 2;
		int index = posOfSumArray(ma, mb);
		printf("%d of array1 + %d of array2 is the %dth num of c\n", ma, mb, index);
		if(index <= k)
		{
			la = ma;
			lb = mb;
		}
		else
		{
			ha = ma;
			hb = mb;
		}
	}
	printf("go out of while, la is %d ha is %d lb is %d hb is %d\n",la,ha,lb,hb);
	if((ha - la == 1) && (hb - lb == 1))
	{
			printf("%d of array1 + %d of array2 is the %dth num of c\n", la, lb, posOfSumArray(la, lb));
			printf("%d of array1 + %d of array2 is the %dth num of c\n", la, hb, posOfSumArray(la, hb));
			printf("%d of array1 + %d of array2 is the %dth num of c\n", ha, lb, posOfSumArray(ha, lb));
		if(posOfSumArray(la, lb) == k)
		{
			return array1[la] + array2[lb];
		}
		else if(posOfSumArray(la, hb) == k)
		{
			return array1[la] + array2[hb];
		}
		else if(posOfSumArray(ha, lb) == k)
		{
			return array1[ha] + array2[lb];
		}
		else
		{
			return -1;
		}
	}
	else
	{
		printf("%d of array1 + %d of array2 is the %dth num of c\n", la, lb, posOfSumArray(la, lb));
		if(posOfSumArray(la, lb) == k)
		{
			return array1[la] + array2[lb];
		}
		else
		{
			return -1;
		}
	}
}
int main()
{
	int k;
	while(scanf("%d %d %d",&length1, &length2, &k) != EOF)
	{
		int i = 0;
		for(i = 0; i < length1; i++)
		{
			scanf("%d", &array1[i]);
		}
		for(i = 0; i < length2; i++)
		{
			scanf("%d", &array2[i]);
		}
		printf("%d\n", findKthNum(k));
	}
	return 0;
}
