#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n, m;
int ans[250 + 5][250 + 5];
int main()
{
  int xa, ya, xb, yb;
  while(scanf("%d%d", &n, &m) != EOF)
  {
    for (int k = 1; k <= n; k++)
    {
      scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
      int s = __gcd(abs(xa - xb), abs(ya - yb));
      int x, y;
      if (xb == xa)
      {
        x = 0;
        s = abs(yb - ya);
        y = (yb - ya) / s;
      }
      else if (yb == ya)
      {
        y = 0;
        s = abs(xb - xa);
        x = (xb - xa) / s;
      }
      else
      {
        x = (xb - xa) / s;
        y = (yb - ya) / s;
      }
      for (int i = 0; i <= s; i++)
      {
        int cx = xa + i * x;
        int cy = ya + i * y;
        ans[cx][cy] = k;
      }
    }
      int q;
      scanf("%d", &q);
      while(q--)
      {
        scanf("%d%d", &xa, &ya);
        printf("%d\n", ans[xa][ya]);
      }
  }
}
