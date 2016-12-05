#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>        //大概这么多头文件昂
#include<string.h>
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

	int MF(int s, int t) {
		this->s = s; this->t = t;
		int flow = 0, cost = 0;
		while (spfa(flow, cost));
		return cost;
	}

};
MCMF gg;
int n, m;
const int maxn = 50 + 2;
int Z[maxn][maxn];// n be the toy
int main()
{
	int t;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d%d", &n, &m);
			gg.init(n * m + n + 2);
			int source = n *m;
			int dest = source + 1;
			int toy0 = dest + 1;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					scanf("%d", Z[i] + j);
					for (int k = 0; k < n; k++)
					{
						gg.add(toy0 + i, j* n + k, 1, Z[i][j] * (k + 1));
					}
					gg.add(j * n + i, dest, 1, 0);
				}
				gg.add(source, toy0 + i, 1, 0);
			}
			printf("%.6f\n", (double)gg.MF(source, dest) / n);
		}
	}
}