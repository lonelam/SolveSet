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
#include <climits>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 100;
typedef long long ll;
typedef long double ld;
const int maxk = 11;
#define v first
#define w second

int n, m;
vector<pair<int,int> > G[maxn];
int o_deg[maxn];
vector<int> cur;
int dp[maxn];
bool vis[maxn];
void init()
{
	for (int i = 0; i < n; i++)
	{
		G[i].clear();
	}
	memset(vis, 0, sizeof(vis));
	memset(o_deg, 0, sizeof(o_deg));
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		init();
		for (int i = 0; i < m; i++)
		{
			static int from, to, cost;
			scanf("%d%d%d", &from, &to, &cost);
			G[to].push_back({ from, cost });
			o_deg[from]++;
		}
		int ans = INT_MIN;
		queue<int> Q;
		for (int i = 0; i < n; i++)
		{
			    dp[i] = 0;
			if (o_deg[i] == 0)
			{
				Q.push(i);
			}
		}
		while (!Q.empty())
		{
			int c = Q.front(); Q.pop();
			for (pair<int, int> g : G[c])
			{
				dp[g.v] = max(dp[g.v], dp[c] + g.w);
				if ((--o_deg[g.v]) == 0)
				{
					Q.push(g.v);
				}
			}
		}
		printf("%d\n", *max_element(dp, dp + n));
	}
}