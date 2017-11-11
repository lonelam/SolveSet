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
const int maxn = 2000 + 100;
typedef long long ll;
typedef long double ld;
const ll moder = 998244353;

//从前到后
ll dp[maxn][maxn][2][11];

int T;
int n, a[maxn], b[maxn];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int tmp;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			a[i] = b[i] = 0;
			for (int j = 0; j < 9 && tmp; j++)
			{
				if (j & 1)
				{
					a[i] = (a[i] + (tmp % 10)) % 11;
				}
				else
				{
					a[i] = (a[i] - (tmp % 10) + 11) % 11;
				}
				tmp /= 10;
				b[i]++;
			}
		}
	}
}