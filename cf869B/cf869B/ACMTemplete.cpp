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
ll a, b;
int main()
{
	while (cin >> a >> b)
	{
		map<pair<ll, ll>, ll> vis;
		ll ans = 1;
		ll cur = b % 10;
		ll cnt = b - a;
		while (cnt > 0)
		{
			if (vis[{ans, cur}])
			{
				cnt %= (cnt - vis[{ans, cur}]);
			}
			else
			{
				vis[{ans, cur}] = cnt;
			}
			if (cnt)
			{
				ans *= cur;
				ans %= 10;
				cur = (cur + 9) % 10;
				cnt--;
			}
		}
		cout << ans << endl;
	}
}