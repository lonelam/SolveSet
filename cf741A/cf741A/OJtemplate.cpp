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
const int maxn = 105;
int gto[maxn];
bool vis[maxn];
int grp[maxn];
int n;
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}
int sch()
{
	int ans = 1;
	int cnt = 1;
	memset(grp, 0, sizeof(grp));
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			int circle = 0;
			int p = i;
			grp[i] = cnt;
			vis[p] = true;
			p = gto[p];
			circle++;
			while (p != i && !vis[p])
			{
				grp[p] = cnt;
				vis[p] = true;
				p = gto[p];
				circle++;
			}
			if (p != i)
			{
				return -1;
			}
			if (circle & 1)
				ans = lcm(ans, circle);
			else
				ans = lcm(ans, circle / 2);
			cnt++;
		}
	}
	return ans;
}
int main()
{
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> gto[i];
		}
		cout << sch() << endl;
	}
	return 0;
}