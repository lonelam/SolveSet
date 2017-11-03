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
ll a[maxn];
int n;
ll p, q, r;
int main()
{
	while (cin >> n)
	{
		cin >> p >> q >> r;
		
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		ll ans = a[0] * (p + q + r);
		ll pl = a[0] * p;
		ll ql = a[0] * q + pl;
		for (int i = 0; i < n; i++)
		{
			pl = max(pl, a[i] * p);
			ql = max(ql, a[i] * q + pl);
			ans = max(ans, a[i] * r + ql);
		}
		cout << ans << endl;
	}
}