#define _CRT_SECURE_NO_WARNINGS	
#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<functional>
#include<cmath>
#include<cstring>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 10005;
typedef long long ll;
ll a[maxn], b[maxn];
ll h[maxn];
int n, m, k;
ll bs(int low, int high)
{
	if (low >= high)
		return low;
	while (high - low > 1)
	{
		int mid = (high + low) / 2;
		for (int i = 0; i < n; i++)
		{
			h[i] = 10000000 * a[i] - mid * b[i];
		}
		sort(h, h + n);
		ll sum = 0;
		for (int i = k; i < n; i++)
		{
			sum += h[i];
		}
		if (sum > 0) low = mid;
		else high = mid;
		//else low = mid;
	}
	return low;
}
int main()
{
	while (scanf("%d%d", &n, &k) != EOF )
	{
		if (n == 0 && k == 0)
			return 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", a + i);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", b + i);
		}
		printf("%.0f\n", (double)bs(0, 10000000)/ 100000.0);

	}
	return 0;
}