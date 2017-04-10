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
const int maxn = 100 + 5;
typedef long long ll;
typedef long double ld;
int occupied[maxn * 4 * 2];
double sum[maxn * 4 * 2];
int n;
double xup[maxn], xdown[maxn], yleft[maxn], yright[maxn];
double xdisc[maxn * 2], ydisc[maxn * 2];

void init()
{
	for (int i = 0; i < n; i++)
	{
		xdisc[i] = xup[i];
		xdisc[i + n] = xdown[i];
		ydisc[i] = yleft[i];
		ydisc[i + n] = yright[i];
		
	}
	sort(xdisc, xdisc + 2 * n);
	sort(ydisc, ydisc + 2 * n);
	memset(occupied, 0, sizeof(occupied));
	memset(sum, 0, sizeof(sum));
}
void pushup(int x, int l, int r)
{
	if (occupied[x]) sum[x] = ydisc[r] - ydisc[l];
	else if (l + 1 == r) sum[x] = 0;
	else sum[x] = sum[x << 1] + sum[x << 1 | 1];
}

void add(int ql, int qr, int a, int L = 0, int R = 2 * n, int x = 1)
{
	if (R < ql || L > qr) return;
	if (ql <= L && R <= qr)
	{
		occupied[x] += a;
		pushup(x, L, R);
		return;
	}
	const int mid = L + (R - L) / 2;
	if (ql < mid) add(ql, qr, a, L, mid, x << 1);
	if (mid < qr) add(ql, qr, a, mid, R, x << 1 | 1);
	pushup(x, L, R);
}

struct q
{
	double yl, yr, x;
	int type;
	bool operator<(q & rhs)
	{
		return x < rhs.x;
	}
} qs[2 * maxn];
int main()
{
	//int n;
	int kase = 1;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf%lf", xup + i, yleft + i, xdown + i, yright + i);
			qs[i << 1].type = 1;
			qs[i << 1].x = xup[i];
			qs[i << 1].yl = yleft[i];
			qs[i << 1].yr = yright[i];
			qs[i << 1 | 1].type = -1;
			qs[i << 1 | 1].x = xdown[i];
			qs[i << 1 | 1].yl = yleft[i];
			qs[i << 1 | 1].yr = yright[i];
		}
		sort(qs, qs + 2 * n);
		init();
		ld ans = 0, pre = qs[0].x;
		for (int i = 0; i < 2 * n; i++)
		{
			ans += sum[1] * (qs[i].x - pre);
			add(lower_bound(ydisc, ydisc + 2 *n,qs[i].yl) - ydisc, lower_bound(ydisc, ydisc + 2 * n, qs[i].yr) - ydisc, qs[i].type);
			pre = qs[i].x;
		}

		printf("Test case #%d\nTotal explored area: %.2f\n\n", kase++, (double)ans);
	}
}