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
int a[maxn];
int n;
int main()
{
	scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		sort(a, a + n);
		ll cnt = 0;
		for (int i = 2; i < n; i++)
		{
			if (a[i] == a[2])
			{
				cnt++;
			}
			else break;
		}
		ll ans = 0;
		if (a[0] == a[1] && a[1] == a[2])
		{
			cnt += 2;
			ans = cnt * (cnt - 1) * (cnt - 2) / 6;
		}
		else if (a[2] == a[1])
		{
			cnt += 1;
			ans = cnt * (cnt - 1) / 2;
		}
		else
		{
			ans = cnt;
		}
		printf("%lld\n", ans);
}