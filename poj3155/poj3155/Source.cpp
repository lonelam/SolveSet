#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<set>
#include<cstring>

using namespace std;
const double eps = 1e-10;
const int maxn = 105;
const double inf = 1e12;
struct edge
{
	int from, to;
	double flow, cap;
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
	void add_edge(int u, int v, double cap)
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
	
	double aug()
	{
		int x = t;
		double a = inf;
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

	double maxflow(int s, int t)
	{
		double flow = 0;
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
				if (e.cap - e.flow > eps && dis[x] == dis[e.to] + 1)//Advance
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
					if (e.cap - e.flow > eps)
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
	vector<int> precut(int flow)
	{
		//int x = s;
		deque<int> que;
		vector<int> ans;
		memset(vis, 0, sizeof(vis));
		que.push_back(s);
		vis[s] = true;
	//	ans.push_back(s);
		while (!que.empty())
		{
			int x = que.front(); que.pop_front();
			for (int i = 0; i < G[x].size(); i++)
			{
				edge & e = es[G[x][i]];
				if (e.cap - e.flow < eps && !vis[e.to])
				{
					vis[e.to] = true;
					que.push_back(e.to);
					if (e.to != t)
					{
						ans.push_back(e.to);
					}
				}
			}
		}
		return ans;
	}
	vector<vector<int> > path(double flow)
	{
		vector<vector<int> > ans;
		int x = s;
		memset(cur, 0, sizeof(cur));
		while (flow)
		{
			if (x == t)
			{
				vector<int> pt;
				double a = inf;
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
int dv[maxn];
vector<int> G[maxn];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		memset(dv, 0, sizeof(dv));
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
		}
		double U = m;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			dv[u]++;
			dv[v]++;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int t = n + 1;
		int s = n + 2;
		vector<int> ans;
		double low = 0, high = n;
		while (true)
		{
			const double mid = low + (high - low) / 2;
			isap is(t + 2);
			for (int i = 1; i <= n; i++)
			{
				for (int k = 0; k < G[i].size(); k++)
				{
					is.add_edge(i, G[i][k], 1);
				}
				is.add_edge(s, i, U);
				is.add_edge(i, t, U + 2 * mid - (double)dv[i]);
			}
			double hg = U * n - is.maxflow(s, t);
			cout << "**debug:  \n";
			cout << U * n - hg << endl;
			cout << hg << endl;

			cout << low << endl;
			cout << "****************\n";
			if (hg >= 0)
			{
				high = mid;
			}
			else
			{
				low = mid;
			}
			if (high - low > eps)
			{
				continue;
			}
			else
			{
				ans = is.precut(U*n - hg);
				break;
			}
		}
		//cout << low << endl;
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << endl;
		}
	}
}