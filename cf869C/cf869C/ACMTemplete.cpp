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
const ll moder = 998244353;

typedef long double ld;
ll p_m(ll base, ll index)
{
	ll ret = 1;
	while (index)
	{
		if (index & 1)
		{
			ret *= base;
			ret %= moder;
		}
		base *= base;
		base %= moder;
		index >>= 1;

	}
	return ret;
}
ll mem[10000];
ll fac(ll n)
{
	return mem[n];
	ll ans = 1;
	while (n)
	{
		ans *= n--;
		ans %= moder;
	}
	return mem[n] = ans;
}
ll A(ll n, ll m)
{
	ll ans = 1;
	if (n < m) swap(n, m);
	while (n > m)
	{
		ans *= n;
		ans %= moder;
		n--;
	}
	return ans;
}
int main()
{
	ll a, b, c;
	mem[0] = 1;
	for (ll i = 1; i < 6000; i++)
	{
		mem[i] = mem[i - 1] * i;
		mem[i] %= moder;
	}
	while (cin >> a >> b >> c)
	{
		ll ans = 1, tot = 1, finl = 1;
		for (ll i = min(a, b), j = max(a, b), k = 1; i > 0; i--, j--, k++)
		{
			ans *= (i * j) % moder;
			ans %= moder;
			tot += ans * p_m(fac(k), moder - 2);
			tot %= moder;
		}
		finl *= tot;
		finl %= moder;
		ans = tot = 1;
		for (ll i = min(a, c), j = max(a, c), k = 1; i > 0; i--, j--, k++)
		{
			ans *= (i * j) % moder;
			ans %= moder;
			tot += ans * p_m(fac(k), moder - 2);
			tot %= moder;
		}
		finl *= tot;
		finl %= moder;
		ans = tot = 1;
		for (ll i = min(c, b), j = max(c, b), k = 1; i > 0; i--, j--, k++)
		{
			ans *= (i * j) % moder;
			ans %= moder;
			tot += ans * p_m(fac(k), moder - 2);
			//cout << A(k, k) << endl;
			tot %= moder;
		}
		finl *= tot;
		finl %= moder;
		cout << finl << endl;
	}
}