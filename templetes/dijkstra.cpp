#include<iostream>
#include<vector>
#include<cstring>
#include<functional>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 10005;
int dis[maxn];
vector<int> G[maxn];
const int inf = 0x3f3f3f3f;
int ecnt;
struct edge
{
	int from, to, cost;
};
edge es[maxn * maxn];

void dijkstra(int s)
{
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push({0, s});
	dis[s] = 0;
	while (!q.empty())
	{
		pii c = q.top();
		q.pop();
		int cur = c.second;

		for (int i = 0; i < G[cur].size(); i++)
		{
			edge & e = es[G[cur][i]];
			if (dis[e.to] > dis[e.from] + e.cost)
			{
				dis[e.to] = dis[e.from] + e.cost;
				q.push({dis[e.to],e.to});
			}
		}

	}
}
void init(int n)
{
    ecnt = 0;
    for(int i = 0; i < n; i++)
    {
        G[i].clear();
    }
    memset(dis, inf, sizeof(dis));
}
void addedge(int u, int v, int w)
{
    es[ecnt] = {u, v, w};
    G[u].push_back(ecnt++);
}
