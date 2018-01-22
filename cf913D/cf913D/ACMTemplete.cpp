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
#include <functional>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
typedef long long ll;
typedef long double ld;
int n, T;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
piii p[maxn];
bool cmp(const piii & lhs,const piii & rhs)
{
	return lhs.first.second < rhs.first.second;
}
bool check(int k)
{
	if (k == 0) return true;
	sort(p, p + n);
	int b = 0;
	while (b < n && p[b].first.first < k)
	{
		b++;
	}
	if (n - b < k) return false;
	sort(p + b, p + n, cmp);
	ll sum = 0;
	for (int i = b; i < b + k; i++)
	{
		sum += p[i].first.second;
	}
	if (sum > T)
		return false;
	return true;
}
vector<int> gen(int k)
{
	if (k == 0) return {};
	int b = 0;
	sort(p, p + n);
	while (b < n && p[b].first.first < k)
	{
		b++;
	}
	sort(p + b, p + n, cmp);
	vector<int> ret;
	for (int i = b; i < b + k; i++)
	{
		ret.push_back(p[i].second);
	}
	return ret;
}
int main()
{
	while (~scanf("%d%d", &n, &T))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d",  &(p[i].first.first),&(p[i].first.second));
			p[i].second = i + 1;
		}
		sort(p, p + n);
		//int rem = T;
		int L = 0, R = n + 1;
		while (L + 1 < R)
		{
			const int mid = (L + R) / 2;
			if (check(mid))
			{
				L = mid;
			}
			else
			{
				R = mid;
			}
		}
		printf("%d\n", L);
		vector<int> ans = gen(L);
		printf("%u\n", ans.size());
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d%c", ans[i], (i == (ans.size() - 1)) ? '\n' : ' ');
		}
	}
}