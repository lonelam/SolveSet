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
ll dp[1 << 17][105];
//int brem[20];

int main()
{
	ll n;
	int m;
	cin >> n >> m;
	vector<int> digit;
	int bmask = 1;
	ll dmask = 1;
	int tmp = 0;
	while (n)
	{
		//brem[tmp] = dmask % m;
		//bmask *= 10;
		digit.push_back(n % 10);
		n /= 10;
	}
	const int pmax = 1 << digit.size();
	//bmask = 1;
	int nlen = digit.size();
	dp[0][0] = 1;
	for (int k = 0; k < nlen; k++)
		for (int i = 0; i < pmax; i++)
		{
			int popcnt = 0;
			bmask = 1;
			while (bmask <= i)
			{
				if (bmask & i) popcnt++;
				bmask <<= 1;
			}
			if (popcnt != k) continue;
			bmask = 1;
			dmask = 1;
			for (int j = 0; j < nlen; j++, (bmask <<= 1), dmask = (dmask * 10LL) % m)
			{
				if (bmask & i) continue;
				if (j == nlen - 1 && digit[k] == 0) continue;
				int exm = digit[k] * dmask % m;
				for (int a = 0; a < m; a++)
				{
					dp[i | bmask][(a + exm) % m] += dp[i][a];
				}
			}
		}
	ll ans = dp[pmax - 1][0];
	sort(digit.begin(), digit.end());
	int fac = 1;
	for (int i = 1; i < nlen; i++)
	{
		if (digit[i] == digit[i - 1])
		{
			fac++;
			ans /= fac;
		}
		else
		{
			fac = 1;
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}