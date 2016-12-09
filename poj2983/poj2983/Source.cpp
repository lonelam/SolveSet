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

struct edge
{
	int v, w;
};
const int maxn = 1000 + 50;
vector<edge> es;
vector<int> G[maxn];
void add_edge(int a, int b, int w)
{
	G[a].push_back(es.size());
	es.push_back({ b, w });
}
int cnt[maxn];
bool inq[maxn];
bool vis[maxn];
int dis[maxn];
int n, m;
bool spfa(int s)
{
	memset(dis, 0, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	memset(inq, 0, sizeof(inq));
	queue<int> que;
	que.push(s);
	dis[s] = 0;
	cnt[s]++;
	while (!que.empty())
	{
		int cur = que.front(); que.pop();
		inq[cur] = false;
		for (int i = 0; i < G[cur].size(); i++)
		{
			edge & e = es[G[cur][i]];
			if (dis[cur] + e.w > dis[e.v])
			{
				dis[e.v] = dis[cur] + e.w;
				if (!inq[e.v])
				{
					inq[e.v] = true;
					que.push(e.v);
					cnt[e.v]++;
					if (cnt[e.v] > n) return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	int u, v, w;
	char typ[3];
	while (scanf("%d%d", &n, &m) != EOF)
	{

		for (int i = 0; i < n; i++)
		{
			G[i].clear();
		}
		es.clear();
		for (int i = 0; i < n; i++)
		{
			add_edge(n, i, 1);
		}
		n++;
		for (int i = 0; i < m; i++)
		{
			scanf("%s", typ);
			if (typ[0] == 'P')
			{
				scanf("%d%d%d", &u, &v, &w);
				add_edge(u - 1, v - 1, w);
				add_edge(v - 1, u - 1, -w);
			}
			else
			{
				scanf("%d%d", &u, &v);
				add_edge(u - 1, v - 1, 1);
			}
		}
		if (!spfa(n - 1))
		{
			printf("Unreliable\n");
		}
		else
		{
			printf("Reliable\n");
		}
	}
	return 0;
}