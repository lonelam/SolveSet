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
const ll moder = 1e9 + 7;
int t, n, k;
int dn;
int a[maxn];
int disc[maxn];
int bit[maxn][105];

inline int lsb(int x)
{
	return x &(-x);
}

void add(int x, int a, int d)
{
	while (x <= dn + 1)
	{
		bit[x][d] = ((ll)bit[x][d] + a) % moder;
		x += lsb(x);
	}
}

int query(int x, int d)
{
	ll ret = 0;
	while (x)
	{
		ret = (ret + bit[x][d]) % moder;
		x -= lsb(x);
	}
	return ret;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
			disc[i] = a[i];
		}
		if (k == 1)
		{
			printf("%d\n", n);
			continue;
		}
		sort(disc, disc + n);
		memset(bit, 0, sizeof(bit));
		dn = unique(disc, disc + n) - disc;
		ll ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			int p = upper_bound(disc, disc + dn, a[i]) - disc;
			ans = (ans + query(p, k - 1)) % moder;
			for (int d = k; d >= 2; d--)
			{
				add(p, query(p, d - 1) , d);
			}

			add(p, 1, 1);
		}
		
		printf("%lld\n", ans);
	}
	return 0;
//	system("pause");
}