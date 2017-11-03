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
int n, m, k;
struct bd
{
	int b, p;
	bool operator< (const bd & rhs) const
	{
		if (p != rhs.p) return p > rhs.p;
		return b < rhs.b;
	}
};
set<bd> r[maxn];
int tot[maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		r[i].insert({inf, tmp});
		while (scanf("%d", &tmp) && tmp != -1)
		{
			int pp;
			scanf("%d", &pp);
			r[i].insert({ tmp, pp });
			if (r[i].size() > 2)
			{
				r[i].erase(--r[i].end());
			}
		}
		if (r[i].size() == 1 || r[i].begin()->b == inf) continue;
		int hummer = min(r[i].begin()->p, int((++r[i].begin())->p * 1.1));
		tot[r[i].begin()->b] += hummer;
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		static int tmp;
		scanf("%d", &tmp);
		printf("%d\n", tot[tmp]);
	}

	
}