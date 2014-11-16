#include<stdio.h>
#define VALUEAREA 200
#define BITLENGTH 20
double sum[VALUEAREA];
int count[VALUEAREA];
int zero = 100;
double myPow(double base, int mi)
{
	if(mi == 0)
	{
		return 1.0;
	}
	else if(mi == 1)
	{
		return base;
	}
	else
	{
		double res = myPow(base, mi / 2);
		res *= res;
		if((mi & 1) == 1)
		{
			res *= base;
		}
		return res;
	}
}
double doAlterSum(int lowLimit[], int highLimit[], int bitLength, int va)
{
	int i = 0;
	int index = 0;
	for(i = 0; i <= VALUEAREA; i++)
	{
		count[i] = 0;
		sum[i] = 0;
	}
	for(i = lowLimit[index]; i <= highLimit[index]; i++)
	{
		count[i + zero] = 1;
		sum[i + zero] = i * myPow(10, bitLength - index - 1);
	}
	
	for(index = 1; index < bitLength; index++)
	{
		//sub
		if((index & 1) == 1)
		{
			for(i = -9 * (index / 2 + 1); i <= 9 * (index / 2 + 1); i++)
			{
				int j = 0;
				double oldZero = sum[i + zero];
				sum[i + zero] = 0;
		//		int temp = count[i + zero];
		//		count[i + zero] = 0;
				for(j = lowLimit[index]; j <= highLimit[index]; j++)
				{
					int state = 0;
		//			if(j == 0)
		//			{
		//				state = temp;
		//			}
		//			else
		//			{
						state = count[i + j + zero];
		//			}
					if(state == 1)
					{
						count[i + zero] = 1;
						if(j == 0)
						{
							sum[i + zero] += oldZero;
						}
						else
						{
							sum[i + zero] += sum[i + j + zero];
							sum[i + zero] += j * myPow(10, bitLength - index - 1);
						}
					}
				}
			}
		}
		else//add
		{
			for(i = 9 * (index / 2 + 1); i >= -9 * (index / 2); i--)
			{
				int j = 0;
				double oldZero = sum[i + zero];
				sum[i + zero] = 0;
			//	int temp = count[i + zero];
			//	count[i + zero] = 0;
				for(j = lowLimit[index]; j <= highLimit[index]; j++)
				{
					int state = 0;
			//		if(j == 0)
			//		{
			//			state = temp;
			//		}
			//		else
			//		{
						state = count[i - j + zero];
			//		}
					if(state == 1)
					{
						count[i + zero] = 1;
						if(j == 0)
						{
							sum[i + zero] += oldZero;
						}
						else
						{
							sum[i + zero] += sum[i - j + zero]; 
							sum[i + zero] += j * myPow(10, bitLength - index - 1); 
						}
					}
				}
			}
		}
	}
	return sum[va + zero];
}
int getBitLength(int bitArray[], int value)
{
	int length = 0;
	while(value > 0)
	{
		bitArray[length++] = value % 10;
		value /= 10;
	}
	int low = 0;
	int high = length - 1;
	while(low <= high)
	{
		int temp = bitArray[low];
		bitArray[low] = bitArray[high];
		bitArray[high] = temp;
		low++;
		high--;
	}
	return length;
}
double alterSum_v1(int low, int high, int value)
{
	double res;
	double yuzhi = 1000000007.0;
	int bit[20];
	int i;
	for(i = low; i <= high; i++)
	{
		int length = getBitLength(bit, i);
		int r = 0;
		int j;
		for(j = 0; j < length; j++)
		{
			if((j & 1) == 1)
			{
				r -= bit[j];
			}
			else
			{
				r += bit[j];
			}
		}
		if(r == value)
		{
			for(j = 0; j < length; j++)
			{
				printf("%d ", bit[j]);
			}
			printf("\n");
			res += i;
			while(res >= yuzhi)
			{
				res -= yuzhi;
			}
		}
	}
	return res;
}
double alterSum(int low, int high, int value)
{
	int lowLimit[20];
	int highLimit[20];
	int tempLowLimit[20];
	int tempHighLimit[20];
	int lowLength = getBitLength(lowLimit, low);
	int highLength = getBitLength(highLimit, high);
	double res = 0;
	int i = 0;
	int index = 0;
	tempLowLimit[0] = 1;
	tempHighLimit[0] = 9;

#if 1
	for(i = 0; i < lowLength; i++)
	{
		printf("%d ", lowLimit[i]);
	}
	printf("\n");
	for(i = 0; i < highLength; i++)
	{
		printf("%d ", highLimit[i]);
	}
	printf("\n");
#endif	
	if(lowLength < highLength)
	{
		printf("lowLength < highLength\n");
		for(i = 1; i < highLength; i++)
		{
			tempLowLimit[i] = 0;
			tempHighLimit[i] = 9;
		}
#if 1
		for(i = 0; i < lowLength; i++)
		{
			printf("%d ", lowLimit[i]);
		}
		printf("\n");
		for(i = 0; i < lowLength; i++)
		{
			printf("%d ", tempHighLimit[i]);
		}
		printf("\n");
#endif
		index = 1;
		res += doAlterSum(lowLimit, tempHighLimit, lowLength, value);
		while(index < highLength - lowLength)
		{
#if 1
			for(i = 0; i < lowLength + index; i++)
			{
				printf("%d ", tempLowLimit[i]);
			}
			printf("\n");
			for(i = 0; i < lowLength + index; i++)
			{
				printf("%d ", tempHighLimit[i]);
			}
			printf("\n");
#endif
			res += doAlterSum(tempLowLimit, tempHighLimit, lowLength + index, value);
			index++;
		}
#if 1
		for(i = 0; i < highLength; i++)
		{
			printf("%d ", tempLowLimit[i]);
		}
		printf("\n");
		for(i = 0; i < highLength; i++)
		{
			printf("%d ", highLimit[i]);
		}
		printf("\n");
#endif
		res += doAlterSum(tempLowLimit, highLimit, highLength, value);
	}
	else
	{
		printf("lowLength = highLength\n");
		printf("%d %d\n", lowLength, value);
		res += doAlterSum(lowLimit, highLimit, lowLength, value);
	}
	return res;
}
int main()
{
	double low, high;
	int value;
	int choice;
	while(scanf("%lf %lf %d", &low, &high, &value) != EOF)
	{
		scanf("%d", &choice);
		if(choice == 0)
		{
			printf("%.0lf\n", alterSum_v1(low, high, value));
		}
		else
		{
			printf("%.0lf\n", alterSum(low, high, value));
		}
	}
}
