#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
const int moder  = 1e9 + 7;
int n, i, j, x, ans, po[maxn], a[maxn], f[maxn];
int main()
{
  scanf("%d", &n);
  for (po[0] = i = 1; i <= n; i++)
  {
    po[i] = 2 * po[i - 1] % moder;
  }
  while(n--)
  {
    scanf("%d", &x);
    a[x]++;
  }
  for (i = maxn - 1; i > 1; i--)
  {
    for (j = i, x = 0; j < maxn; j += i)
    {
      x += a[j];
    }
    if (x)
    {
      f[i] = 1LL * x * po[x - 1] % moder;
      for (int j = i + i; j < maxn; j+= i)
      {
        f[i] = (f[i] - f[j] + moder) % moder;
      }
      ans = (1LL * f[i] * i + ans) % moder;
    }
  }
  printf("%d\n", ans);
}
