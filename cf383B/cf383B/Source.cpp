#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 1000000 + 10;
typedef long long ll;
ll a[maxn];
int main()

{
	ll n, x;
	while (cin >> n >> x)
	{
		map<ll, ll> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (mp.find(a[i]) != mp.end())
			mp[a[i]]++;
			else mp.insert({ a[i], 1 });
		}
		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			ll tar = a[i] ^ x;
			mp[a[i]]--;
			ans += mp[tar];
		}
		cout << ans << endl;
	}
}