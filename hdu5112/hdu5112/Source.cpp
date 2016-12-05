#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#include<functional>
#include<utility>
using namespace std;
const int maxn = 100005;
struct record
{
	int t, x;
	bool operator<(const record & rhs) const
	{
		return t < rhs.t;
	}
};
record recs[maxn];
int main()
{
	int kase = 1;
	int t, n;
	while (scanf("%d",&t)!=EOF)
	{
		while (t--)
		{
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
			{
				cin >> recs[i].t >> recs[i].x;
			}
			double ans = 0;
			sort(recs, recs + n);
			for (int i = 1; i < n; i++)
			{
				ans = max(ans, (double)abs(recs[i].x - recs[i - 1].x) / (recs[i].t - recs[i - 1].t));
			}
			printf("Case #%d: %.2f\n", kase++, ans);
		}
	}
}