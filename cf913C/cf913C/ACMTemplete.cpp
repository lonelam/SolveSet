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
int n;
ll L;
ll c[100];

int main()
{
	while (cin >> n >> L)
	{
		memset(c, 0x7f, sizeof(c));
		
		for (int i = 0; i < n; i++)
		{
			cin >> c[i];
			if (i)
			{
				c[i] = min(c[i], c[i - 1] * 2LL);
			}
			//	for (int j = 0; j < i; j++)
			//	{
			//		if (c[j] >= c[i])
			//		{
			//			c[j] = c[i];
			//			dp[j] = 1;
			//		}
			//	}
			//	//c[i - 1] = min(c[i], c[i - 1]);
			//}
		}
		for (int i = n; i < 32; i++)
		{
			c[i] = c[i - 1] * 2LL;
		}
		ll ans = 0;
		for (int i = 0; i < 32; i++)
		{
			if (c[i] < ans)
			{
				ans = c[i];
			}
			if (L >> i & 1LL)
			{
				//if (dp[i]) ans = 0;
				ans += c[i];
				//cout << ans << endl;
			}
		}
		cout << ans << endl;
	}
}