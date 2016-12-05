#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 20000 + 5;
const int maxm = 100000 + 5;
const int inf = 0x3f3f3f3f;
bool vis[maxn][maxn];
struct edge
{
	int u, v, w;
};
vector<edge> es;
int sz;
vector<int> G[maxn];
bool inq[maxn];
int dis1[maxn];
int disn[maxn];
int cnt;
void init(int n)
{
	es.clear();
	for (int i = 1; i <= n; i++)
	{
		G[i].clear();
	}
	
	sz = 0;
	memset(dis1, inf, sizeof(dis1));
	memset(disn, inf, sizeof(disn));
	cnt = 0;
}

void add(int from, int to, int weight)
{
	G[from].push_back(sz);
	es.push_back({ from, to, weight });
	sz++;
	G[to].push_back(sz);
	es.push_back( { to, from, weight });
	sz++;
	vis[from][to] = vis[to][from] = true;
}
//int cnt;
void spfa(int s, int t, int dis[])
{
	queue<int> q;
	q.push(s);
	memset(inq, 0, sizeof(inq));
	dis[s] = 0;
	inq[s] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		inq[cur] = false;
		for (int i = 0; i < G[cur].size(); i++)
		{
			edge & e = es[G[cur][i]];
			if (dis[cur] + e.w < dis[e.v])
			{
				dis[e.v] = dis[e.u] + e.w;
				if (!inq[e.v])
				{
					inq[e.v] = true;
					q.push(e.v);
				}
			}
		}
	}
}


int main()
{
	int n, m, x;
	int u, v, w;
	while (scanf("%d%d",&n,& m)!=EOF && (n || m))
	{
		scanf("%d",&x);
		init(n);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			add(u, v, w);
		}

		spfa(1, n, dis1);
		spfa(n, 1, disn);
		int ans = 0;
		sort(disn + 1, disn + n + 1);
		for (int i = 1; i <= n; i++)
		{
			int cur = x - dis1[i];
			ans += lower_bound(disn + 1, disn + n + 1, cur) - disn - 1;
		}
		printf("%d\n", ans);

	}
}