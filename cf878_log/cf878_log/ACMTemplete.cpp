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
int n, k, m;
int a[maxn * 2];
struct node
{
	int color, num;
};
void merge(deque<node> & lhs, deque<node> rhs)
{
	for (node v : rhs)
	{
		if (!lhs.empty() && lhs.back().color == v.color)
		{
			lhs.back().num = (lhs.back().num + v.num) % k;
			if (lhs.back().num == 0) lhs.pop_back();
		}
		else
		{
			lhs.push_back(v);
		}
	}
}
int main()
{
	scanf("%d%d%d", &n, &k, &m);
	deque<node> Q;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		if (!Q.empty() && Q.back().color == a[i])
		{
			if (++Q.back().num >= k)
			{
				Q.pop_back();
			}
		}
		else
		{
			Q.push_back({ a[i], 1 });
		}
	}
	deque<node> ans;
	int j = 0;
	while (m)
	{
		if (!ans.empty() && (ans.back().color != Q.front()).color || ans.back().num + Q.front().num < k) break;
		if (m & (1 << j))
		{
			merge(ans, Q);
		}
		m -= 1 << j;
		merge(Q, Q);
	}
	ll tot = 0;
	return 0;

}