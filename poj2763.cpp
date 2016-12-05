#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

struct edge {int id, to, cost;};
const int maxn = 100001 + 20;
const int maxq = maxn;
int n, q, s;
int a[maxn - 1], b[maxn - 1], w[maxn - 1];
int type[maxq];
int x[maxq], t[maxq];

vector<edge> G[maxn];
// bit here

int bit_n;

int root;

int vs[maxn * 2 - 1];
int depth[maxn * 2 - 1];
int id[maxn];
int es[ (maxn - 1) * 2];
void dfs(int v, int p, int d, int & k)
{
	id[v] = k;
	vs[k] = v;
	depth[k++] = d;
	for (int i = 0; i < G[v].size(); i++)
	{
		edge & e = G[v][i];
		if (e.to != p)
		{
			add(k, e.cost);
			es[e.id * 2] = k;
			dfs(e.to, v,d + 1, k);
			vs[k] = v;
			depth[k++] = d;
			add(k, -e.cost);
			es[e.id * 2 + 1] = k;
		}
	}
}

int stack_v[maxn +10];
int stack_i[maxn + 10];

void init(int V)
{
	bit_n = (V - 1) * 2;
	int k = 0;
	dfs(root, -1, 0, k);
	rmq_init(depth, V * 2 - 1);
}

int lca(int u, int v)
{
	return vs[query(min(id[u], id[v]), max(id[u], id[v])];
}


void solve()
{
	root = n / 2;
	for (int i = 0; i < n - 1; i++)
	{
		G[a[i] - 1].push_back((edge){i, b[i] - 1, w[i]});
		G[b[i] - 1].push_back((edge){i, a[i] - 1, w[i]});
		init(n);
		for (int i = 0; i < q; i++)
		{
			if (type[i] == 0)
			{
				int u = x[i] - 1;
				int p = lca(v, u);
				printf("%d\n", sum(id[v]) + sum(id[u]) - sum(id[p]) * 2);
				v = u;
			}
			else
			{
				int k = x[i] - 1;
				add(es[k *2], t[i] - w[k]);
				add(es[k * 2 + 1], w[k] - t[i]);
				w[k] = t[i];
			}
		}
	}
}



