#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int t[maxn];
int c[maxn];
int T, C;
int n;
ld S;
ld eps = 1e-7;
ld dps = 1e-10;
bool check()
{
  ld rem = C;
  for (int i = 0; i < n; i++)
  {
    ld up = (t[i] - S) * (ld)c[i];
    ld down = S - T;
    if (abs(down) < eps)
    {
      if (T == t[i]) continue;
      else return false;
    }
    ld c2 = up / down;
    if (c2 < -dps) return false;
    rem -= c2;
    if (rem < -dps)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  scanf("%d", &n);
  {
    scanf("%d%d", &T, &C);
    bool larger = false, lesser = false;
    int mx = -1, mn = 10001;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", t + i, c + i);
      mx = max(t[i], mx);
      mn = min(t[i], mn);
      if (t[i] > T)
      {
        larger = true;
      }
      else if (t[i] < T)
      {
        lesser = true;
      }
    }
    if (larger && lesser)
    {
      printf("Impossible\n");
      return 0;
    }
    if (lesser)
    {
      ld L = mx, R = T;
      while((R - L) > eps)
      {
        const double mid = (L + R) / 2;
        S = mid;
        if (check())
        {
          L = mid;
        }
        else
        {
          R = mid;
        }
      }
      if (L == mx && !check())
      {
        printf("Impossible\n");
      }
      else
          printf("Possible\n%.4llf\n", S);
    }
    else if (larger)
    {
      S = mn;
      if (!check())
      {

        printf("Impossible\n");
      }
      else
          printf("Possible\n%.4llf\n", S);
    }
    else
    {
      S = T;
          printf("Possible\n%.4llf\n", S);
    }
  }
}
