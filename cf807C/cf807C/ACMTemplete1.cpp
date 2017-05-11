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

		ll x, y, p, q;
int main()
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%lld%lld%lld%lld", &x, &y, &p, &q);
			if (x * q == y * p)
			{
				printf("0\n");
				continue;
			}
			else if (p == q && x != y || p == 0 && x != 0)
			{
				printf("-1\n");
				continue;
			}
			ll L = (y + q - 1) / q ;
			ll R = y;
			while (L < R)
			{
				const ll mid = (L + R) / 2;
				ll up = mid * q - y;
				if (x > mid * p || x + up < mid * p)
				{
					L = mid + 1;
				}
				else
				{
					R = mid;
				}
			}
			printf("%lld\n", L * q - y);
		}
	}
}