#include<iostream>
#include<vector>
#include<cstring>
#include<deque>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
//const int maxp = 10;
const int maxn = 507;
struct edge
{
	int from, to, cap, flow;
};
struct isap
{

	int n, m, s, t;
	isap(int n_) :n(n_), m(0) {}
	vector<edge> es;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn];
	int cur[maxn];
	int p[maxn];
	int num[maxn];
	void bfs()
	{
		deque<int> cur, nex;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			d[i] = n;
		}
		cur.push_back(t);
		int dd = 0;
		while (!cur.empty())
		{
			for (int i = 0; i < cur.size(); i++)
			{
				int cp = cur[i];
				d[cp] = dd;
				for(int i = 0; i < G[cp].size(); i++)
				//for (int x : G[cp])
				{
					int x = G[cp][i];
					if (!vis[es[x ^ 1].from] && es[x ^ 1].cap > 0)
					{
						nex.push_back(es[x ^ 1].from);
						vis[es[x ^ 1].from] = true;
					}
				}
			}
			cur.clear();
			dd++;
			swap(cur, nex);
		}
	}
	void add_edge(int from, int to, int cap)
	{
		es.push_back({ from, to, cap, 0 });
		es.push_back({ to, from, 0, 0 });
		m = es.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}
	int Augment()
	{
		int x = t, a = inf;
		while (x != s)
		{
			edge & e = es[p[x]];
			a = min(a, e.cap - e.flow);
			x = e.from;
		}
		x = t;
		while (x != s)
		{
			es[p[x]].flow += a;
			es[p[x] ^ 1].flow -= a;
			x = es[p[x]].from;
		}
		return a;
	}
	int maxflow(int s, int t)
	{
		this->s = s;
		this->t = t;
		int flow = 0;
		bfs();
		memset(num, 0, sizeof(num));
		for (int i = 0; i < n; i++)
		{
			num[d[i]]++;
		}
		int x = s;
		memset(cur, 0, sizeof(cur));
		while (d[s] < n)
		{
			if (x == t)
			{
				flow += Augment();
				x = s;
			}
			int ok = 0;
			for (int i = cur[x]; i < G[x].size(); i++)
			{
				edge &e = es[G[x][i]];
				if (e.cap > e.flow && d[x] == d[e.to] + 1)
				{
					ok = 1;
					p[e.to] = G[x][i];
					cur[x] = i;
					x = e.to;
					break;
				}
			}
			if (!ok)
			{
				int m = n - 1;
				for (int i = 0; i < G[x].size(); i++)
				{
					edge & e = es[G[x][i]];
					if (e.cap > e.flow)
						m = min(m, d[e.to]);
				}
				if (--num[d[x]] == 0)
				{
					break;
				}
				num[d[x] = m + 1] ++;
				cur[x] = 0;
				if (x != s)
				{
					x = es[p[x]].from;
				}
			}
		}
		return flow;
	}
};
const int maxf = 105;
int main()
{
	int n, f, d;
	int fi, di, lik;
	while (cin >> n >> f >> d)
	{
		int n0 = f;
		int nout = f + n;
		int f0 = 0;
		int d0 = f + n * 2;
		int source = n * 2 + f + d;
		int destiny = source + 1;
		int tot = destiny + 1;
		isap is(tot);
		for (int i = 0; i < n; i++)
		{
			is.add_edge(n0 + i, nout + i, 1);
		}
		for (int i = 0; i < f; i++)
		{
			is.add_edge(source, i, 1);
		}
		for (int i = 0; i < d; i++)
		{
			is.add_edge(d0 + i, destiny, 1);
		}
		for (int i = 0; i < n; i++)
		{
			cin >> fi >> di;
			for (int j = 0; j < fi; j++)
			{
				cin >> lik;
				lik--;
				is.add_edge(f0 + lik, n0 + i, 1);
			}
			for (int j = 0; j < di; j++)
			{
				cin >> lik;
				lik--;
				is.add_edge(nout + i, d0 + lik, 1);
			}
		}
		cout << is.maxflow(source, destiny) << endl;
	}
}