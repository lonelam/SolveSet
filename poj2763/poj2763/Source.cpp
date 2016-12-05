#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 320001 * 2;
//BIT implemention
int sum_n;
int C[maxn];
int lsb(int x)
{
	return x&(-x);
}
int sum(int x)
{
	int ret = 0;
	while (x > 0)
	{
		ret += C[x];
		x -= lsb(x);
	}
	return ret;
}
void add(int x, int d)
{
	while (x <= sum_n)
	{
		C[x] += d;
		x += lsb(x);
	}
}
void sum_init(int N)
{
	sum_n = 1;
	while (N > sum_n)
	{
		sum_n <<= 1;
	}
	sum_n <<= 1;
	memset(C, 0, sizeof(int) * sum_n);
}
struct edge
{
	int to, cost, id;
	edge() {}
	edge(int to, int cost, int id) : to(to), cost(cost), id(id) {}
};
int k;
int vs[maxn * 2];
vector<int> G[maxn];
int sz;
edge es[maxn * 2 + 20 ];
///LCA RMQ version!!
const int inf = 0x3f3f3f3f;
void add_edge(int from, int to, int weight, int id)
{
	G[from].push_back(sz);
	es[sz].to = to;
	es[sz].id = id;
	es[sz++].cost = weight;
	G[to].push_back(sz);
	es[sz].to = from;
	es[sz].id = id;
	es[sz++].cost = weight;
}
///RMQ !

int RMQ[maxn * 2 + 1];
int RMQ_N;
void rmq_init(int * tar, int n)
{
	RMQ_N = 1;
	while (n > RMQ_N)
	{
		RMQ_N <<= 1;
	}
	RMQ_N <<= 1;
	for (int i = 0; i < n; i++)
	{
		RMQ[RMQ_N + i] = i;
	}
	for (int i = n; i < RMQ_N; i++)
	{
		RMQ[RMQ_N + i] = -1;
	}
	for (int i = RMQ_N - 1; i > 0; i--)
	{
		if (RMQ[i * 2] == -1)
		{
			RMQ[i] = RMQ[i * 2 + 1];
		}
		else if (RMQ[i * 2 + 1] == -1 ||tar[RMQ[i * 2]] < tar[RMQ[i * 2 + 1]])
		{
			RMQ[i] = RMQ[i * 2];
		}
		else
		{
			RMQ[i] = RMQ[i * 2 + 1];
		}
	}
}
int depth[maxn * 2 + 1];
int inner_query(int l, int r, int o, int ql, int qr)
{
	if (ql <= l && r <= qr)
	{
		return RMQ[o];
	}
	if (r < ql || qr < l)
	{
		return -1;
	}
	int ans = 0;
	const int mid = l + (r - l) / 2;
	int dl = inner_query(l, mid, o * 2, ql, qr);
	int dr = inner_query(mid + 1, r, o * 2 + 1, ql, qr);
	if (dl == -1)
	{
		return dr;
	}
	if (dr == -1 || depth[dl] < depth[dr])
	{
		return dl;
	}
	else
	{
		return dr;
	}
}
int query(int l, int r)
{
	return inner_query(0, RMQ_N - 1, 1, l, r);
}
///LCA
int id_access1[maxn];
int id_access2[maxn];
int id_w[maxn];
int fp[maxn];
void dfs(int u, int p, int d)
{
	depth[k] = d;
	fp[u] = k;
	vs[k++] = u;
	for (int i = 0; i < G[u].size(); i++)
	{
		edge & e = es[G[u][i]];
		if (e.to != p)
		{
			add(k, e.cost);
			id_access1[e.id] = k;
			dfs(e.to, u, d + 1);
			add(k, -e.cost);
			id_access2[e.id] = k;
			depth[k] = d;
			vs[k++] = u;
		}
	}
}
int lca(int ll, int rr)
{
	return fp[vs[query(ll, rr)]];
}
int main()
{
	int V, q, s;
	int from, to, cost;

	while (scanf("%d%d%d", &V, &q, &s)!=EOF)
	{
		sz = 0;
		k = 1;
		sum_init(V * 2 + 1);
		for (int i = 1; i <= V ; i++)
		{
			G[i].clear();
		}

		for (int i = 1; i < V; i++)
		{
			scanf("%d%d%d", &from, &to, &cost);
			add_edge(from, to, cost, i);
			id_w[i] = cost;
		}
		dfs(s, -1, 0);
		rmq_init(depth, k);
		int cur = s;
		int cmd;
		int u;
		int nno, wto;
		for (int i = 0; i < q; i++)
		{
			scanf("%d", &cmd);
			if (cmd == 0)
			{
				scanf("%d", &u);
				int l = min(fp[cur], fp[u]);
				int r = max(fp[cur], fp[u]);
				printf("%d\n", sum(l) + sum(r) - 2 * sum(lca(l, r)));
				cur = u;
			}
			else
			{
				scanf("%d%d", &nno, &wto);
				add(id_access1[nno], wto - id_w[nno]);
				add(id_access2[nno], id_w[nno] - wto);
				id_w[nno] = wto;
			}
		}
	}
}

/*

10 40 5
1 2 4
1 3 3
1 4 1
4 5 9
5 6 6
4 7 6
1 8 2
1 9 7
9 10 3
0 1
1 6 9
1 7 2
0 6


*/