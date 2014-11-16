#include<iostream>
#include<string.h>
class DictTreeNode
{
	public:
		static const int letterCount = 26;
		//标示此节点是否是一个词的结尾
		bool flag;
		DictTreeNode* next[26];
		DictTreeNode()
		{
			flag = false;
			memset(next, 0, letterCount * sizeof(DictTreeNode*));
		}
};
class DictTree
{
	private:
		DictTreeNode* DictTreeRoot;
		vector<string> AllSentence;
		vector<char> tempSentence;
		void DeleteTree(DictTreeNode* pNode)
		{
			if(pNode == NULL)
			{
				return;
			}
			for(int i = 0; i < letterCount; i++)
			{
				DeleteTree(pNode->next[i]);
				if(pNode->next[i] != NULL)
				{
					delete pNode;
				}
			}
			return;
		}
		void InsertWord(int level, int length, char* str, DictTreeNode* pNode)
		{
			if(level == length)
			{
				pNode->flag = true;
				return;
			}
			int index = str[level] - 'a';
			if(pNode->next[index] == NULL)
			{
				pNode->next[index] = new DictTreeNode;
			}
			InsertWord(level + 1, length, str, DictTreeNode->next[index]);
		}
		bool SearchWord(int& level, int length, char* str,  DictTreeNode* pNode)
		{
			if((pNode->flag == true || pNode == NULL) && level <= length)
			{
				return true;
			}
			if(level >= length)
			{
				return false;
			}
			int index = str[level] - 'a';
			if(pNode->next[index] != NULL)
			{
				++level;
				return SearchWord(level, length, str, pNode->next[index]);
			}
			else
			{
				return false;
			}
		}
		void SplitString(int level, int length, char* str,  DictTreeNode* pNode)
		{
			if(level == length && (pNode->flag == true))
			{
				//wanquanpipei
				string tempString;
				for(vector<char>::iterator it = tempSentence.begin(); it != tempSentence.end(); it++)
				{
					tempString += *it;
				}
				AllSentence.push_back(tempString);
				return;
			}
			if(level >= length)
			{
				return;
			}
			if(pNode->flag == true)
			{
				tempSentence.push_back(' ');
				SplitString(level + 1, length, str, DictTreeRoot);
				tempSentence.pop_back();
				level++;
				if(level > length)
			}
			int index = str[level] - 'a';
			if(pNode->next[index] != NULL)
			{
				++level;
				tempSentence.push_back(str[level]);
				SplitString(level, length, str, pNode->next[index]);
				tempString.pop_back();
			}
			return;
		}
	public:
		DictTree()
		{
			DictTreeRoot = new DictTreeNode;
			DictTreeRoot->flag = false;
		}
		~DictTree()
		{
			DeleteTree(DictTreeRoot);
		}

		void AddWordToDict(string word)
		{
			int length = word.length;
			char *str = word.c_str();
			InsertWord(0, length, str, DictTreeRoot);
		}
		void SplitStringByDictWords(string sentence)
		{
			int length = sentence.length;
			char* str = sentence.c_str();
			SplitString();
		}
};
class Solution
{
	public:
		vector<string> wordBreak(string s, vector<string> &dict);
};
vector<string> Solution::wordBreak(string s, vector<string> &dict)
{
}
