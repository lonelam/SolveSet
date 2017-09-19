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
const ll up = 100000;
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}
ld target;
pair<ll,ll> farey()
{
	pair<ll, ll> a = { 0,1 };
	pair<ll, ll> b = { 1,1 };
	pair<ll, ll> A;
	if (abs((ld)a.first / (ld)a.second - target) < abs((ld)b.first / (ld)b.second - target))
	{
		A = a;
	}
	else
	{
		A = b;
	}
	while (true)
	{
		pair<ll, ll> c = { (a.first + b.first), a.second + b.second };
		ll gc = gcd(c.first, c.second);
		c.first /= gc;
		c.second /= gc;
		if (c.second > up) return A;
		if (abs((ld)c.first / (ld)c.second - target) < abs((ld)A.first / (ld)A.second - target))
			A = c;
		if (((ld)c.first / (ld)c.second) >= target && ((ld)a.first / (ld)a.second ) <= target)
		{
			b = c;
		}
		else
		{
			a = c;
		}
	}
}
ll K;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &K);
		ld x = powl(K, (ld)2 / (ld)3);
		target = x - floorl(x);
		ll num = floorl(x);
		pair<ll, ll> ans = farey();
		ans.first += num * ans.second;
		printf("%lld/%lld\n", ans.first, ans.second);
	}
}