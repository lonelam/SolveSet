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
int a[maxn];
int postsum[maxn];
int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
		}
		sort(a, a + n);
		postsum[n] = 0;
		for (int i = n-1; i >= 0; i--)
		{
			postsum[i] = postsum[i + 1] + a[i];
		}
		ll ans = 0;
		for (int i = 0; i < n-1; i++)
		{
			ans += postsum[i];
		}
		cout << ans << endl;
	}
}