#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int T;
int n, m;
int hp[maxn], g[maxn];
int rnk[maxn];
bool cmp(int lhs, int rhs)
{
  return (hp[lhs]+m-1) / m * g[rhs] <  (hp[rhs]+m-1) / m * g[lhs];
}
ll calc()
{
  sort(rnk,rnk + n, cmp);
  ll ans = 0;
  int t = 0;
  for (int i = 0; i < n; i++)
  {
    t += (hp[rnk[i]] + m - 1) / m;
    ans += (ll)t * g[rnk[i]];
  }
  return ans;
}
int main()
{
  while(scanf("%d", &T) != EOF)
  {
    int kase = 1;
    while(T--)
    {
      scanf("%d%d", &n, &m);
      for (int i = 0; i < n; i++)
      {
        rnk[i] = i;
        scanf("%d%d", hp + i, g + i);
      }
      printf("Case #%d: %lld\n", kase++, calc());
    }
  }
}
