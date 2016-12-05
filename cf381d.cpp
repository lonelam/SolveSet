#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 200000 + 20;
int preind[maxn];
int postind[maxn];
int posno[maxn * 2];
int preno[maxn];
int presum[maxn];
//int value[maxn];
int a[maxn];
int dist[maxn];
int dfs_clock;
vector<int> G[maxn];
int w[maxn];
int N;//equals 1 << k
int sumv[maxn * 4];
int addv[maxn * 4];

void note_dfs(int u, int dis)
{
	dist[u] = dis;
	preind[u] = dfs_clock;
	posno[dfs_clock++] = u;
	for (int i = 0; i < G[u].size(); i++)
	{
		note_dfs(G[u][i], dis + w[G[u][i]]);
	}
	postind[u] = dfs_clock;
	posno[dfs_clock++] = u;
}


int y1, y2;
void add(int o, int L, int R)
{
	int lc = o * 2, rc = o * 2 +1;
	if (y1 <= L && R <= y2)
	{
		addv[o] ++;
	}
	else
	{
		int M = (L + R) / 2;
		if (M >= y1) add(o * 2, L, M);
		if (M <= y2) add(o * 2 + 1, M + 1, y2);
	}
}
int q;
int query(int o, int L, int R)
{
	const int M = (L + R) / 2;
	if (L == R && L == q) return addv[o];
	if (M < q && q <= R) return addv[o] + query(o * 2 + 1, M + 1, R);
	if (L <= q && q <= M) return addv[o] + query(o * 2, L, M);
	return 0;
}

void second_dfs(int u, int deep)
{
	if ((lower_bound(presum, presum + deep, dist[u] - a[u]) - presum) != deep)
	{
		int from = preno[lower_bound(presum, presum + deep, dist[u] - a[u]) - presum];
		y1 = preind[from];
		y2 = preind[u] - 1;
		add(1, 1, N);
	}
	presum[deep] = dist[u];
	for (int i = 0; i < G[u].size(); i++)
	{
		second_dfs(G[u][i], deep + 1);
	}
}

void solve(int n)
{
	N = 1;
	memset(addv, 0, sizeof(addv));
	while( n * 2 > N)
	{
		N <<= 1;
	}
	dfs_clock = 0;
	note_dfs(1, 0);
	second_dfs(1, 0);
	q = 1;
	cout << query(1, 1, N);
	for (int i = 2; i <= n; i++)
	{
		q = preind[i];
		int alpha = query(1, 1, N);
		q = postind[i] - 1;
		int beta = query(1, 1, N);
		cout << ' ' << alpha - beta;
	}
	cout << endl;
}
int main()
{
	int n;
	int pp, ww;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			G[i].clear();
		}
		for (int i = 2; i <= n; i++)
		{
			cin >> pp >> w[i];
			G[pp].push_back(i);
		}
		solve(n);
	}
}
