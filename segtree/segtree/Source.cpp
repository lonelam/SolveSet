

#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10000;
int pre[maxn], dfs_clock;
bool iscut[maxn];
vector<int> G[maxn];
int dfs(int u, int fa)
{
	int lowu = pre[u] = dfs_clock++;
	int child = 0;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][v];//edges u to v;
		if (!pre[v])
		{
			child++;
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if (lowv >= pre[u])//preu is dfs_clock,lowv is the lowest vertex u's children coud reach!
			{
				iscut[u] = true;
			}
		}
		else if (pre[v] < pre[u] && v != fa)//v has been reached, whose time is earlier and is definitly not u's child
		{
			lowu = min(lowu, pre[v]);
		}
		if (fa < 0 && child == 1)
		{
			iscut[u] = 0;
		}
		low[u] = lowu;
		return lowu;
	}
}