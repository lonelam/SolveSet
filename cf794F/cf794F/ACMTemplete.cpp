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
struct node
{
	int digitcnt[11][10];
	int lazy[10];
	bool tag;
	node() {}
	void lazy_init()
	{
		for (int i = 0; i < 10; i++)
		{
			lazy[i] = i;
		}
		tag = false;
	}
	void init(ll x)
	{
		lazy_init();
		memset(digitcnt, 0, sizeof(digitcnt));
		int b = 0;
		while (x)
		{
			digitcnt[b++][x % 10] = 1;
			x /= 10;
		}
	}
	void trans(int from, int to)
	{
		if (from == to) return;
		for (int i = 0; i < 10; i++)
		{
			if (lazy[i] == from)
				lazy[i] = to;
		}
		for (int i = 0; i < 11; i++)
		{
			digitcnt[i][to] += digitcnt[i][from];
			digitcnt[i][from] = 0;
		}
		tag = true;
	}
	void pushup(const node &lhs, const node & rhs)
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				digitcnt[i][j] = lhs.digitcnt[i][j] + rhs.digitcnt[i][j];
			}
		}
	}
	void pushdown(node &lhs, node & rhs)
	{
		if (!tag) return;
		for (int k = 0; k < 10; k++)
		{
			if (lazy[k] != k)
			{
				for (int i = 0; i < 11; i++)
				{
					lhs.digitcnt[i][lazy[k]] += lhs.digitcnt[i][k];
					lhs.digitcnt[i][k] = 0;
					rhs.digitcnt[i][lazy[k]] += rhs.digitcnt[i][k];
					rhs.digitcnt[i][k] = 0;
				}
				for (int j = 0; j < 10; j++)
				{
					if (lhs.lazy[j] == k)
						lhs.lazy[j] = lazy[k];
					if (rhs.lazy[j] == k)
						rhs.lazy[j] = lazy[k];
				}
				lhs.tag = rhs.tag = true;
			}
		}
		lazy_init();
	}
	ll sumup()
	{
		ll dmask = 1, ans = 0;
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				ans += (ll)digitcnt[i][j] * (ll)j * dmask;
			}
			dmask *= 10;
		}
		return ans;
	}
} cnt[maxn * 8];
ll a[maxn];
int n, q;
void init(int L = 0, int R = n, int o = 1)
{
	if (L + 1 == R)
	{
		cnt[o].init(a[L]);
		return;
	}
	const int mid = (L + R) / 2;
	init(L, mid, o << 1);
	init(mid, R, o << 1 | 1);
	cnt[o].lazy_init();
	cnt[o].pushup(cnt[o << 1], cnt[o << 1 | 1]);
}
void trans(int ql, int qr, int from, int to, int L = 0, int R = n, int o = 1)
{
	if (ql <= L && R <= qr)
	{
		cnt[o].trans(from, to);
		return;
	}
	cnt[o].pushdown(cnt[o << 1], cnt[o << 1 | 1]);
	const int mid = (L + R) / 2;
	if (ql < mid) trans(ql, qr, from, to, L, mid, o << 1);
	if (mid < qr) trans(ql, qr, from, to, mid, R, o << 1 | 1);
	cnt[o].pushup(cnt[o << 1], cnt[o << 1 | 1]);
}
ll query(int ql, int qr, int L = 0, int R = n, int o = 1)
{
	if (ql <= L && R <= qr)
	{
		return cnt[o].sumup();
	}
	cnt[o].pushdown(cnt[o << 1], cnt[o << 1 | 1]);
	const int mid = (L + R) / 2;
	ll ret = 0;
	if (ql < mid) ret += query(ql, qr, L, mid, o << 1);
	if (mid < qr) ret += query(ql, qr, mid, R, o << 1 | 1);
	return ret;
}
int main()
{
	while (scanf("%d%d", &n, &q) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", a + i);
		}
		init();
		int cmd, l, r, x, y;
		for (int i = 0; i < q; i++)
		{
			scanf("%d", &cmd);
			if (cmd == 1)
			{
				scanf("%d%d%d%d", &l, &r, &x, &y);
				trans(l - 1, r, x, y);
			}
			else if (cmd == 2)
			{
				scanf("%d%d", &l, &r);
				ll ans = query(l - 1, r);
				printf("%lld\n", ans);
			}
			/*for (int j = 0; j < n; j++)
			{
				cout << query(j, j + 1) << " ";
			}
			cout << endl;*/
		}
	}
}
