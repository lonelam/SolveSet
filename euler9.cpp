#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int T;
int n;
int main()
{
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      int ans = -1;
      for (int a = 1; a * 3 + 3 <= n; a++)
      {
        int up = (n * n - 2 * a * n);
        int down = 2 * (n - a);
        if (up % down == 0)
        {
          int b = up / down;
          int c = n - a - b;
          if (a < b && b < c)
          {
            ans = max(a * b *c, ans);
          }
        }
      }
      printf("%d\n", ans);

    }
  }
}
