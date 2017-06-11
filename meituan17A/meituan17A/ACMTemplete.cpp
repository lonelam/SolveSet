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
const int maxn = 1000 + 100;
typedef long long ll;
typedef long double ld;
int a[maxn];
int b[maxn];
int n, m;
int main()
{
	ll ans;
	while (scanf("%d", &n) != EOF)
	{
		ans = inf;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", b + i);
		}
		for (int i = 0; i + n <= m; i++)
		{
			ll dif = 0;
			for (int j = 0; j < n; j++)
			{
				dif += (a[j] - b[i + j]) * (a[j] - b[i + j]);
			}
			ans = min(ans, dif);
		}
		printf("%lld\n", ans);
	}
}