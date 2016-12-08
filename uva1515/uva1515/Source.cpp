
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<cstring>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2600;
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
};
string grid[51];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0,0 };
int main()
{
	int t;
	int w, h, d, f, b;
	cin >> t;
	while (t--)
	{
		cin >> w >> h >> d >> f >> b;
		int source = w * h;
		int dest = source + 1;
		int tot = dest + 1;
		isap is(tot);
		int cost = 0;
		int lw = w - 1;
		int lh = h - 1;
		for (int i = 0; i < h; i++)
		{
			cin >> grid[i];
		}
		for (int i = 0; i < h; i++)
		{
			if (grid[i][0] == '.')
			{
				grid[i][0] = '#';
				cost += f;
			}
			if (grid[i][lw] == '.')
			{
				grid[i][lw] = '#';
				cost += f;
			}
			int j = 0;
			for (int k = 0; k < 4; k++)
			{
				int tx = i + dx[k];
				int ty = j + dy[k];
				if (tx >= 0 && tx < h && ty >= 0 && ty < w)
				{
					is.add_edge(i * w + j, tx * w + ty, b);
				}
				
			}
			is.add_edge(source, w * i, inf);
			is.add_edge(source, w * i + lw, inf);
			j = lw;
			for (int k = 0; k < 4; k++)
			{
				int tx = i + dx[k];
				int ty = j + dy[k];
				if (tx >= 0 && tx < h && ty >= 0 && ty < w)
				{
					is.add_edge(i * w + j, tx * w + ty, b);
				}
			}
		}
		for (int i = 1; i < lw; i++)
		{
			if (grid[0][i] == '.')
			{
				grid[0][i] = '#';
				cost += f;
			}
			if (grid[lh][i] == '.')
			{
				grid[lh][i] = '#';
				cost += f;
			}
			is.add_edge(source, i, inf);
			is.add_edge(source, lh * w + i, inf);
			int j = 0;
			for (int k = 0; k < 4; k++)
			{
				int tx = j + dx[k];
				int ty = i + dy[k];
				if (tx >= 0 && tx < h && ty >= 0 && ty < w)
				{
					is.add_edge(j * w + i, tx * w + ty, b);
				}
			}
			j = lh;
			for (int k = 0; k < 4; k++)
			{
				int tx = j + dx[k];
				int ty = i + dy[k];
				if (tx >= 0 && tx < h && ty >= 0 && ty < w)
				{
					is.add_edge(j * w + i, tx * w + ty, b);
				}
			}
		}
		for (int i = 1; i < lh; i++)
		{
			for (int j = 1; j < lw; j++)
			{
				if (grid[i][j] == '.')
				{
					is.add_edge(i * w + j, dest, f);
				}
				else
				{
					is.add_edge(source, i * w + j, d);
				}
				for (int k = 0; k < 4; k++)
				{
					int tx = i + dx[k];
					int ty = j + dy[k];
					is.add_edge(i * w + j, tx * w + ty, b);
				}
			}
		}
		cout << is.maxflow(source, dest) + cost << endl;
	}
}


