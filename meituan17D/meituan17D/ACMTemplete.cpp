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
int n;
bool vis[maxn];
bool reach[maxn];
int a[maxn];
int b[maxn];
vector<int> G[maxn];
void rdfs(int cur)
{
	reach[cur] = true;
	for (int i = 0; i < G[cur].size(); i++)
	{
		if (!reach[G[cur][i]]) rdfs(G[cur][i]);
	}
}
int dfs(int cur, string & ans)
{
	if (vis[cur]) return -1;
	vis[cur] = true;
	if (cur == n - 1) return 1;
	int ta = cur + a[cur];
	int tb = cur + b[cur];
	if (0 <= ta && ta < n && reach[ta])
	{
		ans.push_back('a');
		int oa = dfs(ta, ans);
		if (oa == 1) return 1;
		if (oa == -1) return -1;
		ans.pop_back();
	}
	if (0 <= tb && tb < n && reach[tb])
	{
		ans.push_back('b');
		int ob = dfs(tb, ans);
		if (ob == 1) return 1;
		if (ob == -1) return -1;
		ans.pop_back();
	}
	return 0;
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		memset(reach, 0, sizeof(reach));
		for (int i = 0; i < n; i++)
		{
			G[i].clear();
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
			int tar = i + a[i];
			if (tar >= 0 && tar < n)
			{
				G[tar].push_back(i);
			}
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", b + i);
			int tar = i + b[i];
			if (tar >= 0 && tar < n)
			{
				G[tar].push_back(i);
			}
		}
		rdfs(n - 1);
		if (reach[0])
		{
			string ans;
			if (dfs(0, ans) == 1)
			{
				printf("%s\n", ans.c_str());
			}
			else
			{
				printf("Infinity!\n");
			}
		}
		else
		{
			printf("No solution!\n");
		}
	}
}