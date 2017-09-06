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
struct node
{
	int l, r;
	bool operator<(const node & rhs) const
	{
		if (l != rhs.l) l < rhs.l;
		return r < rhs.r;
	}
}ns[maxn];
int up[maxn * 2];
int down[maxn * 2];
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> disc;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &ns[i].l, &ns[i].r);
		ns[i].r++;
		disc.push_back(ns[i].l);
		disc.push_back(ns[i].r);
	}
	sort(disc.begin(), disc.end());
	disc.erase(unique(disc.begin(), disc.end()), disc.end());
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		up[lower_bound(disc.begin(), disc.end(), ns[i].l) - disc.begin()]++;
		down[lower_bound(disc.begin(), disc.end(), ns[i].r) - disc.begin()]++;
	}
	int ans = 0;
	for (int i = 0; i < disc.size(); i++)
	{
		cnt -= down[i];
		ans = max(ans, cnt);
		cnt += up[i];
		ans = max(ans, cnt);
	}
	if (ans > 2)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
}