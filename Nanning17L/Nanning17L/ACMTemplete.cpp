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
ll s[maxn];
int w[maxn];
int dp[maxn << 2];
vector<ll> disc;
void pushup(int x)
{
	dp[x] = max(dp[x << 1], dp[x << 1 | 1]);
}
void update(int tar, int y, int L = 0, int R = disc.size(), int o = 1)
{
	if (L + 1 == R)
	{
		dp[o] = max(y, dp[o]);
		return;

	}
	const int mid = (L + R) / 2;
	if (tar < mid)
	{
		update(tar, y, L, mid, o << 1);
	}
	else
	{
		update(tar, y, mid, R, o << 1 | 1);
	}
	pushup(o);
}
int query(int ql, int qr, int L = 0, int R = disc.size(), int o = 1)
{
	if (ql <= L && R <= qr)
	{
		return dp[o];
	}
	const int mid = (L + R) / 2;
	int ret = 0;

	if (ql < mid) ret = query(ql, qr, L, mid, o << 1);
	if (mid < qr) ret = max(ret, query(ql, qr, mid, R, o << 1 | 1));
	return ret;
}
int main()
{
	int n = 0;
	while (~scanf("%lld", s + (n++)));
	//n++;
	for (int i = 0; i < n; i++)
	{
		if (s[i] < 0)
		{
			w[i] = 0;
		}
		else if (s[i] >= 10000)
		{
			s[i] -= 10000;
			w[i] = 5;
		}
		else
		{
			w[i] = 1;
		}
		disc.push_back(s[i]);
	}
	sort(disc.begin(), disc.end());
	disc.erase(unique(disc.begin(), disc.end()), disc.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		s[i] = lower_bound(disc.begin(), disc.end(), s[i]) - disc.begin();
		int pre = query(0, s[i] + 1);
		update(s[i], pre + w[i]);
		ans = max(ans, pre + w[i]);
	}
	printf("%d\n", ans);
}