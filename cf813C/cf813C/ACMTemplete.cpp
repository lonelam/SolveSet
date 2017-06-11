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
const int maxn = 200000 + 100;
typedef long long ll;
typedef long double ld;
vector<int> G[maxn];
int n, x;
void addedge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
bool is_path[maxn];
int pathd[maxn];
int d[maxn];
int ans = 0;
void dfs(int cur, int p, int depth)
{
	for (int i = 0; i < G[cur].size(); i++)
	{
		if (G[cur][i] != p)
		{
			dfs(G[cur][i], cur, depth + 1);
			if (is_path[G[cur][i]])
			{
				is_path[cur] = true;
				pathd[cur] = pathd[G[cur][i]] + 1;
			}
			d[cur] = max(d[cur], d[G[cur][i]] + 1);// = d[cur] + 1;
		}
	}
	if (is_path[cur] && depth > pathd[cur])
	{
		ans = max(ans, depth + d[cur]);
	}
}
int u, v;
int main()
{
	while (scanf("%d%d", &n, &x) != EOF)
	{
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			G[i].clear();
		}
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			addedge(u - 1, v - 1);
		}
		memset(is_path, 0, sizeof(is_path));
		memset(d, 0, sizeof(d));
		is_path[x - 1] = true;
		pathd[x - 1] = 0;
		dfs(0, -1, 0);
		//ans = max(ans, d[x - 1]);
		printf("%d\n", ans * 2);
	}
}