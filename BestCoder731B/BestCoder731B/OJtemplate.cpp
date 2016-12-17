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
const int maxn = 100000 + 10;
int n;
int fa[maxn];
int a[maxn];
vector<int> G[maxn];
bool bfs()
{
	queue<int> que, nex;
	que.push(0);
	int xsum = 0;
	while (!que.empty())
	{
		xsum = 0;
		while (!que.empty())
		{
			int cur = que.front();
			que.pop();
			for (int x : G[cur])
			{
				xsum ^= x;
				nex.push(x);
			}
		}
		swap(que, nex);
	}
	return xsum != 0;
}
int main()
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%d", &n);
			for (int i = 0; i < n; i++) G[i].clear();
			for (int i = 1; i < n; i++)
			{
				scanf("%d", fa + i);
				G[fa[i]].push_back(i);
			}
			for (int i = 0; i < n; i++)
			{
				scanf("%d", a + i);
			}
			if (bfs())
			{
				printf("win\n");
			}
			else
			{
				printf("lose\n");
			}
		}
	}
	return 0;
}