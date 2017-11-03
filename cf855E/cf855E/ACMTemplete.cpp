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
const int maxs = 1 << 11;
ll mem[11][maxs][11][64];
ll digit[64];
int n;

int dfs(int base, int st, int head, int cur, bool up)
{
	if (cur == -1)
	{
		return st == 0;
	}
	if (up)
	{
		int ans = 0;
		for (int i = 0; i < digit[cur]; i++)
		{
			ans += dfs(base, st ^ (1 << i), i, cur - 1, false);
		}
		ans += dfs(base, st ^ (1 << digit[cur]), digit[cur], cur - 1, true);
		return ans;
	}
	if (mem[base][st][head][cur] != -1)
	{
		return mem[base][st][head][cur];
	}
	int ans = 0;
	for (int i = 0; i < base; i++)
	{
		ans += dfs(base, st ^ (1 << i), i, cur - 1, false);
	}
	return mem[base][st][head][cur] = ans;
}
ll mem2[11][64];
ll solve(ll bound, ll base)
{
	if (bound == 0) return 0;
	int ret = 0;
	n = 0;
	while (bound)
	{
		digit[n++] = bound % base;
		bound /= base;
	}
	
	//reverse(digit, digit + n);
	for (int i = 1; i < digit[n-1]; i++)
	{
		ret += dfs(base, 1 << i, i, n-2, false);
	}
	ret += dfs(base, 1 << digit[n-1], digit[n-1], n-2, true);
	for (int i = 1; i < n; i++)
	{
		if (mem2[base][i] != -1)
		{
			ret += mem2[base][i];
		}
		else
		{
			mem2[base][i] = 0;
			for (int j = 1; j < base; j++)
			{
				mem2[base][i] += dfs(base, 1 << j, j, i - 2, false);
			}
			ret += mem2[base][i];
		}
	}
	//return ret;
	return ret;
}
int main()
{
	int q;
	memset(mem, -1, sizeof(mem));
	memset(mem2, -1, sizeof(mem2));
	scanf("%d", &q);
	while (q--)
	{
		ll b, l, r;
		scanf("%lld%lld%lld", &b, &l, &r);
		printf("%lld\n", solve(r, b) - solve(l - 1, b));
	}
}