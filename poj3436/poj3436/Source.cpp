
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<cstring>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxp = 10;
const int maxn = 202 * 2;
int S[maxn][maxp];
int Q[maxn];
int D[maxn][maxp];
struct edge
{
	int from, to, flow, cap;
	
};
bool cmp(const edge & a,const edge & b)
	{
		if (a.flow > b.flow)
		{
			return true;
		}
		else if (a.flow == b.flow)
		{
			return a.from < b.from;
		}
		return false;
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
					if(!(x & 1))
					pt.push_back((x >> 1)+1);
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
				if(x != s)
				x = es[p[x]].from;
			}
		}
		return ans;
	}
	void edge_show(int f)
	{
		vector<int> p;
		for (int i = 0; i < es.size(); i++)
		{
			edge & e = es[i];
			if (e.flow > 0 && e.cap == inf && e.from != s && e.to != t)
			{
				p.push_back(i);
			//	cout << (e.from >> 1) + 1 << " " << (e.to >> 1) + 1 << " " <<e.flow << endl;
			}
		}
		cout << f << " " << p.size() <<endl;
		sort(p.begin(), p.end(), cmp);
		for (int i = 0; i < p.size(); i++)
		{
			edge & e = es[p[i]];
			cout << (e.from >> 1) + 1 << " " << (e.to >> 1) + 1 << " " << e.flow << endl;
		}
	}
};


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
                cin >> S[i][j];
            }
            for (int j = 0; j < p; j++)
            {
                cin >> D[i][j];
            }

        }
        int sour = 2 * n;
        int dest = 2 * n + 1;
        int tot = 2 * n + 2;
        isap is(tot);
		for (int i = 0; i < n; i++)
		{
			is.add_edge(i <<  1, (i <<1) + 1, Q[i]);
		}
		for (int i = 0; i < n; i++)
		{
		    bool f_source = true;
			bool to_dest = true;
			for (int k = 0; k < p; k++)
			{
				if (S[i][k] == 1)
				{
					f_source = false;
				}
				if (D[i][k] == 0)
				{
					to_dest = false;
				}
			}
			if (f_source)
			{
				is.add_edge(sour, i << 1, inf);
				
			}
			if (to_dest)
			{
				is.add_edge((i << 1) + 1, dest, inf);
			}
		}
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
				bool add = true;
				for (int k = 0; k < p; k++)
				{
					if (D[i][k] == 0 && S[j][k] == 1)
					{
						add = false;
					}
				}
				if (add)
				{
					is.add_edge((i << 1) + 1, j << 1, inf);
				}
            }
        }
		int f = is.maxflow(sour, dest);
		is.edge_show(f);
		/*
		vector<vector<int> > path = is.path(f);
		cout << f << " " << path.size() << endl;
		for (int i = 0; i < path.size(); i++)
		{
			for (int j = path[i].size() - 2; j >= 0; j--)
			{
				cout << path[i][j] << " ";
			}
			cout << path[i][path[i].size() - 1] <<endl;
		}
*/
    }
}