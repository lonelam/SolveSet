#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int fact[100];
ll solve(int n, int L, int R)
{
  if (n == 1)
  {
    return 0;
  }
  ll m = fact[n - 1];
  ll Lb = (L + m - 1) / m * m;
  ll Rb = R / m * m;
  ll midcnt = (Rb - Lb) / m;
  ll ret = midcnt * solve(n - 1, 0, m) + midcnt * (Rb / m + Lb / m - 1) / 2 * fact[n - 1];
  ret += solve(n - 1, 0, R - Rb) + (R - Rb) * (Rb / m) + solve(n - 1, m - (Lb - L), m) + (Lb - L) * (Lb / m - 1);
  return ret;
}
void init()
{
  fact[0] = fact[1] = 1;
  for (int i = 2; i < 60; i++)
  {
    fact[i] = fact[i - 1] * i;
  }
}
int main()
{
  int T;
  int n, L, R;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d%d%d", &n, &L, &R);
      printf("%lld\n", solve(n, L - 1, R));
    }
  }
}
