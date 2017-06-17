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
ll dp[19][181];
int main()
{
	ll n, s;
	while (cin >> n >> s)
	{
		ll d = (s + 8) / 9;
		ll dmask = 1;
		ll rn = n;
		while (dmask <= d)
		{
			dmask *= 10;
			dmask += 1;
		}
		dmask /= 10;
		ll low = 0;
		while (dmask)
		{
			low *= 10;
			low += d / dmask;
			d -= d / dmask * dmask;
			dmask /= 10;
		}
		if (d) low += 1;
		low *= 10;
		cout << max(n - low + 1, 0LL) << endl;
	}
}