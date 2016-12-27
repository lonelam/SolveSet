#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>        //大概这么多头文件昂
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm = 10000 + 100;    //最大点数
const int INF = 0x3f3f3f3f;
const int maxn = 60;
int n;
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
		//求最大费用最大流的情况下可能要修改！
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
		int TTN = n * 4;
		for (int i = 0; i < TTN; i++)
		{
			if (e[i * 2].f < e[i * 2].c)
			{
				return -1;
			}
		}
		return cost;
	}

};
int Rl[maxn], Rh[maxn];
int Cl[maxn], Ch[maxn];
int grid[maxn][maxn];
int Rcnt[maxn];
int Ccnt[maxn];
MCMF mf;
int main()
{
	while (scanf("%d", &n)!=EOF)
	{
		int R0 = 0;
		int C0 = n;
		int S = C0 + n;
		int T = S + 1;
		int superS = T + 1;
		int superT = superS + 1;
		int tot = superT + 1;
		mf.init(tot);
		int Ssum = 0, Tsum = 0;
		memset(Rcnt, 0, sizeof(Rcnt));
		memset(Ccnt, 0, sizeof(Ccnt));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", grid[i] + j);
				if (grid[i][j])
				{
					Rcnt[i]++;
					Ccnt[j]++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			mf.add(superS, R0 + i, Rcnt[i], 0);
			mf.add(superS, C0 + i, Ccnt[i], 0);
			Ssum += Rcnt[i];
			Ssum += Ccnt[i];
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", Rl + i, Rh + i);
			mf.add(R0 + i, superT, Rl[i], 0);
			Tsum += Rl[i];
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", Cl + i, Ch + i);
			mf.add(C0 + i, superT, Cl[i], 0);
			Tsum += Cl[i];
		}
		mf.add(T, S, INF, 0);
		mf.add(superS, T, Tsum, 0);
		mf.add(S, superT, Ssum, 0);
		for (int i = 0; i < n; i++)
		{
			mf.add(C0 + i, T, Ch[i] - Cl[i], 0);
			mf.add(R0 + i, T, Rh[i] - Rl[i], 0);
		}
		int mm = n * n / 2;
		int x1, y1, x2, y2;
		for (int i = 0; i < mm; i++)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x1 == x2)
			{
				if (grid[x1 - 1][y1 - 1])
				{
					swap(y1, y2);
				}
				mf.add(C0 + y2 - 1, C0 + y1 - 1, 1, 1);
			}
			else
			{
				if (grid[x1 - 1][y1 - 1])
				{
					swap(x1, x2);
				}
				mf.add(R0 + x2 - 1, R0 + x1 - 1, 1, 1);
			}
		}
		printf("%d\n", mf.MF(superS, superT));
	}
}

/*

2
0 0
1 1
2 2
0 1
0 2
0 2
1 1 2 1
1 2 2 2
4
0 0 1 1
0 0 1 1
1 1 0 0
1 1 0 0
2 2
1 3
1 3
2 2
0 1
3 4
0 1
3 4
1 1 1 3
1 2 1 4
2 1 2 3
2 2 2 4
3 1 3 4
3 2 3 3
4 1 4 4
4 2 4 3



*/