#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn = 500000 + 100;
int n, k;
typedef long long ll;
ll a[maxn];
ll dp[maxn];
ll S[maxn];
ll deq[maxn];

ll f(int j, int x)
{
	return -a[j] * x + dp[j] - S[j] + a[j] * j;
}

bool check(int f1, int f2, int f3)
{
	ll a1 = -a[f1], b1 = dp[f1] - S[f1] + a[f1] * f1;
	ll a2 = -a[f2], b2 = dp[f2] - S[f2] + a[f2] * f2;
	ll a3 = -a[f3], b3 = dp[f3] - S[f3] + a[f3] * f3;
	return (a2 - a1) *(b3 - b2) >= (b2 - b1) * (a3 - a2);
}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		S[i + 1] = S[i] + a[i];
	}
	int s = 0, t = 1;
	deq[0] = dp[0] = 0;
	for (int i = k; i <= n; i++)
	{
		if (i - k >= k)
		{
			while (s + 1 < t && check(deq[t - 2], deq[t - 1], i - k)) t--;
			deq[t++] = i - k;
		}
		while (s + 1 < t && f(deq[s], i) >= f(deq[s + 1], i)) s++;
		dp[i] = S[i] + f(deq[s], i);
	}
	printf("%lld\n", dp[n]);
}
int main()
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%d%d", &n, &k);
			for (int i = 0; i < n; i++)
			{
				scanf("%lld", a + i);
			}
			solve();
		}
	}
}