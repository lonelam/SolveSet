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
const ll moder = 1e9 + 7;
ll N, M, K;
ll pow_q(ll x, ll k)
{
	if (x == 0)
		return 0LL;
	ll ans = 1;
	if (k == 0)
	{
		return ans;
	}
	ll hf = pow_q(x, k / 2);
	if (k & 1)
	{
		ans = x;
		ans = (ans * hf) % moder;
		ans = (ans * hf) % moder;
		return ans;
	}
	else
	{
		return hf * hf % moder;
	}
}
int main()
{
	int T;
	while (scanf("%d", &T)!=EOF)
	{
		int kase = 1;
		while (T--)
		{
			scanf("%d%d%d", &N, &M, &K);
			ll ans = 0;
			for (ll j = 1; j < K; j++)
			{
				ans = (ans + pow_q(j, N + M - 2)) % moder;
			}
			ans = (ans * N * M) % moder;
			ans = (ans * pow_q(K, (N - 1) * (M - 1))) % moder;
			ans = (ans + pow_q(K, M * N) )% moder;
			printf("Case #%d: %lld\n", kase++, ans);
		}
	}
	return 0;
}