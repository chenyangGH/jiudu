#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;
class Solution
{
	typedef unsigned char BOOL;
	static const BOOL TRUE = 1;
	static const BOOL FALSE = 0;
	static const int MAX_INT = 10000000;
	public:
		int minCut(string s)
		{
			int length = s.size();
			const char* str = s.c_str();
			Initialize(length);
			FindAllPalindrome(str, length);
			int res = CalcMinCut(length);
			Release(length);
			return res;
		}
		Solution(){}
	private:
		BOOL **IsPalindrome;
		int *CutTime;
		template<typename T>
		inline T MinValue(T a, T b)
		{
			return (a < b ? a : b);
		}
		int CalcMinCut(int length)
		{
			for(int i = 1; i < length; i++)
			{
				int res = MAX_INT;
				if(IsPalindrome[0][i])
				{
					CutTime[i] = 0;
					continue;
				}
				for(int j = 1; j <= i; j++)
				{
					if(IsPalindrome[j][i])
					{
						res = MinValue(res, CutTime[j - 1] + 1);
					}
				}
				CutTime[i] = res;
			}
			return CutTime[length - 1];
		}
		void FindAllPalindrome(const char* str, int length)
		{
			for(int i = 0; i < length; i++)
			{
				IsPalindrome[i][i] = TRUE;
			}
			for(int i = 0; i < length - 1; i++)
			{
				if(str[i] == str[i + 1])
				{
					IsPalindrome[i][i + 1] = TRUE;
				}
			}
			for(int len = 2; len < length; len++)
			{
				for(int i = 0; i < length - len; i++)
				{
					if(IsPalindrome[i + 1][i + len - 1] == TRUE && str[i] == str[i + len])
					{
						IsPalindrome[i][i + len] = TRUE;
					}
				}
			}
		}
		void Release(int length)
		{
			for(int i = 0; i < length; i++)
			{
				free(IsPalindrome[i]);
			}
			free(IsPalindrome);
			free(CutTime);
		}
		void Initialize(int length)
		{
			IsPalindrome = (BOOL**)malloc(sizeof(BOOL*) * length);
			for(int i = 0; i < length; i++)
			{
				IsPalindrome[i] = (BOOL*)malloc(sizeof(BOOL) * length);
				memset(IsPalindrome[i], 0, sizeof(BOOL) * length);
			}
			CutTime = (int*)malloc(sizeof(int) * length);
			memset(CutTime, 0, sizeof(int) * length);
		}
};
int main()
{
	Solution solution;
	string s;
	cin>>s;
	cout<<solution.minCut(s)<<endl;
	return 0;
}
