#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxp = 10;
const int maxn = 105;
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
		cur.push_back(t);
		int dd = 0;
		while (!cur.empty())
		{
			for (int i = 0; i < cur.size(); i++)
			{
				int cp = cur[i];
				d[cp] = dd;
				for (int x : G[cp])
				{
					if (!vis[es[x^1].from] && es[x ^ 1].cap > 0)
					{
						nex.push_back(es[x ^ 1].from);
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
int raw[maxn][maxp];
int ripe[maxn][maxp];
int Q[maxn];
int main()
{
	int p, n;
	while (cin >> p >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> Q[i];
			for (int j = 0; j < p; j++)
			{
				cin >> raw[i][j];
			}
			for (int j = 0; j < p; j++)
			{
				cin >> ripe[i][j];
			}

		}
		int source = n << 1;
		int destination = source + 1;
		int tot = destination + 1;
		isap is(tot);
		for (int i = 0; i < n; i++)
		{
			bool link1 = true, link2 = true;
			is.add_edge(i << 1, (i << 1) + 1, Q[i]);
			for (int j = 0; j < p; j++)
			{
				if (raw[i][j] == 1)
				{
					link1 = false;
				}
				if (ripe[i][j] == 0)
				{
					link2 = false;
				}
			}
			if (link1)
			{
				is.add_edge()
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				bool 
				if()
			}
		}
	}
}
