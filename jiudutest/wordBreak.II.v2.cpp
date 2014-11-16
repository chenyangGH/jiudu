#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
vector<string> wordBreak(string s, set<string> &dict, map<string, vector<string>>& cache)
{
	if(cache.find(s) != cache.end())
	{
		return cache[s];
	}
	vector<string> result;
	for(int i = 0; i < s.size(); i++)
	{
		string w = s.substr(0, i + 1);
		if(dict.find(w) != dict.end())
		{
			if(i == s.size() - 1)
			{
				result.push_back(w);
				break;
			}
			vector<string> ret = wordBreak(s.substr(i + 1, s.size() - i - 1), dict, cache);
			for(int j = 0; j < ret.size(); j++)
			{
				result.push_back(w + " " + ret[j]);
			}
		}
	}
	cache[s] = result;
	return result;
}

void wordBreak(string s, set<string> &dict, string str, vector<string>& result)
{
	string org_str = str;
	for(int i = 0; i < s.size(); i++)
	{
		string w = s.substr(0, i + 1);
		if(dict.find(w) != dict.end())
		{
			str = org_str;
			if(str.size() > 0)
			{
				str += " ";
			}
			str = str + w;
			if(i == s.size() - 1)
			{
				result.push_back(str);
				return;
			}
			wordBreak(s, substr(i + 1, s.size() - i - 1), dict, str, result);
		}
	}
}

vector<string> wordBreak_dp(string s, set<string> &dict)
{
	vector<vector<string>> result(s.size());
	for(int i = s.size() - 1; i >= 0; i--)
	{
		vector<string> v;
		result[i] = v;
		for(int j = i + 1; j <= s.size(); j++)
		{
			string word = s.substr(i, j - i);
			if(dict.find(word) != dict.end())
			{
				if(j == s.size())
				{
					result[i].push_back(word);
				}
				else
				{
					for(int k = 0; k < result[j].size(); k++)
					{
						result[i].push_back(word + " " + result[j][k]);
					}
				}
			}
		}
	}
}
