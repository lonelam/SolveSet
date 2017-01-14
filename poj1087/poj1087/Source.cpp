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
const int maxplug = 105;
const int maxdevice = 105;
int main()
{
	int n, m, k;
	map<string, int> aproj;
	map<string, int> dproj;
	multimap<string, string> adapter;
	map<string, string> device;
	cin >> n;
	string pname, dname;
	for (int i = 0; i < n; i++)
	{
		cin >> pname;
		aproj[pname] = i;
	}
	cin >> m;
	int n0 = 0;
	int m0 = n;
	int source = n + m;
	int dest = source + 1;
	int tot = dest + 1;
	isap is(tot);
	for (int i = 0; i < n; i++)
	{
		is.add_edge(i, dest, 1);
	}
	for (int i = 0; i < m; i++)
	{
		is.add_edge(source, m0 + i, 1);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> dname >> pname;
		device[dname] = pname;
		dproj[dname] = i;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> dname >> pname;
		adapter.insert(make_pair(dname, pname));
		//adapter[dname] = pname;
	}
	for (map<string,string>::iterator i = device.begin(); i != device.end(); i++)
	{
		string x = i->second;
		if (aproj.find(x) != aproj.end())
		{
			is.add_edge(dproj[i->first] + m0, aproj[x], 1);
		}
		deque<string> q;
		set<string> vis;
		q.push_back(x);
		vis.insert(x);
		while (!q.empty())
		{
			string c = q.front();
			q.pop_front();
			multimap<string,string>::iterator l = adapter.lower_bound(c), r = adapter.upper_bound(c);
			for (; l != r; l++)
			{
				if (aproj.find(l->second) != aproj.end())
				{
					is.add_edge(dproj[i->first] + m0, aproj[l->second], 1);
				}
			//	auto debug = vis.find(l->second);
				if (vis.find(l->second) == vis.end())
				{
					vis.insert(l->second);
					q.push_back(l->second);
				}
			}
		}
	}
	cout << m - is.maxflow(source, dest) << endl;
	//system("pause");
}
