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
map<int, set<int> > all;
int main()
{
	int n, m;
	int ai;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int ans = 2147483647;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &ai);
			auto ub = all[ai].upper_bound(i);
			if (ub != all[ai].end())
			{
				ans = min(ans, *ub - i);
			}
			all[ai].insert(i);
		}
		for (int i = 0; i < m; i++)
		{
			static int x, y;
			scanf("%d%d", &x, &y);
			if (all[x].size() > all[y].size())
			{
				swap(all[x], all[y]);
			}
			for (int o : all[x])
			{
				auto p = all[y].upper_bound(o);
				if (p != all[y].end())
				{
					ans = min(ans, *p - o);
				}
				if (p != all[y].begin())
				{
					p--;
					ans = min(o - *p, ans);
				}
				
				all[y].insert(o);
			}
			all.erase(x);
			printf("%d\n", ans);
		}
	}
}