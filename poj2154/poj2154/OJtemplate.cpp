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
typedef long long ll;
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
ll moder;
ll pow_m(ll x, ll k)
{
	if (k == 1)
	{
		return x;
	}
	ll hf = pow_m(x, k / 2);
	if (k & 1)
	{
		return (((hf * hf) % moder)* x) % moder;
	}
	else
	{
		return (hf * hf) % moder;
	}
}
int main()
{
	int T;
	while (cin >> T)
	{
		ll n;
		while (T--)

		{
			cin >> n >> moder;
			ll sum = 0;
			for (ll k = 0; k < n; k++)
			{

			}
		}
	}
	return 0;
}