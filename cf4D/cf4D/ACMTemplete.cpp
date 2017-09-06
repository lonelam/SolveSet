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
const int maxn = 5000 + 100;
typedef long long ll;
typedef long double ld;
int dp[maxn];
struct node
{
	int w, h, id;
	bool operator<(const node & rhs) const
	{
		if (w != rhs.w) return w < rhs.w;
		if (h != rhs.h) return h < rhs.h;
		return id < rhs.id;
	}
} ns[maxn];
int pre[maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, w, h;
	memset(pre, -1, sizeof(pre));
	cin >> n >> w >> h;
	int tot = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &ns[tot].w, &ns[tot].h);
		if (ns[tot].w > w && ns[tot].h > h)
		{
			ns[tot].id = i + 1;
			tot++;
		}
	}
	sort(ns, ns + tot);
	int ans = 0;
	int p = -1;
	for (int i = tot - 1; i >= 0; i--)
	{
		dp[i] = 1;
		pre[i] = -1;
		for (int j = i + 1; j < tot; j++)
		{
			if (ns[i].w < ns[j].w && ns[i].h < ns[j].h && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				pre[i] = j;
			}
		}
		if (dp[i] > ans)
		{
			ans = max(ans, dp[i]);
			p = i;
		}
	}
	cout << ans << endl;
	if (ans)
	{
		while (p != -1)
		{
			cout << ns[p].id << " ";
			p = pre[p];
		}
	}
	//system("pause");
}