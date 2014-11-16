#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct _Relation Relation;
struct _Relation
{
	int group;
};
int groupCount(Relation* relation, int length)
{
	int i = 0;
	if(length <= 0)
	{
		return 0;
	}
	for(i = 0; i < length; i++)
	{
		int id = i;
		int groupId = relation[id].group;
		while(groupId != id)
		{
			id = groupId;
			groupId = relation[id].group;
		}
		relation[i].group = groupId;
	}
	int count = 0;
	for(i = 0; i < length; i++)
	{
		if(relation[i].group == i)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int n, m;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
		{
			break;
		}
		scanf("%d", &m);
		Relation* pRelation = (Relation*)malloc(n * sizeof(Relation));
		int i;
		for(i = 0; i < n; i++)
		{
			pRelation[i].group = i;
		}
		for(i = 0; i < m; i++)
		{
			int id1;
			int id2;
			scanf("%d %d", &id1, &id2);
			id1--;
			id2--;
			if(id1 < id2)
			{
				pRelation[id2].group = id1;
			}
			else
			{
				pRelation[id1].group = id2;
			}
		}
		printf("%d\n",groupCount(pRelation, n));
		free(pRelation);
	}
	return 0;
}
