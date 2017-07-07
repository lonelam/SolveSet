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
const int maxn = 5000000 + 100;

typedef long long ll;
typedef long double ld;
const ll moder = 1e9 + 7;
ll gs[maxn];
ll f[maxn];
void init()
{
	for (int i = 2; i < maxn; i++)
	{
		gs[i] = i;
	}
	for (int i = 2; i < maxn; i++)
	{
		if (!f[i])
		{
			f[i] = ((ll)i - 1) * (ll)i / 2LL % moder;
			for (int j = i + i; j < maxn; j += i)
			{
				while (gs[j] % i == 0)
				{
					f[j] = (f[j] + (gs[j] / i * f[i]) % moder) % moder;
					gs[j] /= i;
				}
			}
		}
	}
}
int main()
{
	int t, l, r;
	init();
	while (scanf("%d%d%d", &t, &l, &r) != EOF)
	{
		ll acc = 0;
		ll mt = 1;
		for (ll i = l; i <= r; i++)
		{
			acc = (acc + mt * f[i]) % moder;
			mt = (mt * t) % moder;
		}
		printf("%lld\n", acc);
	}
}