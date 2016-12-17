#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn = 1000;
const int maxk = 500;
const int moder = 1e9 + 7;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int n, k, ans, f[maxn][maxk], g[maxk];
vector<int> G[maxn];

int F(int x)
{
	return x + k;
}
int add(ll x, ll y)
{
	return (x + y) % moder;
}
int mul(ll x, ll y)
{
	return (x * y) % moder;
}
void dfs(int u, int p)
{
	f[u][F(-k)] = f[u][F(1)] = 1;
	for (auto v : G[u])
	{
		if (v == p) continue;
		dfs(v, u);
		memset(g, 0, sizeof(g));
		for (int i = -k; i <= k; i++)
		{
			if (!f[u][F(i)]) continue;
			for (int j = -k; j <= k; j++)
			{
				int t = mul(f[u][F(i)], f[v][F(j)]);
				if (i <= 0 && j <= 0)
				{
					int A = min(i, j + 1);
					g[F(A)] = add(g[F(A)], t);
				}
				else if (i > 0 && j > 0)
				{
					int A = max(i, j + 1);
					g[F(A)] = add(g[F(A)], t);
				}
				else if (i <= 0 && j > 0)
				{
					int A = (-i >= j) ? i : j + 1;
					g[F(A)] = add(g[F(A)], t);
				}
				else if (i > 0 && j <= 0)
				{
					int A = (-j >= i) ? j + 1 : i;
					g[F(A)] = add(g[F(A)], t);
				}
			}
		}
		memcpy(f[u], g, sizeof(g));
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, -1);
	for (int i = 0; i <= k; i++)
	{
		ans = (ans + f[1][i]) % moder;
	}
	cout << ans << endl;
	return 0;
	return 0;
}