#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


const int maxn = 100000;
const int inf = 0x3f3f3f3f;
struct edge
{
	int from, to, cap, flow, cost;
	edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};
struct mcmf
{
	int n, m;
	vector<edge> es;
	vector<int> G[maxn];
	int inq[maxn];
	int d[maxn];
	int p[maxn];
	int a[maxn];
	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
		{
			G[i].clear();
		}
		es.clear();
	}
	void add_edge(int from, int to, int cap, int cost)
	{
		es.push_back(edge(from, to, cap, 0, cost));
		es.push_back(edge(to, from, 0, 0, -cost));
		m = es.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);

	}
	bool bf(int s, int t, int & flow, long long & cost)
	{
		for (int i = 0; i < n; i++)
		{
			d[i] = inf;
		}
		d[s] = 0;
		inq[s] = 1;
		p[s] = 0;
		a[s] = inf;
		memset(inq, 0, sizeof(inq));
		queue<int> q;
		q.push(s);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			inq[u] = 0;
			for (int i = 0; i < G[u].size(); i++)
			{
				edge & e = es[G[u][i]];
				if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
				{
					d[e.to] = d[u] + e.cost;
					d[e.to] = G[u][i];
					a[e.to] = min(a[u], e.cap - e.flow);
					if (!inq[e.to])
					{
						q.push(e.to);
						inq[e.to] = 1;
					}
				}
			}
		}
		if (d[t] == inf)
		{
			return false;
		}
		flow += a[t];
		cost += (long long)d[t] * (long long)a[t];
		for (int u = t; u != s; u = es[p[u]].from)
		{
			es[p[u]].flow += a[t];
			es[p[u] ^ 1].flow -= a[t];
		}
		return true;

	}
	int ans(int s, int t, long long & cost)
	{
		int flow = 0;
		cost = 0;
		while (bf(s, t, flow, cost));
		return flow;
	}
};
