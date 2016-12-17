#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
struct Trie
{
	int nex[500010][26], fail[500010], end[500010];
	int root, L;
	int newnode()
	{
		for (int i = 0; i < 26; i++)
		{
			nex[L][i] = -1;
		}
		end[L++] = 0;
		return L - 1;
	}
	void init()
	{
		L = 0;
		root = newnode();
	}
	void insert(char buf[])
	{

		int len = strlen(buf);
		int now = root;
		for (int i = 0; i < len; i++)
		{
			if (nex[now][buf[i] - 'a'] == -1)
			{
				nex[now][buf[i] - 'a'] = newnode();
			}
			now = nex[now][buf[i] - 'a'];
		}
		end[now]++;
	}
	void build()
	{
		queue<int> Q;
		fail[root] = root;
		for (int i = 0; i < 26; i++)
		{
			if (nex[root][i] == -1)
			{
				nex[root][i] = root;
			}
			else
			{
				fail[nex[root][i]] = root;
				Q.push(nex[root][i]);
			}
		}
		while (!Q.empty())
		{
			int now = Q.front();
			Q.pop();
			for (int i = 0; i < 26; i++)
			{
				if (nex[now][i] == -1)
				{
					nex[now][i] = nex[fail[now]][i];
				}
				else
				{ 
					fail[nex[now][i]] = nex[fail[now]][i];
					Q.push(nex[now][i]);
				} 
			}
		}
	}
		int query(char buf[])
		{
			int len = strlen(buf);
			int now = root;
			int res = 0;
			for (int i = 0; i < len; i++)
			{
				now = nex[now][buf[i] - 'a'];
				int temp = now;
				while (temp != root)
				{
					res += end[temp];
					end[temp] = 0;
					temp = fail[temp];
				}
			}
			return res;
		}
};
char buf[1000010];
Trie ac;
int main()
{
	int T;
	int n;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%d", &n);
			ac.init();
			for (int i = 0; i < n; i++)
			{
				scanf("%s", buf);
				ac.insert(buf);
			}
			ac.build();
			scanf("%s", buf);
			printf("%d\n", ac.query(buf));
		}
	}
	return 0;
}