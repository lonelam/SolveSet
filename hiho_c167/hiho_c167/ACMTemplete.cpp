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
int p[maxn], n;
int vis[maxn];
int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}
int lcm(int x, int y)
{
	return x / gcd(x, y) * y;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", p + i);
	}
	int g = 1;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			int o = p[i];
			int cnt = 1;
			while (o != i)
			{
				vis[o] = true;
				o = p[o];
				cnt++;
			}
			g = lcm(g, cnt);
			//vis[o] = true;
		}
	}
	printf("%d\n", g);
	
}