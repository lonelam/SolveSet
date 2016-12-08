#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 300;
const int inf = 0x3f3f3f3f;

struct edge
{
	int from, to, flow, cap;
};

int aabs(int a)
{
	return a >= 0 ? a : -a;
}

struct isap
{
	int n, m, s, t;
	vector<int> G[maxn];
	vector<edge> es;
	bool vis[maxn];
	int num[maxn];
	int cur[maxn];
	int dis[maxn];
	int p[maxn];
	isap(int n_) : n(n_)
	{}
	void add_edge(int u, int v, int cap)
	{
		es.push_back({ u, v, 0, cap });
		es.push_back({ v, u, 0, 0 });
		m = es.size();
		G[u].push_back(m - 2);
		G[v].push_back(m - 1);
	}
	void bfs()
	{
		deque<int> q;
		for (int i = 0; i < n; i++)
		{
			dis[i] = n;
		}
		memset(vis, 0, sizeof(vis));
		q.push_back(t);
		dis[t] = 0;
		vis[t] = true;
		while (!q.empty())
		{
			int pos = q.front();
			q.pop_front();
			for (int i = 0; i < G[pos].size(); i++)
			{
				edge & e = es[G[pos][i] ^ 1];
				if (e.cap > e.flow && !vis[e.from])
				{
					dis[e.from] = dis[pos] + 1;
					vis[e.from] = true;
					q.push_back(e.from);
				}
			}
		}
	}
	int aug()
	{
		int x = t;
		int a = inf;
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
		int flow = 0;
		this->s = s;
		this->t = t;
		bfs();
		memset(num, 0, sizeof(num));
		for (int i = 0; i < n; i++)
		{
			num[dis[i]] ++;
		}
		int x = s;
		memset(cur, 0, sizeof(cur));
		while (dis[s] < n)
		{
			if (x == t)
			{
				flow += aug();
				x = s;
			}
			int ok = 0;
			for (int i = cur[x]; i < G[x].size(); i++)
			{
				edge & e = es[G[x][i]];
				if (e.cap > e.flow && dis[x] == dis[e.to] + 1)
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
					{
						m = min(m, dis[e.to]);
					}
				}
				if (--num[dis[x]] == 0)
				{
					break;
				}
				num[dis[x] = m + 1] ++;
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
int M[25000];
int B[25000];
int main()
{
	int n, m;
	int t;
	int kase = 0;
	while (cin >> t)
	{
		while (t--)
		{
			
			cin >> n >> m;
			memset(M, 0, sizeof(M));
			int SS = n;
			int ST = SS + 1;
			int tot = ST + 1;
			isap is(tot);
			int u, v, l, c, r;
			for (int i = 0; i < m; i++)
			{
				cin >> u >> v >> l >> c;
				u--;
				v--;
				M[v] += l;
				M[u] -= l;
				is.add_edge(u, v, c - l);
				B[i] = l;
			}
			int target = 0;
			for (int i = 0; i < n; i++)
			{
				if (M[i] >= 0)
				{
					is.add_edge(SS, i, M[i]);
					target += M[i];
				}
				else
				{
					is.add_edge(i, ST, -M[i]);
				}
			}

			int ans = is.maxflow(SS, ST);
			if (kase++)
			{
				cout << endl;
			}
			if (ans != target)
			{
				cout << "NO\n";
				continue;
			}
			cout << "YES\n";
			for (int i = 0; i < m; i++)
			{
				cout << is.es[i * 2].flow + B[i] <<endl;
			}
		}
	}
}