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
vector<pair<ll, ll> > Vu;
int main()
{
	int n, k, m, i, j;
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		if (!Vu.empty() && Vu.back().first == t)
		{
			Vu.back().second++;
			if (Vu.back().second == k) Vu.pop_back();
		}
		else Vu.push_back({ t, 1 });
	}
	ll s = 0;
	for (auto it : Vu)
	{
		s += it.second;
	}
	if (m == 1 || s == 0) return !printf("%lld\n", s);
	s *= m;
	int st = 0, en = (int)Vu.size() - 1;
	
}