#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
typedef long long ll;
const int maxn = 20;
int maxw = 16;
int maxf = 1 << maxw;
int n, m, f;
int mpt[maxn][maxn];
int ans[maxn][maxn];
int tmp[maxn][maxn];
int vis[maxn][maxn];

void flip(int i, int j)
{
	tmp[i][j] ^= 1;
	if (i - 1 >= 0)
	{
		tmp[i - 1][j] ^= 1;
	}
	if (i + 1 < n)
	{
		tmp[i + 1][j] ^= 1;
	}
	if (j - 1 >= 0)
	{
		tmp[i][j - 1] ^= 1;
	}
	if (j + 1 < m)
	{
		tmp[i][j + 1] ^= 1;
	}
}

int solve()
{
	f = 1 << m;
	int res = inf;
	for (int i = 0; i < f; i++)
	{
		int t = 0;
		memset(vis, 0, sizeof(vis));
		memcpy(tmp, mpt, sizeof(mpt));
		for (int k = 0; k < m; k++)
		{
			if (i >> k & 1)
			{
				flip(0, k);
				t++;
				vis[0][k] = 1;
			}
		}
		for (int j = 1; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (tmp[j - 1][k] == 1)
				{
					flip(j, k);
					t++;
					vis[j][k] = 1;
				}
			}
		}
		bool vali = true;
		for (int k = 0; k < m; k++)
		{
			if (tmp[n - 1][k] == 1)
			{
				vali = false;
				break;
			}
		}
		if (t < res && vali)
		{
			memcpy(ans, vis, sizeof(vis));
			res = t;
		}

	}
	return res;
}

int main()
{
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> mpt[i][j];
			}
		}
		int an = solve();
		if (an == inf)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			cout << ans[i][0];
			for (int j = 1; j < m; j++)
			{
				cout << " " << ans[i][j];
			}
			cout << endl;
		}
	}
}
