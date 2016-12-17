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
	int nex[1500010][26], fail[1500010];
	bool end[1500010];
	int root, L;
	int newnode()
	{
		memset(nex[L], -1, sizeof(nex[L]));
		end[L++] = false;
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
		end[now] = true;
	}
	void build()
	{
		queue<int> Q;
		fail[root] = root;
		for (int c = 0; c < 26; c++)
		{
			if (nex[root][c] != -1)
			{
				fail[nex[root][c]] = root;
				Q.push(nex[root][c]);
			}
			else
			{
				nex[root][c] = root;
			}
		}
		while (!Q.empty())
		{
			int r = Q.front();
			Q.pop();
			for (int c = 0; c < 26; c++)
			{
				int u = nex[r][c];
				if (u == -1)
				{
					nex[r][c] = nex[fail[r]][c];
					continue;
				}
				Q.push(u);
				fail[nex[r][c]] = nex[fail[r]][c];
			}
		}
	}
	bool query(char buf[])
	{
		int len = strlen(buf);
		int j = root;
		for (int i = 0; i < len; i++)
		{
			int c = buf[i] - 'a';
			j = nex[j][c];
			if (end[j])
				return true;
		}
		return false;
	}
} ac;
char buf[1100010];

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		ac.init();
		for (int i = 0; i < n; i++)
		{
			scanf("%s", buf);
			ac.insert(buf);
		}
		scanf("%s", buf);
		ac.build();
		if (ac.query(buf))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}