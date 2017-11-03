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
bool vis[maxn * 2];
struct node
{
	int color, num, start;
};
node st[maxn * 2];
int main()
{
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		a[i + n] = a[i];
	}
	deque<node> Q;
	for (int i = 0; i < n; i++)
	{
		if (!Q.empty() && Q.back().color == a[i])
		{
			if (++Q.back().num == k)
			{
				vis[Q.back().start] = true;
				st[Q.back().start] = Q.back();
				Q.pop_back();
			}
		}
		else
		{
			Q.push_back({ a[i], 1, i });
		}
	}
	if (m == 1)
	{
		int tot = 0;
		for (node v: Q)
		{
			tot += v.num;
		}
		printf("%d\n", tot);
		return 0;
	}
	bool flg = false;
	ll rem = LLONG_MAX;
	int L, R;
	for (int i = n; i < n * 2; i++)
	{
		if (vis[i - n])
		{
			Q.push_front(st[i - n]);
			--Q.front().num;
		}
		else
		{
			if (--Q.front().num == 0)
			{
				Q.pop_front();
			}
		}
		if (!Q.empty() && Q.back().color == a[i])
		{
			if (++Q.back().num == k)
			{
				vis[Q.back().start] = true;
				st[Q.back().start] = Q.back();
				Q.pop_back();
			}
		}
		else
		{
			Q.push_back({ a[i], 1, i });
		}

		if (Q.empty() || Q.size() == 1)
		{
			flg = true;
			L = i - n + 1;
			R = i + 1;
			break;
		}
		
		else
		{
			if (rem > Q.size())
			{
				rem = Q.size();
				L = i - n + 1;
				R = i + 1;
			}
		}
	}
	Q.clear();
	if (flg)
	{
		for (int i = L; i < R; i++)
		{
			if (!Q.empty() && Q.back().color == a[i])
			{
				if (++Q.back().num == k)
				{
					vis[Q.back().start] = true;
					st[Q.back().start] = Q.back();
					Q.pop_back();
				}
			}
			else
			{
				Q.push_back({ a[i], 1, i });
			}
		}
		int rr = Q[0].num, cc = Q[0].color;
		int ff = Q[0].num * (ll)(m-1) % (ll)k;
		Q.clear();
		for (int i = 0; i < L; i++)
		{
			if (!Q.empty() && Q.back().color == a[i])
			{
				if (++Q.back().num == k)
				{
					vis[Q.back().start] = true;
					st[Q.back().start] = Q.back();
					Q.pop_back();
				}
			}
			else
			{
				Q.push_back({ a[i], 1, i });
			}
		}
		if (!Q.empty() && Q.back().color == cc)
		{
			if ((Q.back().num += ff) >= k)
			{
				Q.back().num %= k;
				if (Q.back().num == 0) Q.pop_back();
			}
		}
		else
		{
			Q.push_back({ cc, ff, -1 });
		}
		for (int i = R; i < 2 * n; i++)
		{
			if (!Q.empty() && Q.back().color == a[i])
			{
				if (++Q.back().num == k)
				{
					Q.pop_back();
				}
			}
			else
			{
				Q.push_back({ a[i], 1, i });
			}
		}
		ll tot = 0;
		for (node v : Q)
		{
			tot += v.num;
		}
		printf("%I64d\n", tot);
		return 0;
	}
	flg = true;
	for (int i = L; i < R; i++)
	{
		if (!Q.empty() && Q.back().color == a[i])
		{
			if (++Q.back().num == k)
			{
				Q.pop_back();
			}
		}
		else
		{
			Q.push_back({ a[i], 1, i });
		}
	}
	ll seg = 0;
	for (node v : Q)
	{
		seg += v.num;
	}
	deque<node> sQ = Q;
	Q.clear();
	for (int i = 0; i < L; i++)
	{
		if (!Q.empty() && Q.back().color == a[i])
		{
			if (++Q.back().num == k)
			{
				Q.pop_back();
			}
		}
		else
		{
			Q.push_back({ a[i], 1, i });
		}
	}
	m--;
	while (flg && m > 0)
	{
		m--;
		flg = false;
		for (node v : sQ)
		{
			if (!Q.empty() && Q.back().color == v.color)
			{
				if ((Q.back().num += v.num) >= k)
				{
					flg = true;
					Q.back().num %= k;
					if (Q.back().num == 0)
					{
						Q.pop_back();
					}
				}
			}
			else
			{
				Q.push_back(v);
			}
		}
	}
	for (int i = R; i < 2 * n; i++)
	{
		if (!Q.empty() && Q.back().color == a[i])
		{
			if (++Q.back().num == k)
			{
				Q.pop_back();
			}
		}
		else
		{
			Q.push_back({ a[i], 1, i });
		}
	}
	ll tot = 0;
	for (node v : Q)
	{
		tot += v.num;
	}
	printf("%I64d\n", tot + ((ll)m* seg));
	return 0;
}