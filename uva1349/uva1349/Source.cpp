#include<stdio.h>        //大概这么多头文件昂
#include<string.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm = 10000 + 100;    //最大点数
const int INF = 0x3f3f3f3f;

struct edge {        //边：起点、终点、容量、流量、单位费用
	int from, to, c, f, cost;
	edge(int a, int b, int m, int n, int p) :from(a), to(b), c(m), f(n), cost(p) {}
};

int aabs(int a) {
	return a >= 0 ? a : -a;
}

struct MCMF {
	int m, s, t;
	vector<edge>e;
	vector<int>g[maxm];
	int dis[maxm], a[maxm], p[maxm];
	bool vis[maxm];

	void init(int n) {        //初始化函数
		for (int i = 0; i <= n; i++)g[i].clear();
		e.clear();
	}

	void add(int a, int b, int c, int v) {    //加边函数
		e.push_back(edge(a, b, c, 0, v));
		e.push_back(edge(b, a, 0, 0, -v));
		m = e.size();
		g[a].push_back(m - 2);
		g[b].push_back(m - 1);
	}

	bool spfa(int& flow, int& cost) {
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		queue<int>q;
		q.push(s);
		vis[s] = 1;
		dis[s] = 0;
		p[s] = 0;
		a[s] = INF;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			vis[u] = 0;
			for (int i = 0; i<g[u].size(); i++) {
				edge tmp = e[g[u][i]];
				if (dis[tmp.to]>dis[u] + tmp.cost&&tmp.c>tmp.f) {
					dis[tmp.to] = dis[u] + tmp.cost;
					p[tmp.to] = g[u][i];
					a[tmp.to] = min(a[u], tmp.c - tmp.f);
					if (!vis[tmp.to]) {
						q.push(tmp.to);
						vis[tmp.to] = 1;
					}
				}
			}
		}
		if (dis[t] == INF)return 0;
		flow += a[t];
		cost += dis[t] * a[t];
		int u = t;
		while (u != s) {
			e[p[u]].f += a[t];
			e[p[u] ^ 1].f -= a[t];
			u = e[p[u]].from;
		}
		return 1;
	}

	int MF(int s, int t, int & flow) {
		this->s = s; this->t = t;
		int cost = 0;
		while (spfa(flow, cost));
		
		return cost;
	}

};

int main()
{
	int n;
	int to, d;
	while (cin >> n && n)
	{
		int e_0 = n;
		int s_0 = 0;
		int source = e_0 + n;
		int dest = source + 2;
		int tot = dest + 1;
		MCMF mc;
		mc.init(tot);
		for (int i = 0; i < n; i++)
		{
			mc.add(source, (i << 1) + 1, 1, 0);
			mc.add(i << 1, dest, 1, 0);
		}
		for (int i = 0; i < n; i++)
		{
			while (cin >> to && to)
			{
				cin >> d;
				to--;
				mc.add((i << 1) + 1, to << 1, 1, d);
			}
		}
		int flow = 0;
		int ans = mc.MF(source, dest, flow);
		if (flow == n)
		{
			cout << ans << endl;
		}
		else
		{
			cout << "N\n";
		}
	}
}