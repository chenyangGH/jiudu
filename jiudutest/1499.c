/*题目描述：
 * 小明每天都在开源社区上做项目，假设每天他都有很多项目可以选，其中每个项目都有一个开始时间和截止时间，假设做完每个项目后，拿到报酬都是不同的。由于小明马上就要硕士毕业了，面临着买房、买车、给女友买各种包包的鸭梨，但是他的钱包却空空如也，他需要足够的money来充实钱包。万能的网友麻烦你来帮帮小明，如何在最短时间内安排自己手中的项目才能保证赚钱最多（注意：做项目的时候，项目不能并行，即两个项目之间不能有时间重叠，但是一个项目刚结束，就可以立即做另一个项目，即项目起止时间点可以重叠）。
 * 输入：
 * 输入可能包含多个测试样例。
 * 对于每个测试案例，输入的第一行是一个整数n(1<=n<=10000)：代表小明手中的项目个数。
 * 接下来共有n行，每行有3个整数st、ed、val，分别表示项目的开始、截至时间和项目的报酬，相邻两数之间用空格隔开。
 * st、ed、value取值均在32位有符号整数（int）的范围内，输入数据保证所有数据的value总和也在int范围内。
 * 输出：
 * 对应每个测试案例，输出小明可以获得的最大报酬。
 * 样例输入：
 * 3
 * 1 3 6
 * 4 8 9
 * 2 5 16
 * 4
 * 1 14 10
 * 5 20 15
 * 15 20 8
 * 18 22 12
 * 样例输出：
 * 16
 * 22
 * */

/*resolution:
 *every project has two state "choice or not choice", so we can solve this problem by semplely write a recursive program to Enumerate all possible situation to get the best plan.However,it costs O(2^n).So, it is natural to expect use DP.
 * maxIncome[i] : the max reward xiaoming can get among 1...i priject
 * so,we can inferred:
 * maxIncome[i] = max{maxIncome[i - 1], maxIncome[j] + reward[i]}.(note: j < i && project[j].endtime <= project[i].starttime)
 * maxIncome[0] = project[0].reward 
 * */
#include<stdio.h>
#include<stdlib.h>
#define MAXCOUNT 10001
#define MAXVALUE(a,b) ((a) > (b) ? (a) : (b))
typedef struct _project project;
struct _project
{
	int start;
	int end;
	int income;
};
int maxIncome[MAXCOUNT];
project projectArr[MAXCOUNT]; 
int projectCount;
int compare(const void *a, const void *b)
{
	return ((project*)a)->end - ((project*)b)->end;
}
int calMaxIncome()
{
	qsort(projectArr, projectCount, sizeof(project), compare);
	int i;
	maxIncome[0] = projectArr[0].income;
	for(i = 1; i < projectCount; i++)
	{
		int j;
		for(j = i - 1; j >= 0; j--)
		{
			if(projectArr[j].end <= projectArr[i].start)
			{
				break;
			}
		}
		int maxCandidate = projectArr[i].income;
		if(j != -1)
		{
			maxCandidate += maxIncome[j];
		}
		maxIncome[i] = MAXVALUE(maxCandidate, maxIncome[i - 1]);
	}
	return maxIncome[projectCount - 1];
}

int main()
{
	int count;
	while(scanf("%d", &count) != EOF)
	{
		projectCount = count;
		int i;
		for(i = 0; i < count; i++)
		{
			scanf("%d %d %d", &projectArr[i].start, &projectArr[i].end, &projectArr[i].income);
			maxIncome[i] = 0;
		}
		printf("%d\n", calMaxIncome());
	}
	return 0;
}
