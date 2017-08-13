#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 50;
const ll moder = 1e9 + 7;
ll f[maxn + 1][maxn + 1];
void init()
{
  f[0][0] = 1;
  for (int i = 1; i < maxn; i++)
  {
    f[i][0] = 1;
    for (int j = 0; j <= i; j++)
    {
      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % moder;
    }
  }
}
int main()
{
  init();
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      int n, m;
      scanf("%d%d", &n, &m);
      if (n < m) swap(n, m);
      printf("%lld\n", f[n][m]);
    }
  }
}
