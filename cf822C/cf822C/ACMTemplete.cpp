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

const int inf = 0x7f3f3f3f;
const int maxn = 200000 + 100;
typedef long long ll;
typedef long double ld;
//int mini[maxn << 2];
int l[maxn], r[maxn], c[maxn];
map<int, vector<int> > discl;
map<int, vector<int> > discr, durmap;
map<int, bool> vis;
int rval[maxn];
int rseg[maxn * 4];
int lval[maxn];
int lseg[maxn * 4];
void build(int seg[], int val[], int L, int R, int o = 1)
{
	if (L + 1 == R)
	{
		seg[o] = val[L];
		return;
	}
	const int mid = (L + R) / 2;
	build(seg, val, L, mid, o << 1);
	build(seg, val, mid, R, o << 1 | 1);
	seg[o] = min(seg[o << 1], seg[o << 1 | 1]);
}
int query(int seg[], int ql, int qr, int L, int R, int o = 1)
{
	if (qr <= ql)
	{
		return inf;
	}
	if (ql <= L && R <= qr)
	{
		return seg[o];
	}
	const int mid = (L + R) / 2;
	int ret = inf;
	if (ql < mid) ret = query(seg, ql, qr, L, mid, o << 1);
	if (mid < qr) ret = min(ret, query(seg, ql, qr, mid, R, o << 1 | 1));
	return ret;
}
int n, x;
int main()
{
	while (scanf("%d%d", &n, &x) != EOF)
	{
		int ans = inf;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", l + i, r + i, c + i);
			const int dur = r[i] - l[i] + 1;
			discl[dur].push_back(l[i]);
			discr[dur].push_back(r[i]);
			durmap[dur].push_back(i);
		}
		vis.clear();
		for (auto duritem : durmap)
		{
			if (vis[duritem.first] == true)
			{
				continue;
			}
			const int tar = x - duritem.first;
			vis[tar] = vis[duritem.first] = true;
			int tmp = -inf;
			if (durmap.find(tar) == durmap.end()) continue;
			vector<int> & ldisc = discl[tar], &rdisc = discr[tar];
			sort(ldisc.begin(), ldisc.end());
			sort(rdisc.begin(), rdisc.end());
			ldisc.erase(unique(ldisc.begin(), ldisc.end()), ldisc.end());
			rdisc.erase(unique(rdisc.begin(), rdisc.end()), rdisc.end());
			int lnum = ldisc.size();
			int rnum = rdisc.size();
			for (int i = 0; i < lnum; i++)
			{
				lval[i] = inf;
			}
			for (int i = 0; i < rnum; i++)
			{
				rval[i] = inf;
			}
			for (auto & i : durmap[tar])
			{
				int lno = lower_bound(ldisc.begin(), ldisc.end(), l[i]) - ldisc.begin();
				lval[lno] = min(lval[lno], c[i]);
				int rno = lower_bound(rdisc.begin(), rdisc.end(), r[i]) - rdisc.begin();
				rval[rno] = min(rval[rno], c[i]);
			}
			build(lseg, lval, 0, lnum);
			build(rseg, rval, 0, rnum);
			for (int i : duritem.second)
			{
				int qleft = upper_bound(ldisc.begin(), ldisc.end(), r[i]) - ldisc.begin();
				int qright = lower_bound(rdisc.begin(), rdisc.end(), l[i]) - rdisc.begin();
				int tl = query(lseg, qleft, lnum, 0, lnum);
				int tr = query(rseg, 0, qright, 0, rnum);
				if (tl != inf)ans = min(ans, tl + c[i]);
				if (tr != inf) ans = min(ans, tr + c[i]);
			}
		}
		printf("%d\n", ans == inf ? -1 : ans);
	}
}