#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<string>
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
				for (int i = 0; i < G[cp].size(); i++)
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


const int maxc = 21;
const int maxr = 21;
int Rowsum[maxr];
int Colsum[maxc];
int Crowsum[maxr];
int Ccolsum[maxc];
int main()
{
	int t;
	cin >> t;
	int c, r;
	for(int kase = 1; kase <= t; kase++)
	{
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			cin >> Crowsum[i];
		}
		for (int i = 0; i < c; i++)
		{
			cin >> Ccolsum[i];
		}
		Rowsum[0] = Crowsum[0];
		for (int i = 1; i < r; i++)
		{
			Rowsum[i] = Crowsum[i] - Crowsum[i - 1];
		}
		Colsum[0] = Ccolsum[0];
		for (int i = 1; i < c; i++)
		{
			Colsum[i] = Ccolsum[i] - Ccolsum[i - 1];
		}
		int row0 = 0;
		int col0 = r;
		int source = r + c;
		int dest = source + 1;
		int tot = dest + 1;
		isap is(tot);
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				is.add_edge(i, j + col0, 19);
			}
		}
		for (int i = 0; i < r; i++)
		{
			is.add_edge(source, i, Rowsum[i] - c);
		}
		for (int i = 0; i < c; i++)
		{
			is.add_edge(i + col0, dest, Colsum[i] - r);
		}
		
		cout << "Matrix " << kase << endl;
		//cout << "debug " << is.maxflow(source, dest) << endl;
		for (int i = 0; i < r; i++)
		{
			cout << is.es[(i * c) << 1].flow + 1;
			for (int j = 1; j < c; j++)
			{
				cout << " " << is.es[(i * c + j) << 1].flow + 1;
			}
			cout << endl;
		}
		cout << endl;
	}
}