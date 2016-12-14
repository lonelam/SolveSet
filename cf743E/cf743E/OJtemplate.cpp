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
bool vis[10];
int a[1000 + 10];
int n;
int ans;
bool dfs(int cur, int x, int p, int ccc, int cl = -1)
{
	if (cur == 0)
	{
		ans = max(ans, ccc);
		return true;
	}
	int cnt = 0;
	if (cl != -1)
	{
		for (; p < n && cnt < x; p++)
		{
			if (a[p] == cl)
				cnt++;
		}
		if (cnt != x)
		{
			return false;
		}
	}
	ccc += cnt;
	bool fret = false;
	for (int i = 1; i <= 8; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			if (dfs(cur - 1, x, p, ccc, i))
				fret = true;
			vis[i] = false;
		}
	}
	if (cl != -1)
	{
		for (; p < n && cnt < x+1; p++)
		{
			if (a[p] == cl)
				cnt++;
		}
		if (cnt != x + 1)
			return fret;
	}
	ccc++;
	for (int i = 1; i <= 8; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			if (dfs(cur - 1, x, p, ccc, i))
				fret = true;
			vis[i] = false;
		}
	}
	return fret;
}
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int l = 1, r = n;
		ans = 0;
		memset(vis, 0, sizeof(vis));
		while (l + 1 < r)
		{
			const int mid = l + (r - l) / 2;
			if (dfs(8, mid, 0, 0))
			{
				l = mid;
			}
			else
			{
				r = mid;
			}
		}
		dfs(8, l, 0, 0);
		cout << ans << endl;
	}
	return 0;
}