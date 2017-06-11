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
const int maxn = 1 << 20;
typedef long long ll;
typedef long double ld;
int n, a[maxn], m;
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
		}
		m = a[0];
		sort(a, a + n);
		int ans = -1;
		for (int i = 0; n >> i; i++)
		{
			if (m < a[(n >> i) - 1])
			{
				ans--;
			}
			ans++;
		}
		printf("%d\n", ans);
	}
}