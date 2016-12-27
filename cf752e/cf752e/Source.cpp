#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10000000 + 100;
typedef long long ll;
ll dp[maxn];
ll a[maxn];
int main()
{
	int n;
	ll k;
	ios::sync_with_stdio(false);
	cin >> n >> k;
	ll R = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		R = max(R, a[i]);
	}
	R++;
	ll superR = R;
	ll L = 0;
	while (L + 1 < R)
	{
		const ll mid = L + (R - L) / 2;
		if (mid == 0)
		{
			L = R = mid;
			break;
		}
		memset(dp, 0, sizeof(dp));
		for (ll i = mid; i <= superR; i++)
		{
			dp[i] = dp[i / 2] + dp[(i + 1) / 2];
			dp[i] = max(dp[i], 1LL);
		}
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum +=dp[a[i]];
			if (sum >= k)
			{
				break;
			}
		}
		if (sum >= k)
		{
			L = mid;
		}
		else
		{
			R = mid;
		}
	}
	if (L == 0)
	{
		cout << -1 << endl;
	}
	else
		cout << L << endl;
}