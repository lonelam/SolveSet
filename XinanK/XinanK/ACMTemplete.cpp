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
#include <numeric>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 100;
typedef long long ll;
typedef long double ld;
int cnt[maxn];
int a[maxn];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k, q;
		scanf("%d%d%d", &n, &k, &q);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
			cnt[a[i]]++;
		}
		int ans = 0;
		for (int i = 1; i <= 100; i++)
		{
			int sum = accumulate(cnt + i, cnt + i + k, 0);
			if (sum >= q)
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}