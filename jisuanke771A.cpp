#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
ll mem[64][maxn];
ll n, p;
int digit[64];
ll calc(int i, int j, bool up)
{
  if (mem[i][j] != -1)
  {
    return mem[i][j];
  }
  if (i == 0)
  {
    return mem[i][j] = 1;
  }
  if (!up)
  {
    ll ans = 0;
    for (int k = 1; k < p; k++)
    {
      if (__gcd(k, j) == 1)
      {
        ans += calc(i - 1, k, false);
      }
    }
    return mem[i][j] = ans;
  }
  else
  {
    ll ans = __gcd(digit[i - 1], j) == 1 ? calc(i - 1, digit[i - 1], true) : 0;
    for (int k = 1; k < digit[i - 1]; k++)
    {
      if (__gcd(k, j) == 1)
      {
        ans += calc(i - 1, k, false);
      }
    }
    return ans;
  }
  /*  for (int k = 1; k < p; k++)
    {
      ans += calc(i - 1, k, false);
    }
    return ans;
  }
  */
}
int main()
{
  int T;
  ll L, R;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%Ld%Ld%Ld", &L, &R, &p);
      int dpos = 0;
      L--;
      while(L)
      {
        digit[dpos++] = L % p;
        L /= p;
      }
      memset(mem, -1, sizeof(mem));
      ll ans1 = dpos?calc(dpos - 1, digit[dpos - 1], true):0;//calc(dpos, 1, true);
      for (int k = 1; k < digit[dpos - 1]; k++)
      {
        ans1 += calc(dpos - 1, k, false);
      }
      if (dpos)dpos--;
      while(dpos--)
      {
        for (int k = 1; k < p; k++)
        {
          ans1 += calc(dpos, k, false);
        }
      }
      cout << ans1 << endl;
      dpos = 0;
      while(R)
      {
        digit[dpos++] = R % p;
        R/=p;
      }
      ll ans2 = dpos?calc(dpos - 1, digit[dpos - 1], true):0;//calc(dpos, 1, true);
      for (int k = 1; k < digit[dpos - 1]; k++)
      {
        ans2 += calc(dpos - 1, k, false);
      }
      if (dpos)dpos--;
      while(dpos--)
      {
        for (int k = 1; k < p; k++)
        {
          ans2 += calc(dpos, k, false);
        }
      }
      cout << ans2 << endl;
      //cout << ans2 << endl;
      printf("%Ld\n", ans2 - ans1);
    }
  }
}
