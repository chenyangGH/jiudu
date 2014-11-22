/* 题目描述：
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 * 输入：
 * 输入可能包含多个测试样例。
 * 对于每个测试案例，输入的第一行为一个整数m (1<=m <=100)代表输入的正整数的个数。
 * 输入的第二行包括m个正整数，其中每个正整数不超过10000000。
 * 输出：
 * 对应每个测试案例，
 * 输出m个数字能排成的最小数字。
 * 样例输入：
 * 3
 * 23 13 6
 * 2
 * 23456 56
 * 样例输出：
 * 13236
 * 2345656
 * */


/* solution:
 * the most intuitive and simple solution is compare all combination situation
 * to get the smallest one. for n nums it costs O((n!)^2).
 * 
 * first,we consider a simple case,assume there only two nums:a and b.
 * stra and strb is the string representation of a and b. we can expect that
 * min{strcat(stra, strb),strcat(strb, stra)} is the string representation of
 * the min num which can be combinationed by a and b.and this representation can be
 * get by sort all the num's string representation and the compare rule for
 * any two num's string representation is:
 * min{strcat(stra, strb),strcat(strb, stra)}
 * this conclusion can be proved by "Reductio ad absurdum"
 * */
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAXLEN 9
#define SWAP(a,b,temp) do{temp = (a);(a) = (b);(b) = temp;}while(0)
void reverse(char* str)
{
		int low = 0;
		int high = strlen(str) - 1;
		char temp;
		while(low < high)
		{
				SWAP(str[low],str[high],temp);
				low++;
				high --;
		}
}
char* intostr(int num)
{
		int temp = 0;
		char* str = (char*)malloc(MAXLEN * sizeof(char));
		int i = 0;
		while(num > 0)
		{
				temp = num % 10;
				str[i] = temp + '0';
				num = num / 10;
				i++;
		}
		str[i] = '\0';
		reverse(str);
		return str;
}

int compare(char* pstra, char* pstrb)
{
		int lengtha = strlen(pstra);
		int lengthb = strlen(pstrb);
		char* ptemp = NULL;
		char* pca = (char*)malloc(lengtha + lengthb + 1);
		char* pcb = (char*)malloc(lengtha + lengthb + 1);
		strcpy(pca, pstra);
		ptemp = pca + lengtha;
		strcpy(ptemp, pstrb);

		strcpy(pcb, pstrb);
		ptemp = pcb + lengthb;
		strcpy(ptemp, pstra);

		return strcmp(pca, pcb);
}
//we choice parray[0] as compare baseline
int partition(char** parray, int low, int high)
{
		char* ptemp = NULL;
		int i = low;
		int j = high + 1;
		while(1)
		{
				do
				{
						i++;
				}while(i <= high && (compare(parray[i], parray[low]) < 0));
				do
				{
						j--;
				}while(compare(parray[j], parray[low]) > 0);
				if(i > j)
				{
						break;
				}
				SWAP(parray[i], parray[j], ptemp);
		}
		SWAP(parray[j], parray[low], ptemp);
		return j;
}
void quick_sort(char** parray, int low, int high)
{
		int loc = 0;
		if(low < high)
		{
				loc = partition(parray, low, high);
				quick_sort(parray, low, loc - 1);
				quick_sort(parray, loc + 1, high);
		}
}

int main()
{
		char** parray = NULL;
		int* pnum = NULL;
		int length = 0;
		int i = 0;

		while(scanf("%d",&length) != EOF)
		{
				pnum = (int*)malloc(length * sizeof(int));
				parray = (char**)malloc(length * sizeof(char*));
				for(i = 0; i < length; i++)
				{
						scanf("%d",&pnum[i]);
				}
				for(i = 0; i < length; i++)
				{
						parray[i] = NULL;
						parray[i] = intostr(pnum[i]);
				}
				quick_sort(parray, 0, length - 1);
				for(i = 0; i < length; i++)
				{
						if(parray[i] != NULL)
						{
								printf("%s",parray[i]);
						}
				}
				printf("\n");

				pnum = NULL;
				parray = NULL;
		}
}
