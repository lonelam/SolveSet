#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<deque>
#include<vector>
#include<deque>
#include<cstring>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 201 * 2;
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
const int maxv = 101;
const int maxe = 501;
int in[maxv];
int out[maxv];
int G[maxv][maxv];
bool vis[maxv];

void euler_circuit(int x, int n, deque<int> &res)
{
	int i;

	//res.push_front(x);
	for (i = n - 1; i >= 0; i--)
	{
		if (G[x][i])
		{
			G[x][i]--;
			euler_circuit(i, n, res);
		}
	}
	res.push_back(x);


}
int main()
{
	int t;
	int v, e;
	string type;
	int from, to;
	while (cin >> t)
	{
		while (t--)
		{
			memset(G, 0, sizeof(G));
			cin >> v >> e;
			int source = v;
			int dest = source + 1;
			int tot = dest + 1;
			isap is(tot);
			memset(in, 0, sizeof(in));
			memset(out, 0, sizeof(out));
			for (int i = 0; i < e; i++)
			{
				cin >> from >> to >> type;
				from--;
				to--;
				if (type[0] == 'U')
				{
					is.add_edge(from, to, inf);
				}
				else
				{
					//is.add_edge(from, to, 0);
				}
				G[from][to]++;
				in[to] ++;
				out[from]++;
			}
			int stat = 0;
			bool valid = true;
			for (int i = 0; i < v; i++)
			{
				int diff = out[i] - in[i];
				if (diff & 1)
				{
					valid = false;
					break;
				}
				else if (diff > 0)
				{
					is.add_edge(source, i, diff / 2);
					stat += diff / 2;
				}
				else if (diff < 0)
				{
					is.add_edge(i, dest, -diff / 2);
					//stat += -diff / 2;
				}

			}
			memset(vis, 0, sizeof(vis));
			if (valid)
			{
				int ans = is.maxflow(source, dest);
				//cout << "debug :" << ans <<" "<< stat<< endl;
				if (ans == stat)
				{
					for (int i = 0; i < is.es.size(); i++)
					{
						edge & e = is.es[i];
						if (e.flow > 0)
						{
							if (e.from != source && e.to != dest && e.flow > 0)
							{
								G[e.from][e.to]-= e.flow;
								G[e.to][e.from]+= e.flow;
							}
						}
					}

					// dFS
					deque<int> q;
					euler_circuit(0, v, q);
					cout << q.back() + 1;
					q.pop_back();
					while (!q.empty())
					{
						cout <<" "<< q.back() + 1;
						q.pop_back();
					}
					cout << endl;
				}
				else
				{
					cout << "No euler circuit exist\n\n";
				}
			}
			else
			{
				cout << "No euler circuit exist\n\n";
			}
		}
	}
}