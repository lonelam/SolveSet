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
#include <climits>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
#include <numeric>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;
ll a[maxn];
ll b[maxn];
ll sum[maxn];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		static int n, k;
		sum[0] = 0;
		scanf("%d%d", &n, &k);
		ll tot = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", a + i);
			sum[i + 1] = sum[i] + a[i];
			tot += a[i] * (i + 1LL);
		}
		ll ans = LLONG_MAX;
		for (int i = k; i < n; i++)
		{
			ans = min(ans, k * a[i] - sum[i] + sum[i - k]);
		}
		printf("%lld\n", tot - ans);
	}
}