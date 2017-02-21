#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 50000 + 100;
const int inf = 0x3f3f3f3f;

int a[maxn], b[maxn];
int c[maxn * 4];
int belong[maxn], bsize, bnum;
int n, q;
struct node
{
	int l, r, id;
	int ans;
	bool operator< (const node & rhs) const
	{
		if (belong[l] != belong[rhs.l]) return belong[l] < belong[rhs.l];
		return belong[r] < belong[rhs.r];
	}
} Qs[maxn];
bool recmp(const node & lhs, const node & rhs) 
{
	return lhs.id < rhs.id;
}

void build(int L = 1, int R = n, int rt = 1)
{
	return;
	if (L > R)
	{
		return;
	}
	c[rt] = 0;
	if (L == R)
	{
		return;
	}
	const int mid = (L + R) / 2;
	build(L, mid, rt << 1);
	build(mid + 1, R, rt << 1 | 1);

}
void add(int x, int val, int L = 1, int R = n, int rt = 1)
{
	if (L > R)
		return;
	if (L == R)
	{
		c[rt] += val;
		return;
	}
	c[rt] += val;
	const int mid = (L + R) / 2;
	if (x <= mid) add(x, val, L, mid, rt << 1);
	else add(x, val, mid + 1, R, rt << 1 | 1);
	//pushup
	//c[rt] = c[rt << 1] + c[rt << 1 | 1];
}


int query(int ql, int qr, int L = 1, int R = n, int rt = 1)
{
	if (L > R)
		return 0;
	const int mid = (L + R) / 2;
	if (ql <= L && R <= qr)
	{
		return c[rt];
	}
	if (L == R)
	{
		return 0;
	}
	int ret = 0;
	if (ql <= mid)
	{
		ret += query(ql, qr, L, mid, rt << 1);
	}
	if (qr > mid)
	{
		ret += query(ql, qr, mid + 1, R, rt << 1 | 1);
	}
	return ret;
}

void init()
{
	bsize = sqrt(n);
	bnum = n / bsize;
	if (n % bsize) bnum++;
	for (int i = 1; i <= n; i++)
	{
		belong[i] = (i - 1) / bsize;
	}
	memset(c, 0, sizeof(c));
	build();
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			b[i] = a[i];
		}
		sort(b + 1, b + n + 1);
		map <int, int> disc;
		for (int i = 1; i <= n; i++)
		{
			disc[b[i]] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			a[i] = disc[a[i]];
		}
		init();
		scanf("%d", &q);
		for (int i = 1; i <= q; i++)
		{
			scanf("%d%d", &Qs[i].l, &Qs[i].r);
			Qs[i].id = i;
		}
		sort(Qs + 1, Qs + q + 1);
		int ll = 1, rr = 0;
		int ans = 0;
		for (int i = 1; i <= q; i++)
		{
			while (rr < Qs[i].r)
			{
				rr++;
				//ins(rr);
				add(a[rr], 1);
				ans += query(a[rr] + 1, n);
			}
			while (rr > Qs[i].r)
			{
				//del(rr);
				add(a[rr], -1);
				ans -= query(a[rr] + 1, n);
				rr--;
			}
			while (ll < Qs[i].l)
			{
				//del(ll);
				add(a[ll], -1);
				ans -= query(1, a[ll] - 1);
				ll++;
			}
			while (ll > Qs[i].l)
			{
				ll--;
				//ins(ll);
				add(a[ll], +1);
				ans += query(1, a[ll] - 1);
			}
			Qs[i].ans = ans;
		}
		sort(Qs + 1, Qs + q + 1, recmp);

		for (int i = 1; i <= q; i++)
		{
			printf("%d\n", Qs[i].ans);
		}
	}
}
