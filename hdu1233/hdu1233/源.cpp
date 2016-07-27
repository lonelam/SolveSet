#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstring>
using namespace std;
typedef pair<int, int> P;
const int maxn = 102;
const int inf = 0x3f3f3f3f;

int G[maxn][maxn];
int mincost[maxn];
bool used[maxn];

int n;
int prim()
{
	memset(mincost, inf, sizeof(mincost));
	memset(used, 0, sizeof(used));
	mincost[1] = 0;
	int res = 0;
	while (true)
	{
		int v = -1;
		for (int u = 1; u <= n; u++)
		{
			if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
			{
				v = u;
			}
		}
		if (v == -1)
		{
			break;
		}
		res += mincost[v];
		used[v] = true;
		for (int u = 1; u <= n; u++)
		{
			mincost[u] = min(mincost[u], G[v][u]);
		}
	}
	return res;
}
int main()
{
	int  a, b, c, m;
	while (cin >> n && n)
	{
		memset(G, inf, sizeof(G));
		m = n * (n - 1) / 2;
		while (m--)
		{
			cin >> a >> b >> c;
			G[a][b] = c;
			G[b][a] = c;
		}
		cout << prim() << endl;
	}
}