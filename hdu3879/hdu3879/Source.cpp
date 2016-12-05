#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct edge
{
	int u, v;
	ll cap, flow;
	edge() {}
	edge(int u, int v, ll cap) : u(u), v(v), cap(cap), flow(0) {}
};
const int maxn = 10005;
struct dinic
{
	int n;
	vector<edge> es;
	vector<vector<int> > g;
	vector<int> d, pt;
	dinic(int n) : n(n), es(0), g(n), d(n), pt(n) {}
	void addedge(int u, int v, ll cap)
	{
		if (u != v)
		{
			es.emplace_back(edge(u, v, cap));
			g[u].emplace_back(es.size() - 1);
			es.emplace_back(edge(v, u, 0));
			g[v].emplace_back(es.size() - 1);
		}
	}
	bool bfs(int S, int T)
	{
		queue<int> qq;
		qq.push(S);
		fill(d.begin(), d.end(), n + 1);
		d[S] = 0;
		while (!qq.empty())
		{
			int u = qq.front();
			qq.pop();
			if (u == T) break;
			for (int k = 0; k < g[u].size(); k++)
			{
				edge & e = es[g[u][k]];
				if (e.flow < e.cap && d[e.v] > d[e.u] + 1)
				{
					d[e.v] = d[e.u] + 1;
					qq.push(e.v);
				}
			}
		}
		return d[T] != n + 1;
	}
	ll dfs(int u, int T, ll flow = -1)
	{
		if (u == T || flow == 0) return flow;
		for (int & i = pt[u]; i < g[u].size(); i++)
		{
			edge & e = es[g[u][i]];
			edge & oe = es[g[u][i] ^ 1];
			if (d[e.v] == d[e.u] + 1)
			{
				ll amt = e.cap - e.flow;
				if (flow != -1 && amt > flow) amt = flow;
				if (ll pushed = dfs(e.v, T, amt))
				{
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	ll maxflow(int S, int T)
	{
		ll total = 0;
		while (bfs(S, T))
		{
			fill(pt.begin(), pt.end(), 0);
			while (ll flow = dfs(S, T))
			{
				total += flow;
			}
		}
		return total;
	}
};
ll p[maxn];
ll dv[maxn];
int main()
{
	int n, m;
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	ll c;
	while (cin >> n >> m)
	{
		dinic mf(n + 4);
		int S = n + 1;
		int T = S + 1;
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i];
		}
		ll sum = 0;
		memset(dv, 0, sizeof(dv));
		for (int i = 1; i <= m; i++)
		{
			cin >> a >> b >> c;
			mf.addedge(a, b, c);
			mf.addedge(b, a, c);
			dv[a] += c;
			dv[b] += c;
			sum += c;
		}
		ll U = 0;
		for (int i = 1; i <= n; i++)
		{
			U = max(U, dv[i]);
		}
	
		for (int i = 1; i <= n; i++)
		{
			mf.addedge(S, i, U);
			mf.addedge(i, T, U + 2 * p[i] - dv[i]);
		}
		ll mp = n * U - mf.maxflow(S, T);
		cout << mp/ 2 << endl;
	}
}