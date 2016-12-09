#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 50000 + 50;
int d[maxn];
bool inq[maxn];
int cnt[maxn];
const int inf = 0x3f3f3f3f;
struct edge
{
	int to, dis;
};
vector<int> G[maxn];
vector<edge> es;
void add_edge(int a, int b, int c)
{
	G[a].push_back(es.size());
	es.push_back({ b, c });
}
void spfa(int s)
{
	memset(inq, 0, sizeof(inq));
	queue<int> que;
	memset(cnt, 0, sizeof(cnt));
	que.push(s);
	memset(d, -inf, sizeof(d));
	d[s] = 0;
	inq[s] = true;
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();
		inq[cur] = false;
		for (int i = 0; i < G[cur].size(); i++)
		{
			edge & e = es[G[cur][i]];
			if (e.dis + d[cur] > d[e.to])
			{
				d[e.to] = e.dis + d[cur];
				if (!inq[e.to])
				{
					inq[e.to] = true;
					que.push(e.to);
				}
			}
		}
	}
}
int n;
int main()
{
	int a, b, c;
	while (scanf("%d",&n)!=EOF)
	{
		memset(G, 0, sizeof(G));
		es.clear();
		int amax = 0;
		int amin = inf;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (a > b) swap(a, b);
			add_edge(a, b + 1, c);
			amax = max(amax, b);
			amin = min(amin, a);
		}
		amax++;
		for (int i = amin; i <= amax; i++)
		{
			add_edge(i - 1, i, 0);
			add_edge(i, i - 1, -1);
		}
		spfa(amin);
		printf("%d\n", d[amax]);
	}
}
/*

3
35 226 47
49 327 26
47 116 25

*/