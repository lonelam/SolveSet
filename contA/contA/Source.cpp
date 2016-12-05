#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<deque>
#include<cstdio>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 5000;
struct edge
{
	int to, flow, cap;
	edge( int to, int flow, int cap): to(to), flow(flow), cap(cap) {}
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
		es.push_back(edge( v, 0, cap ));
		es.push_back(edge( u, 0, 0 ));
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
				edge & ee = es[G[pos][i]];
				if (e.cap > e.flow && !vis[ee.to])
				{
					dis[ee.to] = dis[pos] + 1;
					vis[ee.to] = true;
					q.push_back(ee.to);
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
			x = es[p[x]^1].to;
		}
		x = t;
		while (x != s)
		{
			es[p[x]].flow += a;
			es[p[x] ^ 1].flow -= a;
			x = es[p[x]^1].to;
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
					x = es[p[x]^1].to;
				}
			}
		}
		return flow;
	}
	
};
vector<int> rG[2050];
int vs2[5000];
int vs[5000];
int k;
int fp[2050];
int depth[2050];
int a[2050];
void add_re(int from, int to)
{
	rG[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int u, int p, int d)
{
	fp[u] = k;
	vs2[k] = u;
	depth[k] = d;
	vs[k++] = u;
	for (int i = 0; i < rG[u].size(); i++)
	{
		if (p != rG[u][i])
		{
			
			dfs(rG[u][i], u, d + 1);
			depth[k] = d;
			vs2[k] = u;
			vs[k++] = rG[u][i];
		}
	}
}

bool vis[2050];
int main()
{
	int m, N;
	
	while (cin >> N >> m)
	{
		for (int i = 0; i < N; i++)
		{
			rG[i].clear();
		}
		int sN = 0;
		//int tN = sN + N;
		int rbt = sN + N;
		int superS = rbt + m;
		int superT = superS + 1;
		int tot = superT + 1;
		isap is(tot);

		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
			is.add_edge(i, superT, a[i]);
		}
		int from, to;
		for (int i = 1; i < N; i++)
		{
			cin >> from >> to;
			add_re(from - 1, to - 1);
		}
		k = 0;
		dfs(0, -1, 0);
		int w;
		for (int i = 0; i < m; i++)
		{
			cin >> from >> to >> w;
			from--;
			to--;
			is.add_edge(superS, rbt + i, w);
			memset(vis, 0, sizeof(vis));
			if (fp[from] > fp[to]) swap(from, to);
			int lca = 0;
			int uper = inf;
			for (int j = fp[from]; j <= fp[to]; j++)
			{
				if (depth[j] < uper)
				{
					uper = depth[j];
					lca = vs2[j];
				}
			}
			for (int j = fp[lca]; j <= fp[from]; j++)
			{
				vis[vs[j]] = !vis[vs[j]];
			}
			for (int j = 0; j < N; j++)
			{
				if (vis[j])
				{
					is.add_edge(rbt + i, j, inf);
				}
			}
			memset(vis, 0, sizeof(vis));
			for (int j = fp[lca]; j <= fp[to]; j++)
			{
				vis[vs[j]] = !vis[vs[j]];
			}
			for (int j = 0; j < N; j++)
			{
				if (vis[j])
				{
					is.add_edge(rbt + i, j, inf);
				}
			}
		}
		cout << is.maxflow(superS, superT) << endl;
	}
}

/*

8 3
1 2 3 4 5 6  7 8
1 2
1 3
1 4
3 5
3 6
5 7
5 8

5 7 100
7 8 3
2 4 8


*/