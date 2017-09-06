#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 100;
const int maxk = 21;

typedef long long ll;
typedef long double ld;
int n;
int fa[maxn][maxk];
ll dis[maxn];
int depth[maxn];
struct edge
{
	int v;
	ll w;
}es[maxn * 2];
int tot;
vector<int> G[maxn];

void init()
{
	for (int i = 1; i <= n; i++)
	{
		G[i].clear();
	}
	tot = 0;
	depth[1] = 0;
	dis[1] = 0;
}

void addedge(int u, int v, ll w)
{
	G[u].push_back(tot);
	es[tot++] = { v, w };
	G[v].push_back(tot);
	es[tot++] = { u, w };
}

void dfs(int cur, int parent)
{
	fa[cur][0] = parent;
	for (int k = 1; k < maxk; k++)
	{
		fa[cur][k] = fa[fa[cur][k - 1]][k - 1];
	}
	for (int eno : G[cur])
	{
		edge & e = es[eno];
		if (e.v != parent)
		{
			dis[e.v] = dis[cur] + e.w;
			depth[e.v] = depth[cur] + 1;
			dfs(e.v, cur);
		}
	}
}
int lca(int u, int v)
{
	if (depth[u] < depth[v])
	{
		swap(u, v);
	}
	for (int k = maxk - 1; k >= 0; k--)
	{
		if (depth[fa[k][u]] >= depth[v])
		{
			u = fa[k][u];
		}
	}
	if (u == v) return u;
	for (int k = maxk - 1; k >= 0; k--)
	{
		if (fa[k][u] != fa[k][v])
		{
			u = fa[k][u];
			v = fa[k][v];
		}
	}
	return fa[u][0];
}

struct path
{
	int s, e;
	ll len()
	{
		return dis[s] + dis[e] - 2 * dis[lca(s, e)];
	}
};
bool cmp_by_depth(int lhs, int rhs)
{
	return depth[lhs] < depth[rhs];
}
path merge(const path & x,const path & y)
{
	int tmp[4] = { lca(x.s, y.s), lca(x.s, y.e), lca(x.e, y.s), lca(x.e, y.e) };
	sort(tmp, tmp + 4, cmp_by_depth);
	int low = depth[lca(x.s, x.e)];
	int up = depth[lca(y.s, y.e)];
	if (low > up) swap(low, up);
	if (depth[tmp[0]] < low || depth[tmp[2]] < up) return { 1, 1 };
	return { tmp[2], tmp[3] };
}
path seg[maxn << 2];
path raw[maxn];
int m;
void pushup(int x)
{
	seg[x] = merge(seg[x << 1], seg[x << 1 | 1]);
}
void build(int L = 0, int R = m, int o = 1)
{
	if (L + 1 == R)
	{
		seg[o] = raw[L];
		return;
	}
	const int mid = (L + R) / 2;
	build(L, mid, o << 1);
	build(mid, R, o << 1 | 1);
	pushup(o);
}
path query(int ql, int qr, int L = 0, int R = m, int o = 1)
{
	if (ql <= L && R <= qr)
	{
		return seg[o];
	}
	const int mid = (L + R) / 2;
	path ret = { -1, -1 };
	if (ql < mid) ret = query(ql, qr, L, mid, o << 1);
	if (mid < qr)
	{
		if (ret.s == -1)
		{
			ret = query(ql, qr, mid, R, o << 1 | 1);
		}
		else
		{
			ret = merge(ret, query(ql, qr, mid, R, o << 1 | 1));
		}
	}
	return ret;
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		init();
		for (int i = 1; i < n; i++)
		{
			static int x, y;
			static ll z;
			scanf("%d%d%lld", &x, &y, &z);
			addedge(x, y, z);
		}
		dfs(1, 1);
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &raw[i].s, &raw[i].e);
		}
		build();
		int q;
		scanf("%d", &q);
		while (q--)
		{
			static int L, R;
			scanf("%d%d", &L, &R);
			L--;
			printf("%lld\n", query(L, R).len());
		}
	}
}