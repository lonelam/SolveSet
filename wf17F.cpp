#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxd = 256;
ll k, d;
ll ps[256];
ll dp[257][257];
ll w[257][257];
ll calc(int from, int to)
{
  ll sum = 0;
  ll cnt = 0;
  for (int i = from; i < to; i++)
  {
    sum += ps[i] * i;
    cnt += ps[i];
  }
  ll p = round((ld)sum / cnt);
  sum = 0;
  for (int i = from; i< to; i++)
  {
    sum += (i - p) * (i - p) * ps[i];
  }
  return sum;
}
int main()
{
  memset(ps, 0, sizeof(ps));
  scanf("%lld%lld", &d, &k);
  int tmp;
  ll  val;
  for (int i = 0; i < d; i++)
  {
    scanf("%d%lld", &tmp, &val);
    ps[tmp] += val;
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i <= 256; i++)
  {
    for (int j = i; j <= 256; j++)
    {
      w[i][j] = calc(i, j);
    }
  }
  for (int i = 1; i <= k; i++)
  {
    for (int j = 0; j <= 256; j++)
    {
      for (int s = 0; s < j; s++)
      {
        dp[j][i] = min(dp[j][i], dp[s][i - 1] + w[s][j]);
      }
    }
  }
  printf("%lld\n", dp[256][k]);

}
/*
2 1
50 20000
150 10000

2 1
50 20000
150 10000
*/
