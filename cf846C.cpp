#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 10;
//ans sum[0,K) - sum[K, i);
int K[maxn];
int a[maxn];
ll presum[maxn];
int n;
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++)
  {
    presum[i + 1] = presum[i] + a[i];
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++)
    {
      if (2LL * presum[j] - presum[i] > 2LL * presum[K[i]] - presum[i])
      {
        K[i] = j;
      }
    }
  ll ans = LLONG_MIN;
  int ti, tj, tk;
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (ans < (presum[K[j]]) - (presum[j] - presum[K[j]]) + (presum[i] - presum[j]) - (presum[n] - presum[i]))
      {
        ans = (presum[K[j]]) - (presum[j] - presum[K[j]]) + (presum[i] - presum[j]) - (presum[n] - presum[i]);
        ti = K[j];
        tj = j;
        tk = i;
      }
    }
  }
  printf("%d %d %d\n", ti, tj, tk);
}
