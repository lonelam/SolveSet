#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 300000 + 50;
int N;
ll C[maxn * 4];
int lsb(int x)
{
	return x &(-x);
}
void big_n_init(int n)
{
	N = 1;
	while (n > N)
	{
		N <<= 1;
	}
}
ll sum(int x)
{
	ll ret = 0;
	while (x > 0)
	{
		ret += C[x];
		x -= lsb(x);
	}
	return ret;
}


void add(int x, ll d)
{
	while (x <= N)
	{
		C[x] += d;
		x += lsb(x);
	}
}

int k;
void bit_init(int n)
{
	memset(C, 0, sizeof(C));
	big_n_init(n);
	k = 1;
}


struct edge
{
	int v;
	ll w;
	edge(int v, ll w) :v(v), w(w) {}
};
vector<edge> G[maxn];
void add_edge(int u, int v, ll w)
{
	G[u].emplace_back(edge(v, w));
	G[v].emplace_back(edge(u, w));
}

int vs[maxn * 2];
int depth[maxn * 2];
int fp[maxn];
void dfs(int u, int p, int d)
{
	fp[u] = k;
	vs[k] = u;
	depth[k++] = d;
	for (int i = 0; i < G[u].size(); i++)
	{
		edge & ee = G[u][i];
		if (ee.v == p) continue;
		add(k, ee.w);
		dfs(ee.v, u, d + 1);
		add(k, -ee.w);
		vs[k] = u;
		depth[k++] = d;
	}
}

int RMQ[maxn * 4];
void rmq_init()
{
	for (int i = 0; i < k; i++)
	{
		RMQ[i + N] = i;
	}
	memset(RMQ + k + N, -1, sizeof(int) * (N));
	for (int i = N - 1; i > 0; i--)
	{
		if (RMQ[i * 2 + 1] == -1)
		{
			RMQ[i] = RMQ[i * 2];
		}
		else if (RMQ[i * 2] == -1 || depth[RMQ[i * 2]] > depth[RMQ[i * 2 + 1]])
		{
			RMQ[i] = RMQ[i * 2 + 1];
		}
		else
		{
			RMQ[i] = RMQ[i * 2];
		}
	}
}

int query(int ql, int qr, int o = 1, int l = 0, int r = N - 1)
{
	if (ql <= l && r <= qr)
	{
		return RMQ[o];
	}
	if (r < ql || qr < l)
	{
		return -1;
	}
	const int mid = l + (r - l) / 2;
	int ansl = query(ql, qr, o * 2, l, mid);
	int ansr = query(ql, qr, o * 2 + 1, mid + 1, r);
	if (ansl == -1)
	{
		return ansr;
	}
	if (ansr == -1 || depth[ansl] < depth[ansr])
	{
		return ansl;
	}
	return ansr;
}

int lca(int from, int to)
{
	return vs[query(fp[from], fp[to])];
}
int main()
{
	ios::sync_with_stdio(false);
	int n, q;
	int to;
	ll length;
	int from;
	while (cin >> n&& n)
	{
		for (int i = 0; i < n; i++)
		{
			G[i].clear();
		}
		bit_init(n * 2);

		for (int i = 1; i < n; i++)
		{
			cin >> to >> length;
			add_edge(i, to, length);
		}
		dfs(0, -1, 0);
		rmq_init();
		cin >> q;
		for (int i = 0; i < q; i++)
		{
			cin >> from >> to;
			if (fp[from] > fp[to]) swap(from, to);
			int lc = lca(from, to);
			if (i != 0) cout << ' ';
			ll ans = sum(fp[from]) - 2 * sum(fp[lc]) + sum(fp[to]);
			cout <<  ans ;
		}
		cout << endl;
	}
}
/*
10
0 994352451
1 994352451
2 994352451
3 994352451
4 994352451
5 994300052451
6  994352000451
7 994352451
8 994352451
10
0 10
*/