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
const int maxn = 300000 + 100;
typedef long long ll;
typedef long double ld;
int a[maxn];
int n;
int b[maxn << 2];
int c[maxn << 2];
int dn;
void init(int arr[], int val[], int L = 0, int R = dn, int o = 1)
{
	if (L + 1 == R)
	{
		arr[o] = val[L];
		return;
	}
	const int mid = (L + R) / 2;
	init(arr, val, L, mid, o << 1);
	init(arr, val, mid, R, o << 1 | 1);
	arr[o] = max(arr[o << 1], arr[o << 1 | 1]);
}
int query(int arr[], int ql, int qr, int L = 0, int R = dn, int o = 1)
{
	if (ql <= L && R <= qr)
	{
		return arr[o];
	}
	const int mid = (L + R) / 2;
	int ret = 0;
	if (ql < mid)
		ret = query(arr, ql, qr, L, mid, o << 1);
	if (qr > mid)
		ret = max(ret, query(arr, ql, qr, mid, R, o << 1 | 1));
	return ret;
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
		}
		a[0] = a[n + 1] = inf;
		dn = n + 1;
		for (int i = 0; i < dn; i++)
		{
			b[i] = min(a[i], a[i + 1]);
		}
		init(c, b);
		init(b, a);
		for (int k = 0; k < n; k++)
		{
			const int len = n - k;
			const int lmargin = len / 2 ;
			const int rmargin = n - lmargin;
			int ans = 0;
			if (len == 1)
			{
				ans = query(b, 1, dn);
			}
			else if (len & 1)
			{
				ans = query(c, lmargin, rmargin + 1);
			}
			else
			{
				ans = query(b, lmargin, rmargin + 2);
			}
			printf("%d ", ans);
		}
		printf("\n");
	}
}