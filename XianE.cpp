#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
int a[100];
int main(void)
{
	ll i, j;
	ll n;
	ll ans;
	ll mod = 1000000007ll;
	while (~scanf("%lld", &n))
	{
		n--;
		memset(a, 0, sizeof(a));
		i = 0;
		ll t = n;
		while (t > 0)
		{
			a[i++] = t & 1ll;
			t >>= 1ll;
		}
		ans = 1;
		//cout << ans << endl;
		for (i = 1, j = 1; (1ll << i) <= n; i++, j = (j * 4) % mod)
		{
			ll temp = n >> i;
			ll x = 1ll << i;
			if (n % x < (1ll << (i - 1)))
			{
				temp--;
			}
			//cout << "temp: " << temp << endl;
			ans += ((temp % mod) * ((j + 1) % mod)) % mod;
			ans %= mod;
		}
		for (i = 2, j = 1; i <= n; i <<= 1, j = (j * 4) % mod)
		{
			ans += j + 1;
			ans %= mod;
		}
    printf("%lld\n", ans % mod);
		// cout << ans % mod << endl;
	}
	return 0;
}
