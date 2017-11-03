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
const int maxn = 1000000 + 100;
typedef long long ll;
typedef long long LL;
typedef long double ld;
const ll mod = 1e9 + 7;
const ll p = mod;
///LucasÄ£°å
LL quick_mod(LL a, LL b)
{
	LL ans = 1;
	a %= p;
	while (b)
	{
		if (b & 1)
		{
			ans = ans * a % p;
			b--;
		}
		b >>= 1;
		a = a * a % p;
	}
	return ans;
}

LL C(LL n, LL m)
{
	if (m > n) return 0;
	LL ans = 1;
	for (int i = 1; i <= m; i++)
	{
		LL a = (n + i - m) % p;
		LL b = i % p;
		ans = ans * (a * quick_mod(b, p - 2) % p) % p;
	}
	return ans;
}

LL Lucas(LL n, LL m)
{
	if (m == 0) return 1;
	return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}
ll f(ll n, ll k)
{
	if (n == 1 && k == 1) return 1;
	if (k > n) return 0;
	if (n > 1 && k > 1) return Lucas(n-1, k);
	return 0;
}
int main()
{
	int T;
	ll n, m, k;
	//initFac(maxn - 1);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld", &n, &m, &k);
		printf("%lld\n", Lucas(m, k) * f(n, k) % mod);
	}
}