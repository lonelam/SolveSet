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
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;
vector<int> G[maxn];
ld dp[maxn];
void dfs(int cur, int parent)
{
	int cnt = 0;
	for (int v : G[cur])
	{
		if (v != parent)
		{
			dfs(v, cur);
			cnt++;
		}
	}
	if (cnt)
	{
		for (int v : G[cur])
		{
			if (v != parent)
			{
				dp[cur] += dp[v] + 1;
			}
		}
		dp[cur] /= (ld)cnt;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while (cin >> n)
	{
		for (int i = 1; i < n; i++)
		{
			static int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 1);
		cout.setf(ios::fixed);
		cout.precision(9);
		cout << dp[1] << endl;
	}
}