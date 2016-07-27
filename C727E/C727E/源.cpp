#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int maxn = 100004;
typedef long long ll;
ll dp[maxn];
ll height[maxn];
int r[maxn];
int l[maxn];
int main()
{
	int n, tmp;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", height + i);
		}
		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			int left = i-1;
			ll cur = height[i];
			while (left >= 0 && height[left] >= cur)
			{
				left = min(left - 1, l[left]);
			}
			l[i] = left;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			int right = i+1;
			ll cur = height[i];
			while (right < n && height[right] >= cur)
			{
				right = max(right + 1, r[right]);
			}
			r[i] = right;
			ans = max((right - l[i] - 1)*cur, ans);
		}
		printf("%lld\n", ans);
	}
}