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
const int maxn = 1000 + 100;
typedef long long ll;
typedef long double ld;
int T, n;
double xl[maxn], yt[maxn], xr[maxn], yd[maxn];
double xdisc[maxn * 2];
struct q
{
	double xl, xr, y;
	int type;
	bool operator< (const q & rhs) const
	{
		return y < rhs.y;
	}
} qs[maxn * 2];
double sum2[maxn * 2 * 4];
double sum1[maxn * 2 * 4];
int cover[maxn * 2 * 4];
void init()
{
	memset(cover, 0, sizeof(cover));
	for (int i = 0; i < n; i++)
	{
		xdisc[i] = qs[i].xl = qs[i + n].xl = xl[i];
		xdisc[i + n] = qs[i].xr = qs[i + n].xr = xr[i];
		qs[i].y = yd[i];
		qs[i].type = -1;
		qs[i + n].y = yt[i];
		qs[i + n].type = 1;
	}
	sort(qs, qs + 2 * n);
	sort(xdisc, xdisc + 2 * n);
}
void pushup(int x, int l, int r)
{
	if (cover[x] >= 2)
	{
		sum2[x] = xdisc[r] - xdisc[l];
		sum1[x] = xdisc[r] - xdisc[l];
		return;
	}
	if (l + 1 == r)
	{
		sum2[x] = 0;
		if (cover[x] == 1) sum1[x] = xdisc[r] - xdisc[l];
		else sum1[x] = 0;
		return;
	}
	if (cover[x] == 1)
	{
		sum2[x] = sum1[x << 1] + sum1[x << 1 | 1];
		sum1[x] = xdisc[r] - xdisc[l];
	}
	else
	{
		sum1[x] = sum1[x << 1] + sum1[x << 1 | 1];
		sum2[x] = sum2[x << 1] + sum2[x << 1 | 1];
	}
}
void add(int ql, int qr, int a, int L = 0, int R = 2 * n, int x = 1)
{
	if (R <= ql || qr <= L)
	{
		return;
	}
	if (ql <= L && R <= qr)
	{
		cover[x] += a;
		pushup(x, L, R);
		return;
	}
	const int mid = L + (R - L) / 2;
	if (ql < mid) add(ql, qr, a, L, mid, x << 1);
	if (mid < qr) add(ql, qr, a, mid, R, x << 1 | 1);
	pushup(x, L, R);
}

int main()
{
    string path = "C:\\Users\\51433\\Desktop\\";
	int tfile = 5;
	for (int i = 0; i < tfile; i++)
	{
		freopen((path + char(i + '0') + ".in").c_str(), "r", stdin);
        freopen((path + char(i + '0') + ".out").c_str(), "w", stdout);

        while (scanf("%d", &T) != EOF)
        {
            while (T--)
            {
                scanf("%d", &n);
                for (int i = 0; i < n; i++)
                {
                    scanf("%lf%lf%lf%lf", xl + i, yt + i, xr + i, yd + i);
                }
                init();
                double pre = qs[0].y;
                double ans = 0;
                for (int i = 0; i < 2 * n; i++)
                {
                    ans += (qs[i].y - pre) * sum2[1];
                    add(lower_bound(xdisc, xdisc + 2 * n, qs[i].xl) - xdisc, lower_bound(xdisc, xdisc + 2 * n, qs[i].xr) - xdisc, qs[i].type);
                    pre = qs[i].y;
                }
                printf("%.2f\n", ans);
            }
        }

	}
}
