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
ll bs(ll l, ll r, ll k, ll i)
{
	const ll mid = l + (r - l) / 2;
	if (k == mid)
	{
		return i;
	}
	else if (k > mid)
	{
		return bs(l, r / 2, k - mid, i - 1);
	}
	else
	{
		return bs(l, r / 2, mid - k, i - 1);
	}
}
int main()
{
	ll n, k;
	while (cin >> n >> k)
	{
		cout << bs(1LL, (1LL << n) - 1LL, k, n) << endl;
	}
	return 0;
}