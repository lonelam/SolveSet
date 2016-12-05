#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<cstring>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2005 * 2 + 105 * 2;
struct edge
{
	int from, to, flow, cap;
};
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
	isap(int n_) :n(n_)
	{

	}
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
			num[dis[i]]++;
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
				if (e.cap > e.flow && dis[x] == dis[e.to] + 1)//Advance
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
					edge &e = es[G[x][i]];
					if (e.cap > e.flow)
					{
						m = min(m, dis[e.to]);
					}
				}
				if (--num[dis[x]] == 0)
				{
					break;
				}
				num[dis[x] = m + 1]++;
				cur[x] = 0;
				if (x != s)
				{
					x = es[p[x]].from;
				}
			}
		}
		return flow;
	}
	vector<vector<int> > path(int flow)
	{
		vector<vector<int> > ans;
		int x = s;
		memset(cur, 0, sizeof(cur));
		while (flow)
		{
			if (x == t)
			{
				vector<int> pt;
				int a = inf;
				while (x != s)
				{
					if (!(x & 1))
						pt.push_back((x >> 1) + 1);
					a = min(a, es[p[x]].flow);
					x = es[p[x]].from;
				}
				x = t;
				while (x != s)
				{
					es[p[x]].flow -= a;
					x = es[p[x]].from;
				}
				flow -= a;
				pt.push_back(a);
				ans.push_back(pt);

			}
			int ok = 0;
			for (int i = cur[x]; i < G[x].size(); i++)
			{
				edge & e = es[G[x][i]];
				if (e.flow > 0)
				{
					p[e.to] = G[x][i];
					ok = 1;
					cur[x] = i;
					x = e.to;
					break;
				}
			}
			if (!ok)
			{
				cur[x] = 0;
				if (x != s)
					x = es[p[x]].from;
			}
		}
		return ans;
	}
};
const int maxn_ = 105;
const int maxm_ = 1005;
int p_in_closure[maxm_];
bool vis[maxm_];
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int source = (n + m ) * 2;
		int dest = source + 1;
		int tot = dest + 1;
		int key0 = 0;
		int cp0 = n;
		int cus0 = n + m;
		int op0 = cus0 + n;
		isap is(tot);
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; i++)
		{
			cin >> p_in_closure[i];
		}
		int k;
		int buy;
		int to;
		for (int i = 0; i < n; i++)
		{
			cin >> k;
			is.add_edge(source, i + key0, inf);
			for (int j = 0; j < k; j++)
			{
				cin >> to;
				to--;
				if (!vis[to])
				{
					vis[to] = true;
					is.add_edge(key0 +i, to + cp0, p_in_closure[to]);
					is.add_edge(to + cp0, cus0 + i, inf);
					
				}
				else
				{
					is.add_edge(op0 +to, cus0 + i, inf);
				}
				is.add_edge(i + cus0, op0 + to, inf);
			}
			cin >> buy;
			is.add_edge(cus0 + i, dest, buy);
		}
		cout << is.maxflow(source, dest) << endl;
	}
}