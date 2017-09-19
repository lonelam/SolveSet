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
const int maxn = 200000 + 100;
typedef long long ll;
typedef long double ld;
int sum[maxn * 4];
int n;
void pushup(int x)
{
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
}
void update(int tar, int L = 0, int R = n, int o = 1)
{
	if (L + 1 == R)
	{
		sum[o] = 1;
		return;
	}
	const int mid = (L + R) / 2;
	if (tar < mid) update(tar, L, mid, o << 1);
	else update(tar, mid, R, o << 1 | 1);
	pushup(o);
}
int getsum(int ql, int qr, int L = 0, int R = n, int o = 1)
{
	if (ql == qr) 
		return 0;
	if (ql <= L && R <= qr)
	{
		return sum[o];
	}
	//if (L >= R) return 0;
	const int mid = (L + R) / 2;
	int ret = 0;
	if (ql < mid) ret += getsum(ql, qr, L, mid, o << 1);
	if (mid < qr) ret += getsum(ql, qr, mid, R, o << 1 | 1);
	return ret;
}
int a[maxn], b[maxn], c[maxn];
int ra[maxn], rb[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", a + i, b + i, c + i);
		a[i]--, b[i]--, c[i]--;
		ra[a[i]] = i;
		rb[b[i]] = i;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += (ll)getsum(b[ra[i]] + 1, n);
		update(b[ra[i]]);
		//update(c[ra[i]]);
	}
	memset(sum, 0, sizeof(sum));
	for (int i = n-1; i >= 0; i--)
	{
		ans += (ll)getsum(0, b[ra[i]]);
		update(b[ra[i]]);
		//update(c[ra[i]]);
	}
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < n; i++)
	{
		ans += (ll)getsum(c[ra[i]] + 1, n);
		update(c[ra[i]]);
		//update(c[ra[i]]);
	}
	memset(sum, 0, sizeof(sum));
	for (int i = n - 1; i >= 0; i--)
	{
		ans += (ll)getsum(0, c[ra[i]]);
		update(c[ra[i]]);
		//update(c[ra[i]]);
	}
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < n; i++)
	{
		ans += (ll)getsum(c[rb[i]] + 1, n);
		update(c[rb[i]]);
		//update(c[ra[i]]);
	}
	memset(sum, 0, sizeof(sum));
	for (int i = n - 1; i >= 0; i--)
	{
		ans += (ll)getsum(0, c[rb[i]]);
		update(c[rb[i]]);
		//update(c[ra[i]]);
	}
	
	printf("%lld\n", ans / 2);
}