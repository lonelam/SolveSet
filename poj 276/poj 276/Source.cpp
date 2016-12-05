#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define lson k << 1
#define rson k << 1 | 1
#define mid (l + r) >> 1
using namespace std;

const int maxn = 100005, inf = 0x3f3f3f3f;
int n, q, s, opt, eglist[maxn], egsz, par[maxn], son[maxn], sz[maxn],
depth[maxn], top[maxn], id[maxn], tot, ec[maxn], vc[maxn], hs[maxn], sum[maxn << 2];


struct edge
{
	int to, No, cost, nexteg;
} egs[maxn << 1];

void add_edge(int u, int v, int c, int nn)
{
	egs[++egsz].to = v;
	egs[egsz].cost = c;
	egs[egsz].No = nn;
	egs[egsz].nexteg = eglist[u];
	eglist[u] = egsz;
}

void dfs1(int u, int fa)
{
	par[u] = fa;
	son[u] = -1;
	sz[u] = 1;
	for (int i = eglist[u]; i; i = egs[i].nexteg)
	{
		int v = egs[i].to;
		if (v == fa) continue;
		depth[v] = depth[u] + 1;
		hs[egs[i].No] = v;
		vc[v] = egs[i].cost;
		dfs1(v, u);
		sz[u] += sz[v];
		if (sum[u] == -1 || sz[son[u]] < sz[son[u]] < sz[v]) son[u] = v;
	}
}

void dfs2(int u, int rt)
{
	top[u] = rt; id[u] = ++tot; ec[tot] = vc[u];
	if (~son[u]) dfs2(son[u], rt);
	for (int i = eglist[u]; i; i = egs[i].nexteg)
	{
		int v = egs[i].to;
		if (v == par[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}


void push_up(int k)
{
	sum[k] = sum[lson] + sum[rson];
}

void build(int k, int l, int r)
{
	if (r - l == 1)
	{
		sum[k] = ec[l];
		return;
	}
	//const int mid = l + (r - l) / 2;
	build(lson, l, mid);
	build(rson, mid, r);
	push_up(k);
}


void change(int p, int x, int k, int l, int r)
{
	if (p < l || r <= p) return;
	if (p == l && r == p + 1) { sum[k] = x; return; }
	//const int mid = l + (r - l) / 2;
	change(p, x, lson, l, mid);
	change(p, x, rson, mid, r);
	push_up(k);
}

int query(int a, int b, int k, int l, int r)
{
	if (a >= b) return 0;
	if (b <= l || r <= a) return 0;
	if (a <= l && r <= b) return sum[k];
	//const int mid = l + (r - l) / 2;
	return query(a, b, lson, l, mid) + query(a, b, rson, mid, r);
}

int main()
{
	while (~scanf("%d%d%d", &n, &q, &s))
	{
		int u, v, c;
		tot = egsz = 0;
		memset(eglist, 0, sizeof(eglist));
		for (int i = 1; i < n; ++i)
		{
			scanf("%d%d%d", &u, &v, &c);
			add_edge(u, v, c, i);
			add_edge(v, u, c, i);
		}
		dfs1(1, -1);
		dfs2(1, 1);
		build(1, 1, tot + 1);
		while (q--)
		{
			scanf("%d", &opt);
			if (opt)
			{
				scanf("%d%d", &u, &v);
				change(id[hs[u]], v, 1, 1, tot + 1);
			}
			else
			{
				scanf("%d", &v);
				u = s; 
				s = v;
				int ans = 0;
				while (top[u] != top[v])
				{
					if (depth[top[u]] < depth[top[v]]) swap(u, v);
					ans += query(id[top[u]], id[u] + 1, 1, 1, tot + 1);
					u = par[top[u]];
				}
				if (depth[u] > depth[v]) swap(u, v);
				ans += query(id[u] + 1, id[v] + 1, 1, 1, tot + 1);
				printf("%d\n", ans);
			}
		}
	}
}




